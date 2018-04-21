#include <iostream>
#include "Vecteur.h"

using namespace std;


int main()
{
	Vecteur v1(2,2,2);
	Vecteur v2(1,1,1);
	Vecteur v3;
	
	cout << (v1+v2) << (v1-v2) << (v2 * 4) << endl;
	
	cout << "Fin du programme !!" << endl;
	
	return 0;
}
//std est pour pas mettre le using namespace à toutes ma classe//std est pour pas mettre le using //std est pour pas mettre le using namespace à toutes ma classe//std est pour pas mettre le using namespace à toutes ma classe
