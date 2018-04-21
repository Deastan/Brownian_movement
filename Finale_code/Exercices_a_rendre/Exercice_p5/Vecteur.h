#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H

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
	Vecteur();
	Vecteur(double x, double y, double z);
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	// Comparateurs == et != :
	bool operator==(Vecteur const&) const;
	bool operator!=(Vecteur const& v) const;
	//Méthodes += et -= :
	Vecteur& operator+=(Vecteur const& v1);
	Vecteur& operator-=(Vecteur const& v1);
	// Multiplication par un scalaire :
	Vecteur& operator*=(double const& scalaire);	
	// Produit scalaire :
	double operator*(const Vecteur& v1);
	// Produit vectoriel :
	Vecteur& operator^=(Vecteur const& v1);// ATTENTION XOR a une plus grande priorité à cause du ou exclusif donc toujours mettre des parentaises entre !!!!!
	// Vecteur opposé :
	const Vecteur operator-(); 
	// Méthode afficher :
	std::ostream& afficher(std::ostream& sortie) const;//std est pour pas mettre le using namespace à toutes ma classe

};

/*================================================================================
 * Prototypes des fonctions
 *================================================================================*/
std::ostream& operator<<(std::ostream& sortie, Vecteur const& v1); //std est pour pas mettre le using namespace à toute ma classe
const Vecteur operator+(Vecteur v1, Vecteur const& v2);
const Vecteur operator-(Vecteur v1, Vecteur const& v2);
const Vecteur operator*(double scalaire, Vecteur v1);
const Vecteur operator*(Vecteur v1, double scalaire);
const Vecteur operator^(Vecteur v1, Vecteur const& v2);// ATTENTION XOR a une plus grande priorité à cause du ou exclusif donc toujours mettre des parentaises entre !!!!!

#endif // PRJ_VECTEUR_H
