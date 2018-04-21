/**
 * \file TXTArgon.cc
 * \brief est la définition de la classe de la particule Néon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTArgon.h"

TXTArgon::TXTArgon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 39.948) {}

void TXTArgon::dessine() const
{
	cout << "particule TXTAr : " << *this << endl;
}
