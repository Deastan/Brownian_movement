#include "Particule.h"

/* Definition des constructeurs : */

Particule::Particule()
	: position(Vecteur(0,0,0)), vitesse(Vecteur(0,0,0)), masse(0) {}

Particule::Particule(Vecteur position, Vecteur vitesse, double masse)
	: position(position), vitesse(vitesse), masse(masse) {}

/* Methodes utiles : */

Vecteur Particule::getPosition()
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

void Particule::gere_sortie(Enceinte enceinte)
{
	if (position.getX() < 0) { 
		Vecteur nouvellepos (-position.getX(), position.getY(), position.getZ());
		position = nouvellepos;
		Vecteur nouvellevit (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
		vitesse = nouvellevit;
	} else {
		if (position.getX() > enceinte.getLargeur()) { 
			Vecteur nouvellepos (enceinte.getLargeur() - (position.getX() - enceinte.getLargeur()), position.getY(), position.getZ());
			position = nouvellepos;
			Vecteur nouvellevit (-vitesse.getX(), vitesse.getY(), vitesse.getZ());
			vitesse = nouvellevit;
		}
	}
	
	if (p.getPosition().getY() < 0) { 
		Vecteur nouvellepos (position.getX(), -position.getY(), position.getZ());
		position = nouvellepos;
		Vecteur nouvellevit (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
		vitesse = nouvellevit;
	} else {
		if (p.getPosition().getY() > enceinte.getLongueur()) { 
			Vecteur nouvellepos (position.getX(), enceinte.getLongueur() - (position.getY() - enceinte.getLongueur()), position.getZ());
			position = nouvellepos;
			Vecteur nouvellevit (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
			vitesse = nouvellevit;
		}
	}
	
	if (p.getPosition().getZ() < 0) { 
		Vecteur nouvellepos (position.getX(), position.getY(), -position.getZ());
		position = nouvellepos;
		Vecteur nouvellevit (vitesse.getX(), vitesse.getY(), -vitesse.getZ());
		vitesse = nouvellevit;
	} else {
		if (p.getPosition().getZ() > enceinte.getHauteur()) { 
			Vecteur nouvellepos (position.getX(), position.getY(), enceinte.getHauteur() - (position.getZ() - enceinte.getHauteur()));
			position = nouvellepos;
			Vecteur nouvellevit (vitesse.getX(), -vitesse.getY(), vitesse.getZ());
			vitesse = nouvellevit;
		}
	}
}

/* Fonctions utiles : */

ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficher(sortie);
}

