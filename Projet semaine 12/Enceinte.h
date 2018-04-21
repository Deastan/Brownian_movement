#ifndef PRJ_ENCEINTE_H
#define PRJ_ENCEINTE_H

#include "Dessinable.h"

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
	Enceinte();
	Enceinte(double largeur, double longueur, double hauteur);
	
/*================================================================================
 * Prototype des méthodes
 *================================================================================*/
	double getLargeur() const;
	double getLongueur() const;
	double getHauteur() const;
	void display() const;
	virtual void dessine() const;

};

#endif // PRJ_ENCEINTE_H
