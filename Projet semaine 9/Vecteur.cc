#include "Vecteur.h"

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/

Vecteur::Vecteur()
	: x(0), y(0), z(0) {}

Vecteur::Vecteur(double x, double y, double z)
	: x(x), y(y), z(z) {}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
double Vecteur::getX() const
{
	return x;
} 
double Vecteur::getY() const
{
	return y;
}
double Vecteur::getZ() const
{
	return z;
}

bool Vecteur::operator==(Vecteur const& v) const
{
	if (x == v.x and y == v.y and z == v.z) { return true; }
	else { return false; }
}

bool Vecteur::operator!=(Vecteur const& v) const
{
	return not(*this == v);
}

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
	double x_(x), y_(y);
	x = (y * v1.z - z * v1.y);
	y = (z * v1.x - x_ * v1.z);
	z = (x_ * v1.y - y_ * v1.x);
	return *this;
}

double Vecteur::operator*(const Vecteur& v1)
{
	return (v1.x*x + v1.y*y + v1.z*z);
}

ostream& Vecteur::afficher(ostream& sortie) const
{
	return sortie << "(" << x << ", " << y << ", " << z  << ")";
}

/*================================================================================
 * Definition des fonctions 
 *================================================================================*/

ostream& operator<<(ostream& sortie, Vecteur const& v1)
{
	return v1.afficher(sortie);
}

/* Les méthodes suivantes sont écrites sur 2 lignes pour éviter la copie
 * inutile faîtes par certain compilateurs */

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
	v1 *= scalaire;
	return v1;
}

const Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
	v1 ^= v2;
	return v1;
}
