#include "Particule.h"

class TXTNeon : public Particule
{
	private :
	TXTNeon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
