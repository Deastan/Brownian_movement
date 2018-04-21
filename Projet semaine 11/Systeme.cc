#include "Systeme.h"
#include "GLNeon.h"
#include "GLHelium.h"
#include "GLArgon.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs et du destructeur
 *================================================================================*/
Systeme::Systeme()
{
	//initialiserParticule(2,3,45);
	for(int i(0);i<15;i++)
	{
		ajouterParticule(new GLNeon(Vecteur(5, i+1, 10), Vecteur(0.05, 0.022, 0.002)));
	}
	for(int i(0);i<4;i++)
	{
		ajouterParticule(new GLHelium(Vecteur(i+10, 2, 10), Vecteur(0.05, 0.022, 0.002)));
	}
	for(int i(0);i<7;i++)
	{
		ajouterParticule(new GLArgon(Vecteur(i+2, 2, 10), Vecteur(0.05, 0.022, 0.002)));
	}
}

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
{ 	glPushMatrix();
	glTranslated(-enceinte.getLargeur()/2,-enceinte.getLongueur()/2,-enceinte.getHauteur()/2);
	enceinte.dessine();
	
	for(auto const& particule : collectionParticules) 
	{
		particule->dessine();
	}
	glPopMatrix();
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

void Systeme::evolue(double dt, bool const& exerciceP9)
{
	for (auto const& particule : collectionParticules) 
	{
		particule->evolue(dt);
		
		particule->gere_sorties(enceinte);
		
		vector<size_t> collisions_possibles (determine_collisions_possibles(1, particule)); /// il faut réfléchir et choisir le epsilon en fonction de la taille des molécules par rapport à l'enceinte
		if (collisions_possibles.size() != 0)
		{
			particule->collision(*collectionParticules[choisi_collision(collisions_possibles)], tirage, exerciceP9);
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

