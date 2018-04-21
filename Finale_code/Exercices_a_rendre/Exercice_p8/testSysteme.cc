#include "Systeme.h"
#include "TXTArgon.h"
#include "TXTNeon.h"
#include "TXTHelium.h"


int main()
{
	Systeme systeme(100,100,100);
	
	systeme.ajouterParticule(new TXTHelium(Vecteur(0, 0, 0), Vecteur(0, 0, 0)));
	systeme.ajouterParticule(new TXTNeon(Vecteur(1, 18.5, 1), Vecteur(0, 0.2, 0)));
	systeme.ajouterParticule(new TXTArgon(Vecteur(1, 1, 3.1), Vecteur(0, 0, -0.5)));
	
	systeme.dessine();

	
	return 0;
}
