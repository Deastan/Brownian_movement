/**
 * \file Particule.h
 * \brief est le prototype de la particule qui est une classe mère des différentes particules 
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H

#include "Vecteur.h"
#include "Dessinable.h"
#include "Enceinte.h"
#include "GenerateurAleatoire.h"

class Particule : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/	
	protected :
	Vecteur position;
	Vecteur vitesse;
	double const masse;
	double const rayon;
	
/*================================================================================
 * Prototypes des constructeurs
 *================================================================================*/
	public :
	Particule();
	Particule(Vecteur position, Vecteur vitesse, double masse, double rayon);
	Particule(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature, double masse, double rayon);
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/	
	// virtual void dessine() const override;
	virtual void evolue(double dt); //methode permettant evoluer la particule dans le "temps"
	Vecteur getPosition() const;
	std::ostream& afficher(std::ostream& sortie) const;
	
	void gere_sorties(Enceinte enceinte); //gere les sorties de la particule de l'enceinte
	Vecteur pavageCubique(double espsilon) const; //cette méthode fait le cadrillage autour de la position de la particule
	void collision(Particule& p, GenerateurAleatoire& tirage, bool const& exerciceP9); ///effectue la collision de deux particules
	double get_rayon();

};

std::ostream& operator<<(std::ostream& sortie, Particule const& p);

#endif // PRJ_PARTICULE_H
