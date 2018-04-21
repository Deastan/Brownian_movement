#include "Particule.h"

class TXTHelium : public Particule
{
	public :
	
	TXTHelium(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
