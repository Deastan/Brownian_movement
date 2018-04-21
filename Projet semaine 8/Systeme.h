#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H

#include <memory>
#include <vector>

#include "Particule.h"
#include "Enceinte.h"

class Systeme : public Dessinable
{
	private:
	vector<unique_ptr<Particule>> collectionParticule;
	Enceinte enceinte;
	
/*================================================================================
 * Prototypes du constructeur
 *================================================================================*/	
	public:
	Systeme();
	Systeme(double hauteur, double largeur, double profondeur);
	~Systeme();
	
	private:
	Systeme(Systeme const& autre) = delete;//suppression du constructeur de copie
	
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	public:
	void ajouterParticule(Particule* particule);
	void dessine() const override;
	
	
	private:
	bool supprimerParticules();
	Systeme& operator=(Systeme aCopier) = delete; //suppression de l'operateur = pour un systemme
};

#endif // PRJ_SYSTEME_H
