/**
 * \file Enceinte.h
 * \brief est la classe qui contient l'objet enceinte qui est la boîte où seront nos particules
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_ENCEINTE_H
#define PRJ_ENCEINTE_H

#include "Dessinable.h"

/*! \class Enceinte
   * \brief Prototype de la classe Enceinte
   *
   * Cette classe est celle qui permet de créer une enceinte, de la dessiner
   * 
   */
class Enceinte : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	double largeur;
	double longueur;
	double hauteur;	
	
	public:
/*================================================================================
 * Prototype du constructeur
 *================================================================================*/
	/// Constructeur sans paramètre
	Enceinte();
		/// Constructeur sans paramètre
	Enceinte(bool reglage);
		/// Constructeur avec paramètres largeur, longueur et hauteur de l'enceinte
	Enceinte(double largeur, double longueur, double hauteur);
	
/*================================================================================
 * Prototype des méthodes
 *================================================================================*/
 	/// Prototype du getters de la largeur de l'enceinte
	double getLargeur() const;
 	/// Prototype du getters de la longueur de l'enceinte
	double getLongueur() const;
 	/// Prototype du getters de la hauteur de l'enceinte
	double getHauteur() const;
	 /// Prototype de la méthode qui écrit dans le terminal la largeur hauteur et longueur de l'enceinte
	void display() const;
 	/// Prototype de la méthode dessine en OpenGL
	virtual void dessine() const;
};

#endif // PRJ_ENCEINTE_H
