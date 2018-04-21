#include <iostream>
#include "Systeme.h"
#include "TXTHelium.h"
#include "TXTNeon.h"
#include "TXTArgon.h"

int main() {
	
	Systeme john;
	john.ajouterParticule(new TXTHelium(Vecteur(1,1,1), Vecteur(0,0,0)));
	john.ajouterParticule(new TXTNeon(Vecteur(1,18.5,1), Vecteur(0,0.2, 0)));
	john.ajouterParticule(new TXTArgon(Vecteur(1,1,3.1), Vecteur(0,0,-0.5)));
	
	cout << "Le système est constitué des trois particules suivantes :" << endl;
	
	john.dessine();
	
	cout << "Lancement de la simulation :" << endl
	     << "==========----------" << endl;
	
	for (int i(1) ; i <= 10 ; ++i)
	{
		john.evolue(1);
		john.dessine();
		cout << "==========----------" << endl;
	}
	
}
