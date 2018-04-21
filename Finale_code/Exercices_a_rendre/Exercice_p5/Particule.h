#include "Vecteur.h"

class Particule
{
	private :
	
	Vecteur position;
	Vecteur vitesse;
	double masse;
	
	public :
	
	Particule();
	Particule(Vecteur position, Vecteur vitesse, double masse);
	
	std::ostream& afficher(std::ostream& sortie);
		
};

std::ostream& operator<<(std::ostream& sortie, Particule p);
