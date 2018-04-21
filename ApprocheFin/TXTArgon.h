/**
 * \file TXTArgon.h
 * \brief est le protype de la classe de la particule Néon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

class TXTArgon : public Particule
{
	public :
	
	TXTArgon(Vecteur position, Vecteur vitesse);
	
	void dessine() const override;
};
