/**
 * \file GLArgon.h
 * \brief est le prototype de la classe de la particule Néon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

class TXTNeon : public Particule
{
	public :
	
	TXTNeon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
