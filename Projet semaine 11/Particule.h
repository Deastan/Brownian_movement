#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H

#include <math.h>

#include "Vecteur.h"
#include "Dessinable.h"
#include "Enceinte.h"
#include "GenerateurAleatoire.h"

class Particule : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/	
	protected :
	Vecteur position;
	Vecteur vitesse;
	double const masse;
	double const rayon;
	
/*================================================================================
 * Prototypes des constructeurs
 *================================================================================*/
	public :
	Particule();
	Particule(Vecteur position, Vecteur vitesse, double masse, double rayon);
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/	
	// virtual void dessine() const override;
	
	ostream& afficher(ostream& sortie) const;
	void evolue(double dt); //methode permettant evoluer la particule dans le "temps"
	void gere_sorties(Enceinte enceinte); //gere les sorties de la particule de l'enceinte
	Vecteur pavageCubique(double espsilon) const; //cette méthode fait le cadrillage autour de la position de la particule
	void collision(Particule& p, GenerateurAleatoire& tirage, bool const& exerciceP9); ///effectue la collision de deux particules
	
	Vecteur getPosition() const
	{
		return position;
	}
};

ostream& operator<<(ostream& sortie, Particule const& p);

#endif // PRJ_PARTICULE_H
