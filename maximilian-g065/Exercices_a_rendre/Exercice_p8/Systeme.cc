#include <iostream>
#include "Systeme.h"

using namespace std;

/*================================================================================
 * Definition du constructeur et destructeur
 *================================================================================*/

Systeme::Systeme()
{		}

Systeme::Systeme(double hauteur, double largeur, double profondeur)
: enceinte(hauteur, largeur, profondeur)
{}

Systeme::~Systeme()
{
	supprimerParticules();
}

/*================================================================================
 * Definition des methodes
 *================================================================================*/
 
void Systeme::ajouterParticule(Particule* particule)
{ 
	if(particule != nullptr)
	{
		collectionParticule.push_back(unique_ptr<Particule>(particule));
	}
}

void Systeme::dessine() const
{
	cout << "Le système est constitué des " << collectionParticule.size() << " particules suivantes :" << endl;
	for(auto const& particule : collectionParticule) 
	{
		(*particule).dessine();
	}
}

bool Systeme::supprimerParticules()
{
	for(auto& particule : collectionParticule)
	{
		particule.reset();
	}
	collectionParticule.clear();
	return true;
}
