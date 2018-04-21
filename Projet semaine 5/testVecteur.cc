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
	
	vect1 += vect2;
	cout << vect1 << endl;
	vect1 -= vect2;
	cout << vect1 << endl;
	cout << vect1 + vect2 << endl << vect1 - vect2 << endl;
	cout << 3 * vect1 << endl << vect1 * 4 << endl;
	vect1 *= 2;
	cout << vect1 << endl;
	cout << (vect1 ^ vect4) << endl;
	vect1 *= .5;
	cout << vect1 << endl;
	vect1 ^= vect2;
	cout << vect1 << endl;
	cout << vect3 * vect2 << endl;
	
	return 0;
}
//std est pour pas mettre le using namespace à toutes ma classe//std est pour pas mettre le using //std est pour pas mettre le using namespace à toutes ma classe//std est pour pas mettre le using namespace à toutes ma classe
