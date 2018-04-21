#ifndef PRJ_ENCEINTE_H
#define PRJ_ENCEINTE_H

class Enceinte
{
	private:
	double hauteur;
	double largeur;
	double profondeur;
	
	public:
/*================================================================================
 * Prototype du constructeur
 *================================================================================*/
	Enceinte();
	Enceinte(double hauteur, double largeur, double profondeur);
/*================================================================================
 * Prototype des méthodes
 *================================================================================*/
	void display() const;
	
};

#endif // PRJ_ENCEINTE_H
