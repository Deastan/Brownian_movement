#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H

#include <memory>
#include <vector>

#include "Particule.h"
#include "Enceinte.h"

class Systeme : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	protected :
	vector<unique_ptr<Particule>> collectionParticules;
	Enceinte enceinte;
	/// besoin de rajouter un attribut pour le P12
	double const temperature; /// const si l'on considère que le systeme est a une pression et un volume constant
	GenerateurAleatoire tirage;
	
/*================================================================================
 * Prototypes des constructeurs et du destructeur
 *================================================================================*/	
	public :
	Systeme();
	Systeme(double largeur, double longueur, double hauteur, double temperature = 298); /// en Kelvin si besoin de faire des calculs de pression par la suite
	~Systeme();//destructeur
	
	private :
	Systeme(Systeme const& autre) = delete; //suppression du constructeur de copie
	
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	public :
	void ajouterParticule(Particule* particule);
	void dessine() const override;
	void evolue(double dt, bool const& exerciceP9 = false);

	private :
	bool supprimerParticules();
	Systeme& operator=(Systeme aCopier) = delete; //suppression de l'operateur = pour un systemme
	vector<size_t> determine_collisions_possibles(double epsilon, unique_ptr<Particule> const& p1);
	size_t choisi_collision(vector<size_t> collisions_possibles);
	void initialise(unsigned int nbr_argon, unsigned int nbr_fluor, unsigned int nbr_helium, unsigned int nbr_neon);
	void initialise();
};

#endif // PRJ_SYSTEME_H
