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
	std::vector<std::unique_ptr<Particule>> collectionParticules;
	Enceinte enceinte;
	double const temperature; /// const si l'on considère que le systeme est a une pression et un volume constant
	double epsilon; /// conceptuellement, il faudrait que epsilon (pas d'espace) soit de type const, mais la valeur de epsilon ne peut être calculée qu'après le remplissage du tableau collectionParticules, ce qui posait problème
	GenerateurAleatoire tirage;
	
/*================================================================================
 * Prototypes des constructeurs et du destructeur
 *================================================================================*/	
	public :
	Systeme();
	Systeme(double largeur, double longueur, double hauteur, double temperature); /// j'ai enlevé la valeur par défaut parce que conceptuellement c'est mieux, on initialise rien (hasard total) ou tout (determination totale)
	~Systeme();//destructeur
	
	private :
	Systeme(Systeme const& autre) = delete; //suppression du constructeur de copie
	
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	public :
	void ajouterArgon(unsigned int nbr_argon, bool canon = false);
	void ajouterFluor(unsigned int nbr_fluor, bool canon = false);
	void ajouterHelium(unsigned int nbr_helium, bool canon = false);
	void ajouterNeon(unsigned int nbr_neon, bool canon = false);
	void dessine() const override;
	void evolue(double dt, bool const& exerciceP9 = false);

	private :
	void ajouterParticule(Particule* particule);
	bool supprimerParticules();
	Systeme& operator=(Systeme aCopier) = delete; //suppression de l'operateur = pour un systemme
	std::vector<size_t> determine_collisions_possibles(std::unique_ptr<Particule> const& p1);
	size_t choisi_collision(std::vector<size_t> const& collisions_possibles);
	void initialise(unsigned int nbr_argon, unsigned int nbr_fluor, unsigned int nbr_helium, unsigned int nbr_neon);
	void initialise();
	void change_epsilon(double rayon);
};

#endif // PRJ_SYSTEME_H
