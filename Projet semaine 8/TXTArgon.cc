#include "TXTArgon.h"

TXTArgon::TXTArgon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 39.948) {}
 
void TXTArgon::dessine() const
{
	cout << "particule TXTAr : " << *this << endl;
}
