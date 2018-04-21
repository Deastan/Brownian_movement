/**
 * \file Vecteur.cc
 * \brief est la définition de la classe qui nous pourmet de gérer la position et la vitesse de nos particules mais aussi de tous l'espace qui les entours.
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mars 2014
 */

#include "Vecteur.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
/*!
     *  Constructeur de la classe Vecteur sans arguments
     * 
     */
Vecteur::Vecteur()
	: x(0), y(0), z(0) {}

/*!
     *  Constructeur de la classe Vecteur avec trois arguements de type double
     *
     * \param x : première coordonnée x
     * \param y : deuxième coordonnée y 
     * \param z : troisième coordonnée z
     */
Vecteur::Vecteur(double x, double y, double z)
	: x(x), y(y), z(z) {}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
 /*!
     *  Methode qui permet de retourner les attributs privés du Vecteur
     *
     *  \return la coordonée en x
     */
double Vecteur::getX() const
{
	return x;
} 
 /*!
     *  Methode qui permet de retourner les attributs privés du Vecteur
     *
     *  \return la coordonée en y
     */
double Vecteur::getY() const
{
	return y;
}
 /*!
     *  Methode qui permet de retourner les attributs privés du Vecteur
     *
     *  \return la coordonée en z
     */
double Vecteur::getZ() const
{
	return z;
}

 /*!
     *  \param Vecteur const& v : permet de comparer au deuxième vecteur
     *  \return true s'il sont égale et false sinon
     */
bool Vecteur::operator==(Vecteur const& v) const
{
	if (x == v.x and y == v.y and z == v.z) 
	{ 
		return true; 
	}else 
	{ 
		return false; 
	}
}

 /*!
     *  \param Vecteur const& v : permet de comparer la différence au deuxième vecteur
     *  \return true si le vecteur est différents de v
     * sinon il retourne false
     */
bool Vecteur::operator!=(Vecteur const& v) const
{
	return not(*this == v);
}

 /*!
     * aditionne le vecteur appelant au vecteur v en paramètre et l'enregistre dans l'objet appelant
     * 
     *  \param Vecteur const& v : permet d'additionner le deuxième vecteur
     *  \return le vecteur appelant
     */
Vecteur& Vecteur::operator+=(Vecteur const& v1)
{
	x += v1.x;
	y += v1.y;
	z += v1.z;
	return *this;
}

 /*!
     * soustrait le vecteur appelant au vecteur v en paramètre et l'enregistre dans l'objet appelant
     * 
     *  \param Vecteur const& v : permet de soustraire le deuxième vecteur
     *  \return le vecteur appelant
     */
Vecteur& Vecteur::operator-=(Vecteur const& v1) 
{
	x -= v1.x;
	y -= v1.y;
	z -= v1.z;
	return *this;
}

 /*!
     *	fait l'opposer du vecteur appelant
     * 
     *  \return le vecteur appelant opposé
     */
const Vecteur Vecteur::operator-()
{
	return ((*this)*= (-1.));
}

 /*!
     *	permet de multiplier le vecteur à un nombre scalaire et de l'enregistrer dans le vecteur appelant
     * 
     * \param double const& scalaire : le nombre par lequel on va multiplier
     *  \return le vecteur appelant
     */
Vecteur& Vecteur::operator*=(double const& scalaire)
{
	x *= scalaire;
	y *= scalaire;
	z *= scalaire;
	return *this;
}	

 /*!
     *	permet de faire le produit vectoriel avec le vecteur en paramètre et l'enregistrer dans le vecteur appelant
     *	le calcul ce fait comme le produit vectoriel usuels
     * 
     * \param Vecteur const& v1 : permet de calculer le produit vectoriel avec le deuxième vecteur
     *  \return le vecteur appelant qui est le produit vectoriel des deux vecteurs
     */
Vecteur& Vecteur::operator^=(Vecteur const& v1)
{
	double x_(x), y_(y);
	x = (y * v1.z - z * v1.y);
	y = (z * v1.x - x_ * v1.z);
	z = (x_ * v1.y - y_ * v1.x);
	return *this;
}

 /*!
     *	fait le produit scalaire de deux vecteurs
     * 
     * \param Vecteur const& v1 : permet de calculer le produit scalaire
     *  \return un double (nombre réel) qui est le produit scalaire
     */
double Vecteur::operator*(const Vecteur& v1) const
{
	return (v1.x*x + v1.y*y + v1.z*z);
}

 /*!
     * \param ostream& sortie : permet de choisir le flot de sortie
     *  \return un ostream& pour pouvoir faire des "appels multiples"
     */
ostream& Vecteur::afficher(ostream& sortie) const
{
	return sortie << x << " " << y << " " << z;
}

/*================================================================================
 * Definition des fonctions 
 *================================================================================*/


 /*!
  * fonction qui permet de prendre un ostream& et va permettre de "multiplier"
  * l'affichage des vecteurs facillement en surchargeant l'opérateur <<
  * 
     * \param ostream& sortie : permet de choisir le flot de sortie
     * \param Vecteur const& v1 : le vecteur que l'on veut donner a ostream
     *  \return un ostream& pour pouvoir faire des "appels multiples"
     */
ostream& operator<<(ostream& sortie, Vecteur const& v1)
{
	return v1.afficher(sortie);
}

/* Les méthodes suivantes sont écrites sur 2 lignes pour éviter la copie
 * inutile faîtes par certain compilateurs 
 */

 /*!
     * \param Vecteur v1 : sert pour l'addition, on prends la copie pour ne pas changer le vecteur 1
     * \param Vecteur const& v2 : sert pour l'addition
     *  \return retourne le vecteur modifier
     */
const Vecteur operator+(Vecteur v1, Vecteur const& v2) 
{
	v1 += v2;
	return v1;
}

 /*!
     * \param Vecteur v1 : sert pour la soustraction, on prends la copie pour ne pas changer le vecteur 1
     * \param Vecteur const& v2 : sert pour la soustraction
     *  \return retourne le vecteur modifier
     */
const Vecteur operator-(Vecteur v1, Vecteur const& v2) 
{
	v1 -= v2;
	return v1;
}

 /*!
     *  \brief fonction qui surcharge l'opérateur *
     *
     * \param double scalaire : pour la multiplaction avant le vecteur
     * \param Vecteur v1 : sert pour la multiplaction par le scalaire
     *  \return retourne le vecteur modifier
     */
const Vecteur operator*(double scalaire, Vecteur v1)
{
	v1 *= scalaire;
	return v1;
}

 /*!
     * \param Vecteur v1 : sert pour la multiplaction par le scalaire
	 * \param double scalaire : pour la multiplaction avant le vecteur
     *  \return retourne le vecteur modifier
     */
const Vecteur operator*(Vecteur v1, double scalaire)
{
	v1 *= scalaire;
	return v1;
}

 /*!
     * pour le produit vectoriel de deux vecteurs
     *
     * \param Vecteur v1 : sert pour la multiplaction par le scalaire
     * \param Vecteur const& v2 : on ne modifie pas le vecteur mais on le veut comme référence
     *  \return retourne le vecteur modifier
     */
const Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
	v1 ^= v2;
	return v1;
}
