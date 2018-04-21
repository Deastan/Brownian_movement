/**
 * \file TXTNeon.cc
 * \brief est la définition de la classe de la particule néon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTNeon.h"

#include <iostream>

using namespace std;

TXTNeon::TXTNeon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 20.1797) {}

void TXTNeon::dessine() const
{
	cout << "particule TXTNe : " << *this << endl;
}
