/**
 * \file Vecteur.h
 * \brief est le prototype de la classe qui nous pourmet de gérer la position et 
 * la vitesse de nos particules mais aussi de tous l'espace qui les entours.
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mars 2014
 */

#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H

#include <iostream>


/*! \class Vecteur
   * \brief Prototype de la classe Vecteur
   *
   * Cette classe est celle qui permet de créer un vecteur, de gérer 
   * le calcul vectoriel de notre programme.
   * 
   */
class Vecteur
{
	private :
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	double x;
	double y;
	double z;
	
	public:
/*================================================================================
 * Prototyopes des constructeurs
 *================================================================================*/
	///Constructeur sans arguments
	Vecteur();
	/// Constructeur avec arguments qui prends les coordonnées du vecteurs
	Vecteur(double x, double y, double z);
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	/// Prototype du getters de la première coordonnée 
	double getX() const;
	/// Prototype du getters de la deuxième coordonnée 
	double getY() const;
	/// Prototype du getters de la deuxième coordonnée 
	double getZ() const;
	/// Prototype comparateurs ==
	bool operator==(Vecteur const&) const;
	/// Prototype comparateurs != 
	bool operator!=(Vecteur const& v) const;
	/// Prototype méthodes +=  
	Vecteur& operator+=(Vecteur const& v1);
	/// Prototype méthodes -= 
	Vecteur& operator-=(Vecteur const& v1);
	/// Prototype multiplication par un scalaire 
	Vecteur& operator*=(double const& scalaire);	
	/// Prototype produit scalaire 
	double operator*(const Vecteur& v1) const;
	/// Prototype produit vectoriel 
	Vecteur& operator^=(Vecteur const& v1);// ATTENTION XOR a une plus grande priorité à cause du ou exclusif donc toujours mettre des parentaises entre !!!!!
	/// Prototype vecteur opposé 
	const Vecteur operator-(); 
	/// Prototype méthode afficher 
	std::ostream& afficher(std::ostream& sortie) const;

};

/*================================================================================
 * Prototypes des fonctions
 *================================================================================*/
/// Prototype fonction << 
std::ostream& operator<<(std::ostream& sortie, Vecteur const& v1);
/// Prototype fonction + entre deux vecteurs 
const Vecteur operator+(Vecteur v1, Vecteur const& v2);
/// Prototype fonction - soustraction entre deux vecteurs
const Vecteur operator-(Vecteur v1, Vecteur const& v2);
/// Prototype fonction multiplication par un scalire avant
const Vecteur operator*(double scalaire, Vecteur v1);
/// Prototype fonction multiplication par un scalire arrière
const Vecteur operator*(Vecteur v1, double scalaire);
/// Prototype fonction ^ prduit vectoriel
const Vecteur operator^(Vecteur v1, Vecteur const& v2);// ATTENTION XOR a une plus grande priorité à cause du ou exclusif donc toujours mettre des parentaises entre !!!!!

#endif // PRJ_VECTEUR_H
