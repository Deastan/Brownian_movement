#include "Systeme.h"
#include "TXTArgon.h"
#include "TXTNeon.h"

int main()
{
	cout << "Debut" << endl;
	Systeme jonathan;
	Systeme emma(300.,300.,200.);
	
	emma.ajouterParticule(new TXTArgon(Vecteur(0, 1, 4), Vecteur(1, 5, 0.5)));
	emma.ajouterParticule(new TXTNeon(Vecteur(0, 2, 3), Vecteur(-1, 5, 0.1)));
	
	emma.dessine();
	

	
	cout << "Fin" << endl;
	
	return 0;
}
