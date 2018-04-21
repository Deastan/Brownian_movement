#include <iostream>
#include "Enceinte.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
Enceinte::Enceinte()
:largeur(20), longueur(20), hauteur(20)
{}

Enceinte::Enceinte(double largeur, double longueur, double hauteur)
:largeur(largeur), longueur(longueur), hauteur(hauteur) 
{}

/*================================================================================
 * Definition des méthodes
 *================================================================================*/
double Enceinte::getLargeur() const
{
	return largeur;
}
double Enceinte::getLongueur() const
{
	return longueur;
}
double Enceinte::getHauteur() const
{
	return hauteur;
}
	
void Enceinte::display() const
{
	cout << largeur << ", " << longueur << ", " << hauteur << endl;
}
