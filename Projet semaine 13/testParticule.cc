#include <iostream>
#include "Particule.h"

using namespace std;

int main() {
	
	Particule p0;
	Particule p1(Vecteur(1, 1, 1), Vecteur(0, 0, 0), 4.002602);
	Particule p2(Vecteur(1, 18.5, 1), Vecteur(0, 0.2, 0), 20.1797);
	Particule p3(Vecteur(1, 1, 3.1), Vecteur(0, 0, -0.5), 39.948);
	Particule p4(p2);
	
	cout << "particule 0 : " << p0 << endl
	     << "particule 1 : " << p1 << endl
	     << "particule 2 : " << p2 << endl
	     << "particule 3 : " << p3 << endl
	     << "particule 4 : " << p4 << endl;
	
}
