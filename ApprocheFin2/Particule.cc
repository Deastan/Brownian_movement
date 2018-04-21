/**
 * \file Particule.cc
 * \brief Définition de la classe mère Particule
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"
#include <cmath>

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
/** Initialise tous les paramètres de type vecteur comme des vecteurs nuls et ceux de type double à 0 */
Particule::Particule()
	: position(Vecteur(0,0,0)), vitesse(Vecteur(0,0,0)), masse(0), rayon(0) {}

/** Permet d'initialiser une particule en fournissant une position, une vitesse, une masse et un rayon
 *  \param position Vecteur indiquant la position de la particule
 *  \param vitesse Vecteur indiquant la vitesse de la particule
 *  \param masse Nombre réel indiquant la masse de la particule
 *  \param rayon Nombre réel indiquant le rayon de la particule
  */
Particule::Particule(Vecteur position, Vecteur vitesse, double masse, double rayon)
	: position(position), vitesse(vitesse), masse(masse), rayon(rayon) {}

/** Permet d'initialiser aléatoirement la position et la vitesse de la particule sur une enceinte
 *  \param enceinte Enceinte dans laquelle doit se trouver la particule
  */
Particule::Particule(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature, double masse, double rayon)
	: position(Vecteur(tirage.uniforme_reel(0, enceinte.getLargeur()),
	                   tirage.uniforme_reel(0, enceinte.getLongueur()),
	                   tirage.uniforme_reel(0, enceinte.getHauteur()))), 
	  masse(masse), rayon(rayon)
{
	double ecart_type (sqrt(8314.472 * temperature / masse));
	vitesse = Vecteur(tirage.gaussienne(0, ecart_type),
	                  tirage.gaussienne(0, ecart_type),
	                  tirage.gaussienne(0, ecart_type));
}	                  

/*================================================================================
 * Definition des méthodes
 *================================================================================*/

/** \param sortie ostream sur lequel l'affichage s'effectue
 *  \return ostream sur lequel l'affichage a été fait */
ostream& Particule::afficher(ostream& sortie) const
{
	return sortie << "pos : " << position << " ; v : " << vitesse
	              << " ; m : " << masse;
}

/** \param  dt Pas de temps */
void Particule::evolue(double dt)
{
	position += vitesse * dt;
}

/** Détermine si la particule sort ou non de l'enceinte.
 *  Si elle sort effectivement (c'est à dire le BORD de la particule est sorti
 *  de l'enceinte), on change les Vecteurs  position et vitesse en conséquence
 *  \param enceinte Enceinte dans laquelle la particule se trouve et doit rester */
void Particule::gere_sorties(Enceinte const& enceinte)
{
    // Par rapport a X
    while (position.getX() - rayon < 0 or position.getX() + rayon > enceinte.getLargeur()) {
        if (position.getX() - rayon < 0)
        {
            position = Vecteur (-(position.getX() - rayon) + rayon, position.getY(), position.getZ());
            vitesse = Vecteur (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
            // Rebond sur la face 1
        } else
        {
            position = Vecteur (enceinte.getLargeur() - (position.getX() + rayon - enceinte.getLargeur()) - rayon, position.getY(), position.getZ());
            vitesse = Vecteur (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
            // Rebond sur la face 2
        }
    }
 
    // Par rapport a Y
    while (position.getY() - rayon < 0 or position.getY() + rayon > enceinte.getLongueur()) {
        if (position.getY() - rayon < 0)
        {
            position = Vecteur (position.getX(), -(position.getY() - rayon) + rayon, position.getZ());
            vitesse = Vecteur (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
            // Rebond sur la face 3
        } else
        {
            position = Vecteur (position.getX(), enceinte.getLongueur() - (position.getY() + rayon - enceinte.getLongueur()) - rayon, position.getZ());
            vitesse = Vecteur (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
            // Rebond sur la face 4
        }
    }
    
    // Par rapport a Z
    while (position.getZ() - rayon < 0 or position.getZ() + rayon > enceinte.getHauteur()) {
        if (position.getZ() - rayon < 0)
        {
            position = Vecteur (position.getX(), position.getY(), -(position.getZ() - rayon) + rayon);
            vitesse = Vecteur (vitesse.getX(), vitesse.getY(), -vitesse.getZ());
            // Rebond sur la face 5
        } else
        {
            position = Vecteur (position.getX(), position.getY(), enceinte.getHauteur() - (position.getZ() + rayon - enceinte.getHauteur()) - rayon);
            vitesse = Vecteur (vitesse.getX(), vitesse.getY(), -vitesse.getZ());
            // Rebond sur la face 6
        }
    }
}

/** \param epsilon Pas d'espace
 *  \return Retourne un vecteur qui représente le pavage cubique autour de la particule
 *          (et peut-être comparé avec le vecteur de pavage d'une autre particule) */
Vecteur Particule::pavageCubique(double epsilon) const
{ return Vecteur (floor(position.getX()*(1/epsilon)),
                  floor(position.getY()*(1/epsilon)),
                  floor(position.getZ()*(1/epsilon))); }

/** \param p Particule avec laquelle *this entre en collision
 *  \param tirage GenerateurAleatoire permettant d'effectuer différents tirages de nombres dans la méthode
 */
void Particule::collision(Particule& p, GenerateurAleatoire& tirage)
{
	Vecteur vg (masse/(masse + p.masse) * vitesse + p.masse/(masse + p.masse) * p.vitesse);
	
	double L (sqrt((vitesse-vg) * (vitesse-vg))); // racine carrée du produit scalaire d'un vecteur avec lui-même = norme de ce vecteur
	
	double z(tirage.uniforme_reel(-L, L));
	double phi(tirage.uniforme_reel(0, 2 * M_PI));
	
	double r (sqrt(L * L - z * z));
	Vecteur v0 (r * cos(phi), r * sin(phi), z);
	
	vitesse = vg + v0;
	p.vitesse = vg - (masse/p.masse) * v0;
}

/** Utile pour déterminer le pas d'espace epsilon du systeme
 * \return Retourne le rayon de la particule */
double Particule::get_rayon()
{ return rayon; }

/*================================================================================
 * Definition des fonctions
 *================================================================================*/

/** \param p Particule à afficher
 *  \param sortie ostream sur lequel on doit afficher p
 *  \return ostream modifié par l'affichage de p */
ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficher(sortie);
}

