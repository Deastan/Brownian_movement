/**
 * \file TXTHelium.cc
 * \brief est la définition de la classe de la particule hélium en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTHelium.h"

TXTHelium::TXTHelium(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 4.002602) {}

void TXTHelium::dessine() const
{
	cout << "particule TXHe : " << *this << endl;
}
