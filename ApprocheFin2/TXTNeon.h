/**
 * \file GLArgon.h
 * \brief Prototype de la classe de la particule Neon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

/** \class TXTNeon.h
 *  \brief Représente des atomes de Neon (version texte)
 * 
 * \sa TestTXTNeon, TXTArgon, TXTHelium
 * 
 */

class TXTNeon : public Particule
{
	public :
	
	/// Constructeur
	TXTNeon(Vecteur position, Vecteur vitesse);
	
	/// Redéfinition de la méthode dessine (héritée de Dessinable)
	void dessine() const override;
};
