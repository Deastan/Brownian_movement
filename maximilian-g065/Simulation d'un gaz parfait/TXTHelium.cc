/**
 * \file TXTHelium.cc
 * \brief Définition de la classe de la particule Helium en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTHelium.h"

/** Contructeur prenant deux paramètres de type Vecteur
 * 
 * \param position Vecteur correspondant à la position de la particule
 * \param vitesse Vecteur correspondant à la vitesse de la particule
 */

TXTHelium::TXTHelium(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 4.002602) {}

/** Methode permettant de dessiner la version texte d'une particule d'Helium */

void TXTHelium::dessine() const
{
	std::cout << "particule TXHe : " << *this << endl;
}
