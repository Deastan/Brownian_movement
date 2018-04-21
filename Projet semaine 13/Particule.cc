#include "Particule.h"
#include <cmath>

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/

Particule::Particule()
	: position(Vecteur(0,0,0)), vitesse(Vecteur(0,0,0)), masse(0), rayon(0) {}

Particule::Particule(Vecteur position, Vecteur vitesse, double masse, double rayon)
	: position(position), vitesse(vitesse), masse(masse), rayon(rayon) {}

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

Vecteur Particule::getPosition() const
{
	return position;
}

ostream& Particule::afficher(ostream& sortie) const
{
	return sortie << "pos : " << position << " ; v : " << vitesse
	              << " ; m : " << masse;
}

void Particule::evolue(double dt)
{
	position += vitesse * dt;
}

void Particule::gere_sorties(Enceinte enceinte)
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


Vecteur Particule::pavageCubique(double epsilon) const
{
	Vecteur vecteur(floor(position.getX()*(1/epsilon)), floor(position.getY()*(1/epsilon)), floor(position.getZ()*(1/epsilon)));
	
	return vecteur;
}

void Particule::collision(Particule& p, GenerateurAleatoire& tirage, bool const& exerciceP9)
{
	/*cout << "Collision de particules entre :" << endl
	     << *this << endl
	     << p << endl; */
	
	Vecteur vg (masse/(masse + p.masse) * vitesse + p.masse/(masse + p.masse) * p.vitesse);
	
	double L (sqrt((vitesse-vg) * (vitesse-vg))); ///racine carrée du produit scalaire d'un vecteur avec lui-même = norme de ce vecteur
	
	double z;
	double phi;
	
	if (exerciceP9 == true)
	{
		z = 0;
		phi = M_PI / 3;
	} else
	{
		z = tirage.uniforme_reel(-L, L);
		phi = tirage.uniforme_reel(0, 2 * M_PI);
	}
	
	
	///Utile juste pour l'exercice 9
	
	double r (sqrt(L * L - z * z));
	
	Vecteur v0 (r * cos(phi), r * sin(phi), z);
	
	vitesse = vg + v0;
	p.vitesse = vg - (masse/p.masse) * v0;
}

double Particule::get_rayon()
{
	return rayon;
}

/*================================================================================
 * Definition des fonctions
 *================================================================================*/

ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficher(sortie);
}

