#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H


#include "Vecteur.h"
#include "Dessinable.h"
#include "Enceinte.h"

class Particule : public Dessinable
{
	protected :
	
	Vecteur position;
	Vecteur vitesse;
	double const masse;
	
	public :
	
	Particule();
	Particule(Vecteur position, Vecteur vitesse, double masse);
	
	// Utile pour savoir si une particule est sortie de l'enceinte
	Vecteur getPosition();
	
	ostream& afficher(ostream& sortie) const;
	
	void evolue(double dt);
	void gere_sortie(Enceinte enceinte);
};

ostream& operator<<(ostream& sortie, Particule const & p);

#endif // PRJ_PARTICULE_H
