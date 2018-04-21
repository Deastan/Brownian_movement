/**
 * \file TXTHelium.h
 * \brief est le prototype de la classe de la particule Helium en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

class TXTHelium : public Particule
{
	public :
	
	TXTHelium(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
