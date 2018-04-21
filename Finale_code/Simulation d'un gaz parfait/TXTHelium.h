/**
 * \file TXTHelium.h
 * \brief Prototype de la classe de la particule Helium en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

/** \class TXTHelium.h
 *  \brief Représente des atomes d'Helium (version texte)
 * 
 * \sa TestTXTHelium, TXTArgon, TXTNeon
 * 
 */

class TXTHelium : public Particule
{
	public :
	
	/// Constructeur
	TXTHelium(Vecteur position, Vecteur vitesse);
	
	/// Redéfinition de la méthode dessine (héritée de Dessinable)
	void dessine() const override;
};
