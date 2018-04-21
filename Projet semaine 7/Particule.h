#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H


#include "Vecteur.h"
#include "Dessinable.h"

class Particule : public Dessinable
{
	private :
	
	Vecteur position;
	Vecteur vitesse;
	double masse;
	
	public :
	
	Particule();
	Particule(Vecteur position, Vecteur vitesse, double masse);
	
	ostream& afficher(ostream& sortie) const;
		
};

ostream& operator<<(ostream& sortie, Particule const & p);

#endif // PRJ_PARTICULE_H
