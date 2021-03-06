#include "Particule.h"
#include <cmath>

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/

Particule::Particule()
	: position(Vecteur(0,0,0)), vitesse(Vecteur(0,0,0)), masse(0) {}

Particule::Particule(Vecteur position, Vecteur vitesse, double masse)
	: position(position), vitesse(vitesse), masse(masse) {}

/*================================================================================
 * Definition des méthodes
 *================================================================================*/

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
	//Par rapport a X
	
	while (position.getX() < 0 or position.getX() > enceinte.getLargeur()) {
		if (position.getX() < 0) 
		{ 
			position = Vecteur (-position.getX(), position.getY(), position.getZ());
			vitesse = Vecteur (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
			cout << "Rebond sur la face 1" << endl;
		} else 
		{
			position = Vecteur (enceinte.getLargeur() - (position.getX() - enceinte.getLargeur()), position.getY(), position.getZ());
			vitesse = Vecteur (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
			cout << "Rebond sur la face 2" << endl;
		}
	}

	//Par rapport a Y
	
	while (position.getY() < 0 or position.getY() > enceinte.getLongueur()) {
		if (position.getY() < 0)
		{ 
			position = Vecteur (position.getX(), -position.getY(), position.getZ());
			vitesse = Vecteur (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
			cout << "Rebond sur la face 3" << endl;
		} else 
		{
			position = Vecteur (position.getX(), enceinte.getLongueur() - (position.getY() - enceinte.getLongueur()), position.getZ());
			vitesse = Vecteur (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
			cout << "Rebond sur la face 4" << endl;
		}
	}
	//Par rapport a Z
	
	while (position.getZ() < 0 or position.getZ() > enceinte.getHauteur()) {
		if (position.getZ() < 0) 
		{ 
			position = Vecteur (position.getX(), position.getY(), -position.getZ());
			vitesse = Vecteur (vitesse.getX(), vitesse.getY(), -vitesse.getZ());
			cout << "Rebond sur la face 5" << endl;
		} else 
		{
			position = Vecteur (position.getX(), position.getY(), enceinte.getHauteur() - (position.getZ() - enceinte.getHauteur()));
			vitesse = Vecteur (vitesse.getX(), vitesse.getY(), -vitesse.getZ());
			cout << "Rebond sur la face 6" << endl;
		}
	}
}


Vecteur Particule::pavageCubique(double epsilon) const
{
	Vecteur vecteur(floor(position.getX()*(1/epsilon)), floor(position.getY()*(1/epsilon)), floor(position.getZ()*(1/epsilon)));
	
	return vecteur;
}

void Particule::collision(Particule& p, GenerateurAleatoire& tirage)
{
	cout << "Collision de particules entre :" << endl
	     << *this << endl
	     << p << endl;
	
	Vecteur vg (masse/(masse + p.masse) * vitesse + p.masse/(masse + p.masse) * p.vitesse);
	
	double L (sqrt((vitesse-vg) * (vitesse-vg))); ///racine carrée du produit scalaire d'un vecteur avec lui-même = norme de ce vecteur
	//double z (tirage.uniforme(-L, L));
	//double phi (tirage.uniforme(0, 2 * M_PI));
	
	double z (0);
	double phi (M_PI / 3);
	///Utile juste pour l'exercice 9
	
	double r (sqrt(L * L - z * z));
	
	Vecteur v0 (r * cos(phi), r * sin(phi), z);
	
	vitesse = vg + v0;
	p.vitesse = vg - (masse/p.masse) * v0;
}


/*================================================================================
 * Definition des fonctions
 *================================================================================*/

ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficher(sortie);
}

