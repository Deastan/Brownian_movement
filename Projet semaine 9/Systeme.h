#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H

#include <memory>
#include <vector>

#include "Particule.h"
#include "Enceinte.h"
#include "GenerateurAleatoire"

class Systeme : public Dessinable
{
	protected :
	vector<unique_ptr<Particule>> collectionParticules;
	Enceinte enceinte;
	static GenerateurAleatoire tirage; /// Ajouté parce qu'il le suggère
                                       /// dans la partie IV
	
	
/*================================================================================
 * Prototypes des constructeurs et du destructeur
 *================================================================================*/	
	public :
	Systeme();
	Systeme(double largeur, double longueur, double hauteur);
	~Systeme();
	
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
};

GenerateurAleatoire Systeme::tirage(666);

#endif // PRJ_SYSTEME_H
