#include "TXTHelium.h"

TXTHelium::TXTHelium(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 4.002602) {}

void TXTHelium::dessine() const
{
	cout << "particule TXHe : " << *this << endl;
}
