#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H

class Vecteur
{
/*================================================================================
* Definition des attributs
*================================================================================*/
	private:
	double x;
	double y;
	double z;
	
	public:
/*================================================================================
 * Prototyopes des constructeurs
 *================================================================================*/
	Vecteur(double xx = 0., double yy = 0., double zz = 0.);
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	Vecteur& operator+=(Vecteur const& v1);
	Vecteur& operator-=(Vecteur const& v1);
	//multiplication par un scalaire
	Vecteur& operator*=(double const& scalaire);	
	//produit scalaire
	double operator*(const Vecteur& v1);
	//produit vectorielle
	Vecteur& operator^=(Vecteur const& v1);// ATTENTION XOR a une plus grande priorité à cause du ou excusif donc toujours mettre des parentaises entre !!!!!
	//vecteur opposé
	const Vecteur operator-(); 
	//methode afficher
	std::ostream& afficher(std::ostream& sortie) const;//std est pour pas mettre le using namespace à toutes ma classe
	
	//METHODE POUR COMPARR DEUX VECTEURS AMUSE TOI BIEN
};

/*================================================================================
 * Prototypes des fonctions
 *================================================================================*/
std::ostream& operator<<(std::ostream& sortie, Vecteur const& v1); //std est pour pas mettre le using namespace à toutes ma classe
const Vecteur operator+(Vecteur v1, Vecteur const& v2);
const Vecteur operator-(Vecteur v1, Vecteur const& v2);
const Vecteur operator*(double scalaire, Vecteur v1);
const Vecteur operator*(Vecteur v1, double scalaire);
const Vecteur operator^(Vecteur v1, Vecteur const& v2);// ATTENTION XOR a une plus grande priorité à cause du ou excusif donc toujours mettre des parentaises entre !!!!!

#endif // PRJ_VECTEUR_H
