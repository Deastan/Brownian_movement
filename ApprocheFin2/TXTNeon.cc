/**
 * \file TXTNeon.cc
 * \brief Définition de la classe de la particule Neon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "TXTNeon.h"

/** Constructeur prenant deux paramètres de type Vecteur
 * 
 * \param position Vecteur correspondant à la position de la particule
 * \param vitesse Vecteur correspondant à la vitesse de la particule
 */

TXTNeon::TXTNeon(Vecteur position, Vecteur vitesse)
 : Particule(position, vitesse, 20.1797) {}

/** Methode permettant de dessiner la version texte d'une particule de Neon */

void TXTNeon::dessine() const
{
	std::cout << "particule TXTNe : " << *this << endl;
}
