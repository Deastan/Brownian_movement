#include "Systeme.h"

/*================================================================================
 * Definition des constructeurs et du destructeur
 *================================================================================*/

Systeme::Systeme()
{
		cout << "creation systeme avec enceinte initiale !" << endl;		
}

Systeme::Systeme(double largeur, double longueur, double hauteur)
: enceinte(largeur, longueur, hauteur)
{
	cout << "creation systeme avec une enceinte personnalisée !" << endl;
}

Systeme::~Systeme()
{
	supprimerParticules();
	cout << "Je detruis un systeme ! "<< endl;
}

/*================================================================================
 * Definition des methodes
 *================================================================================*/
 
void Systeme::ajouterParticule(Particule* particule)
{ 
	if(particule != nullptr)
	{
		collectionParticules.push_back(unique_ptr<Particule>(particule));
		cout << "Une nouvelle particule a été ajoutée !" << endl;
	}
}

void Systeme::dessine() const
{
	for(auto const& particule : collectionParticules) 
	{
		(*particule).dessine();
	}
}

bool Systeme::supprimerParticules()
{
	cout << "Je suis rentrer dans supprimerParticules " << endl;
	for(auto& particule : collectionParticules)
	{
		particule.reset();
		cout << "Je supprime une particule " << endl;
	}
	collectionParticules.clear();
	cout << "J'ai fini de supprimer" << endl;
	return true;
}

void Systeme::evolue(double dt)
{
	for (auto particule : collectionParticules) {
		particule->evolue(double dt);
		vector<bool> liste_parois_depassees (6, false);
		particule->gere_sortie(enceinte);
		/// Suite : il faut regarder si la particule en rencontre une autre
		/// il faut donc sûrement faire appel à une fonction rencontre_particule
		/// comme c'est ta partie je ne sais pas comment faire l'appel
	}
}

