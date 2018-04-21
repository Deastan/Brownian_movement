#include "TXTNeon.h"

#include <iostream>

using namespace std;

TXTNeon::TXTNeon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 20.1797) {}

void TXTNeon::dessine() const
{
	cout << "particule TXTNe : " << *this << endl;
}
