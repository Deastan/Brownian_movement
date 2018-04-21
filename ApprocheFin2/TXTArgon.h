/**
 * \file TXTArgon.h
 * \brief Prototype de la classe de la particule Argon en version texte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Particule.h"

/** \class TXTArgon.h
 *  \brief Représente des atomes d'Argon (version texte)
 * 
 * \sa TestTXTArgon, TXTHelium, TXTNeon
 * 
 */

//???? est-ce possible ?

class TXTArgon : public Particule
{
	public :
	
	/// Constructeur
	TXTArgon(Vecteur position, Vecteur vitesse);
	
	/// Redéfinition de la méthode dessine (héritée de Dessinable)
	void dessine() const override;
};
