#include <iostream>
#include "Vecteur.h"

using namespace std;


int main()
{
	// un vecteur en 3D :
	Vecteur vect1(1.0, 2.0, -0.1);

	// d'autres vecteurs en 3D
	Vecteur vect2(2.6, -3.5, 4.4);
	Vecteur vect3(vect1);  // copie de V1
	Vecteur vect4;         // le vecteur nul

	cout << "Vecteur 1 : " << vect1 << endl;
	cout << "Vecteur 2 : " << vect2 << endl;
	cout << "Vecteur 4 : " << vect4 << endl;

	cout << "Le vecteur 1 est ";
	if (vect1 == vect2) {
		cout << "égal au";
	} else {
		cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (vect1 != vect3) {
		cout << "différent du";
	} else {
		cout << "égal au";
	}
	cout << " vecteur 3." << endl;
	
	// test += et -= :
	vect1 += vect2;
	cout << "vecteur 1 += vecteur 2 : " << vect1 << endl;
	vect1 -= vect2;
	cout << "vecteur 1 -= vecteur 2 :" << vect1 << endl;
	// le vecteur 1 doit avoir repris sa valeur initiale
	
	// test + et - :
	cout << "vecteur 1 + vecteur 2 = " << vect1 + vect2 << endl
	     << "vecteur 1 - vecteur 2 = " << vect1 - vect2 << endl;
	     
	// test multiplication par un scalaire :
	cout << "3 * (vecteur 1) = " << 3 * vect1 << endl
	     << "(vecteur 1) * 3 = " << vect1 * 3 << endl;
	
	// test *= :
	vect1 *= 2;
	cout << "vecteur 1 *= 2 : " << vect1 << endl;
	vect1 *= 0.5;
	cout << "vecteur 1 *= 0.5 : " << vect1 << endl;
	   // le vecteur 1 doit avoir repris sa valeur initiale
	
	// test produit vectoriel :
	cout << "Produit vectoriel :" << endl
	     << "vecteur 1 ^ vecteur 4 = " << (vect1 ^ vect4) << endl;
	vect1 ^= vect2;
	cout << "vecteur 1 ^= vecteur 2 : " << vect1 << endl;
	     
	// test produit scalaire :
	cout << "Produit scalaire :" << endl
	     << "vecteur 3 * vecteur 2 = " << vect3 * vect2 << endl;
	
	return 0;
}
