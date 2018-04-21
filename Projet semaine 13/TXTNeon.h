#include "Particule.h"

class TXTNeon : public Particule
{
	public :
	
	TXTNeon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
