#include "Systeme.h"
#include "TXTArgon.h"
#include "TXTNeon.h"

int main()
{
	cout << "Debut" << endl;
	
	Systeme emma;
	
	emma.ajouterParticule(new TXTArgon(Vecteur(5, 10, 10), Vecteur(1, 0, 0)));
	emma.ajouterParticule(new TXTNeon(Vecteur(15, 10, 10), Vecteur(2.3, 0, 0)));
	
	emma.dessine();
	for(int i;i<10.;++i)
	{
		emma.evolue(1);
		emma.dessine();
	}

	
	cout << "Fin" << endl;
	
	return 0;
}
