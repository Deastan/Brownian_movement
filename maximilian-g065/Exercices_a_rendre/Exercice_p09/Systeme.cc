#include "Systeme.h"

/*================================================================================
 * Definition des constructeurs et du destructeur
 *================================================================================*/
Systeme::Systeme()
{}

Systeme::Systeme(double largeur, double longueur, double hauteur)
: enceinte(largeur, longueur, hauteur)
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
		collectionParticules.push_back(unique_ptr<Particule>(particule));
	}
}

void Systeme::dessine() const
{
	for(auto const& particule : collectionParticules) 
	{
		particule->dessine();
	}
}

bool Systeme::supprimerParticules()
{
	for(auto& particule : collectionParticules)
	{
		particule.reset();
	}
	collectionParticules.clear();
	return true;
}

void Systeme::evolue(double dt)
{
	for (auto const& particule : collectionParticules) 
	{
		particule->evolue(dt);
		
		particule->gere_sorties(enceinte);
		
		vector<size_t> collisions_possibles (determine_collisions_possibles(1, particule)); /// il faut réfléchir et choisir le epsilon en fonction de la taille des molécules par rapport à l'enceinte
		if (collisions_possibles.size() != 0)
		{
			particule->collision(*collectionParticules[choisi_collision(collisions_possibles)], tirage);
			///faut-il "découper" le code un peu plus pour qu'il saut plus clair ?
		}
	}
}

vector<size_t> Systeme::determine_collisions_possibles(double epsilon, unique_ptr<Particule> const& p1) ///retourne un tableau contenant les positions dans le tableau collectionParticule des particules qui sont assez proches de la particule que l'on traite pour entrer en collision
{
	vector<size_t> tableau;
	for(size_t i(0);i<collectionParticules.size();++i)
	{
		if(p1 != collectionParticules[i] and (p1->pavageCubique(epsilon) == collectionParticules[i]->pavageCubique(epsilon)))
		{
			tableau.push_back(i);
		}
	}
	return tableau;
}

size_t Systeme::choisi_collision(vector<size_t> collisions_possibles) ///retourne la position dans le tableau collectionParticules de la particule avec laquelle la particule traitée entre effectivement en collision
{
	return collisions_possibles[floor(tirage.uniforme(0, collisions_possibles.size()))]; ///le tirage uniforme se faisant sur l'intervalle [ 0, collision_possibles.size() [ , pas de problemes + tirage parfaitement équitable si intervalle égaux (se qui est le cas car avec la fonction floor qui retourne la partie entière d'un double tous les intervalles sont de 1)
}

