#include "Systeme.h"

/*================================================================================
 * Definition du constructeur et destructeur
 *================================================================================*/

Systeme::Systeme()
{
		cout << "creation systeme avec enceinte initiale !" << endl;		
}

Systeme::Systeme(double hauteur, double largeur, double profondeur)
: enceinte(hauteur, largeur, profondeur)
{
	cout << "creation systeme avec une enceinte personnalisée !" << endl;
}

Systeme::~Systeme()
{
	supprimerParticules();
	cout << "Je detruit un systeme ! "<< endl;
}

/*================================================================================
 * Definition des methodes
 *================================================================================*/
 
void Systeme::ajouterParticule(Particule* particule)
{ 
	if(particule != nullptr)
	{
		collectionParticule.push_back(unique_ptr<Particule>(particule));
		cout << "Une nouvelle particule a été ajoutée !" << endl;
	}
}

void Systeme::dessine() const
{
	for(auto const& particule : collectionParticule) 
	{
		(*particule).dessine();
	}
}

bool Systeme::supprimerParticules()
{
	cout << "Je suis rentrer dans supprimerPArticule " << endl;
	for(auto& particule : collectionParticule)
	{
		particule.reset();
		cout << "Je supprime une particule " << endl;
	}
	collectionParticule.clear();
	cout << "J'ai fini de supprimer" << endl;
	return true;
}
