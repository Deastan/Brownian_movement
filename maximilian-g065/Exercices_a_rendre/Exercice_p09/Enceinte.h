#ifndef PRJ_ENCEINTE_H
#define PRJ_ENCEINTE_H

class Enceinte
{
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
	
};

#endif // PRJ_ENCEINTE_H
