#include <iostream>
#include "Vecteur.h"

using namespace std;

/*================================================================================
 * Definition du constructeur
 *================================================================================*/
Vecteur::Vecteur(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
Vecteur& Vecteur::operator+=(Vecteur const& v1)
{
	x += v1.x;
	y += v1.y;
	z += v1.z;
	return *this;
}

Vecteur& Vecteur::operator-=(Vecteur const& v1) 
{
	x -= v1.x;
	y -= v1.y;
	z -= v1.z;
	return *this;
}

const Vecteur Vecteur::operator-()
{
	return ((*this)*= (-1.));
}

Vecteur& Vecteur::operator*=(double const& scalaire)
{
	x *= scalaire;
	y *= scalaire;
	z *= scalaire;
	return *this;
}	

Vecteur& Vecteur::operator^=(Vecteur const& v1)
{
	x = (y * v1.z - z * v1.y);
	y = (z * v1.x - x * v1.z);
	z = (x * v1.y - y * v1.x);
	return *this;
}

double Vecteur::operator*(const Vecteur& v1)
{
	return (v1.x*x + v1.y*y + v1.z*z);
}

ostream& Vecteur::afficher(ostream& sortie) const
{
	return sortie << "( " << x << " " << y << " " << z  << " )";
}

/*================================================================================
 * Definition des fonctions 
 *================================================================================*/
ostream& operator<<(ostream& sortie, Vecteur const& v1)
{
	v1.afficher(sortie);
	return sortie;
}

const Vecteur operator+(Vecteur v1, Vecteur const& v2) 
{	
	v1 += v2;
	return v1;
}

const Vecteur operator-(Vecteur v1, Vecteur const& v2) 
{	
	v1 -= v2;
	return v1;
}

const Vecteur operator*(double scalaire, Vecteur v1)
{
	v1 *= scalaire;
	return v1;
}

const Vecteur operator*(Vecteur v1, double scalaire)
{
	return v1 *= scalaire;
}

const Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
	v1 ^= v2;
	return v1; 
}
