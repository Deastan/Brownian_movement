/**
 * \file TXTArgon.cc
 * \brief Définition de la classe de la particule Argon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTArgon.h"

/** Contructeur prenant deux paramètres de type Vecteur
 * 
 * \param position Vecteur correspondant à la position de la particule
 * \param vitesse Vecteur correspondant à la vitesse de la particule
 */

TXTArgon::TXTArgon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 39.948) {}

/** Methode permettant de dessiner la version texte d'une particule d'Argon */

void TXTArgon::dessine() const
{
	std::cout << "particule TXTAr : " << *this << endl;
}
