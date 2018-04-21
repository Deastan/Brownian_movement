#include "Systeme.h"
#include "GLNeon.h"
#include "GLHelium.h"
#include "GLArgon.h"
#include "GLFluor.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs et du destructeur
 *================================================================================*/
Systeme::Systeme()
	: temperature(0.001)
{
	initialise(1,1,1,1);
}

Systeme::Systeme(double largeur, double longueur, double hauteur, double temperature)
: enceinte(largeur, longueur, hauteur), temperature(temperature)
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
	glPushMatrix();
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
		if((p1 != collectionParticules[i]) and (p1->pavageCubique(epsilon) == collectionParticules[i]->pavageCubique(epsilon)))
		{
			tableau.push_back(i);
		}
	}
	return tableau;
}

size_t Systeme::choisi_collision(vector<size_t> collisions_possibles) ///retourne la position dans le tableau collectionParticules de la particule avec laquelle la particule traitée entre effectivement en collision
{
	return collisions_possibles[tirage.uniforme_entier(0, collisions_possibles.size() - 1)]; ///le tirage uniforme d'ENTIER se faisant sur un intervalle ferme [a, b], il faut tirer sur [0, collisions_possibles.size() - 1] pour que ce soit juste
}

void Systeme::initialise(unsigned int nbr_argon, unsigned int nbr_fluor,
                         unsigned int nbr_helium, unsigned int nbr_neon)
{
	/// Il serait peut-être bien de rendre l'ordre des particules dans
	/// le tableau un peu plus aléatoire, ex : s'il reste des molécules de ce
	/// type à placer, tirer à pile ou face si l'on place la particule à
	/// cet endroit
	
	for(int i(1) ; i <= nbr_argon ; ++i)
	{ ajouterParticule(new GLArgon(enceinte, tirage, temperature)); }
	
	for(int i(1) ; i <= nbr_fluor ; ++i)
	{ ajouterParticule(new GLFluor(enceinte, tirage, temperature)); }
	
	for(int i(1) ; i <= nbr_helium ; ++i)
	{ ajouterParticule(new GLHelium(enceinte, tirage, temperature)); }
	
	for(int i(1) ; i <= nbr_neon ; ++i)
	{ ajouterParticule(new GLNeon(enceinte, tirage, temperature)); }
}

void Systeme::initialise()
{
	initialise(tirage.uniforme_entier(0, random_device()()),
	           tirage.uniforme_entier(0, random_device()()),
	           tirage.uniforme_entier(0, random_device()()),
	           tirage.uniforme_entier(0, random_device()()));
}
