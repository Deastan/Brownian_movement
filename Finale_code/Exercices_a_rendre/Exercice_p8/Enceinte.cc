#include <iostream>
#include "Enceinte.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
	Enceinte::Enceinte()
	:hauteur(20), largeur(20), profondeur(20)
	{}

	Enceinte::Enceinte(double hauteur, double largeur, double profondeur)
	:hauteur(hauteur), largeur(largeur), profondeur(profondeur) 
	{}
/*================================================================================
 * Definition des méthodes
 *================================================================================*/
	void Enceinte::display() const
	{
		cout << hauteur << ", " << largeur << ", " << profondeur << endl;
	}
