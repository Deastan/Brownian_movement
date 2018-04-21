#include "Particule.h"

/* Définition des constructeurs : */

Particule::Particule()
	: position(Vecteur(0,0,0)), vitesse(Vecteur(0,0,0)), masse(0) {}

Particule::Particule(Vecteur position, Vecteur vitesse, double masse)
	: position(position), vitesse(vitesse), masse(masse) {}

/* Méthodes utiles : */

ostream& Particule::afficher(ostream& sortie) const
{
	return sortie << "pos : " << position << " ; v : " << vitesse
	              << " ; m : " << masse;
}

/* Fonctions utiles : */

ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficher(sortie);
}

