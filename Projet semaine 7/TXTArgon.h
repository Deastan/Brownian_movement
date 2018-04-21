#include "Particule.h"

class TXTArgon : public Particule
{
	private:
	TXTArgon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
