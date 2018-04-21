#include "Systeme.h"
#include "TXTArgon.h"
#include "TXTNeon.h"
#include "TXTHelium.h"

int main()
{
	cout << "Debut" << endl;
	
	Systeme emma (3,3,3);
	
	emma.ajouterParticule(new TXTArgon(Vecteur(1, 1, 1), Vecteur(1, 1, 1)));
	emma.ajouterParticule(new TXTNeon(Vecteur(1, 0, 0), Vecteur(5, 0, 0)));
	
	emma.dessine();
	for(int i;i<10.;++i)
	{
		emma.evolue(1);
		emma.dessine();
	}

	
	cout << "Fin" << endl;
	
	return 0;
}
