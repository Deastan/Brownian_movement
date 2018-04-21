#include "Particule.h"

class TXTArgon : public Particule
{
	public :
	
	TXTArgon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
