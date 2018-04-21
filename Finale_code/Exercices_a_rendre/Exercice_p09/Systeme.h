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
	GenerateurAleatoire tirage;
		
/*================================================================================
 * Prototypes des constructeurs et du destructeur
 *================================================================================*/	
	public :
	Systeme();
	Systeme(double largeur, double longueur, double hauteur);
	~Systeme();//destructeur
	
	private :
	Systeme(Systeme const& autre) = delete; //suppression du constructeur de copie
	
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	public :
	void ajouterParticule(Particule* particule);
	void dessine() const override;
	void evolue(double dt);

	private :
	bool supprimerParticules();
	Systeme& operator=(Systeme aCopier) = delete; //suppression de l'operateur = pour un systemme
	vector<size_t> determine_collisions_possibles(double epsilon, unique_ptr<Particule> const& p1);
	size_t choisi_collision(vector<size_t> collisions_possibles);
};

#endif // PRJ_SYSTEME_H
