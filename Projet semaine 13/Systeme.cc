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
 : temperature(298)
{ initialise(); }

Systeme::Systeme(double largeur, double longueur, double hauteur, double temperature)
 : enceinte(largeur, longueur, hauteur), temperature(temperature)
{ initialise(); }

Systeme::~Systeme()
{ 
	cout << "Nombre de particules :" << collectionParticules.size() << endl; /// Juste pour vérifier jusqu'à combien environ, on peut monter. En l'occurence au delà de 425, ça lague vraiment ...
	supprimerParticules(); }

/*================================================================================
 * Definition des methodes
 *================================================================================*/

void Systeme::ajouterParticule(Particule* particule)
{ 
	if(particule != nullptr)
	{ collectionParticules.push_back(unique_ptr<Particule>(particule)); }
}

void Systeme::dessine() const
{ 	
	glPushMatrix();
	glTranslated(-enceinte.getLargeur()/2,-enceinte.getLongueur()/2,-enceinte.getHauteur()/2);
	enceinte.dessine();
	
	for(auto const& particule : collectionParticules) 
	{ particule->dessine(); }
	glPopMatrix();
}

bool Systeme::supprimerParticules()
{
	for(auto& particule : collectionParticules)
	{ particule.reset(); }
	return true;
}

void Systeme::evolue(double dt, bool const& exerciceP9)
{
	for (auto const& particule : collectionParticules) 
	{
		particule->evolue(dt);
		
		particule->gere_sorties(enceinte);
		
		vector<size_t> collisions_possibles (determine_collisions_possibles(particule)); /// il faut réfléchir et choisir le epsilon en fonction de la taille des molécules par rapport à l'enceinte
		if (collisions_possibles.size() != 0)
		{
			particule->collision(*collectionParticules[choisi_collision(collisions_possibles)], tirage, exerciceP9);
			///faut-il "découper" le code un peu plus pour qu'il saut plus clair ?
		}
	}
}

vector<size_t> Systeme::determine_collisions_possibles(unique_ptr<Particule> const& p1) ///retourne un tableau contenant les positions dans le tableau collectionParticule des particules qui sont assez proches de la particule que l'on traite pour entrer en collision
{
	vector<size_t> tableau;
	for(size_t i(0);i<collectionParticules.size();++i)
	{
		if((p1 != collectionParticules[i]) and (p1->pavageCubique(epsilon) == collectionParticules[i]->pavageCubique(epsilon)))
		{ tableau.push_back(i); }
	}
	return tableau;
}

size_t Systeme::choisi_collision(vector<size_t> const& collisions_possibles) ///retourne la position dans le tableau collectionParticules de la particule avec laquelle (*this) entre effectivement en collision
{
	return collisions_possibles[tirage.uniforme_entier(0, collisions_possibles.size() - 1)]; ///le tirage uniforme d'ENTIER se faisant sur un intervalle ferme [a, b], il faut tirer sur [0, collisions_possibles.size() - 1] pour que ce soit juste
}

/// Pourrais tu relire toutes ces nouvelles fonctions, histoire de vérifier
/// qu'il n'y a pas de fautes de frappe (j'ai fait bcp de copier-coller ...)

void Systeme::ajouterArgon(unsigned int nbr_argon, bool canon)
{
	GLArgon argon(Vecteur(0,0,0), Vecteur(0,0,0));
	double rayon_argon(argon.get_rayon());
	if (nbr_argon != 0) { change_epsilon(rayon_argon); }
	if (canon) {
		for(int i(1) ; i <= nbr_argon ; ++i)
		{
			double pas(i*rayon_argon);
			ajouterParticule(new GLArgon(Vecteur(pas,pas,pas), Vecteur(250,250,250)));
		}
	} else {
		for(int i(1) ; i <= nbr_argon ; ++i)
		{ ajouterParticule(new GLArgon(enceinte, tirage, temperature)); }
	}
}

void Systeme::ajouterFluor(unsigned int nbr_fluor, bool canon)
{
	GLFluor fluor(Vecteur(0,0,0), Vecteur(0,0,0));
	double rayon_fluor(fluor.get_rayon());
	if (nbr_fluor != 0) { change_epsilon(rayon_fluor); }
	if (canon) {
		for(int i(1) ; i <= nbr_fluor ; ++i)
		{
			double pas(i*rayon_fluor);
			ajouterParticule(new GLFluor(Vecteur(pas,pas,pas), Vecteur(250,250,250)));
		}
	} else {
		for(int i(1) ; i <= nbr_fluor ; ++i)
		{ ajouterParticule(new GLFluor(enceinte, tirage, temperature)); }
	}
}

void Systeme::ajouterHelium(unsigned int nbr_helium, bool canon)
{
	GLHelium helium(Vecteur(0,0,0), Vecteur(0,0,0));
	double rayon_helium(helium.get_rayon());
	if (nbr_helium != 0) { change_epsilon(rayon_helium); }
	if (canon) {
		for(int i(1) ; i <= nbr_helium ; ++i)
		{
			double pas(i*rayon_helium);
			ajouterParticule(new GLHelium(Vecteur(pas,pas,pas), Vecteur(250,250,250)));
		}
	} else {
		for(int i(1) ; i <= nbr_helium ; ++i)
		{ ajouterParticule(new GLHelium(enceinte, tirage, temperature)); }
	}
}

void Systeme::ajouterNeon(unsigned int nbr_neon, bool canon)
{
	GLNeon neon(Vecteur(0,0,0), Vecteur(0,0,0));
	double rayon_neon(neon.get_rayon());
	if (nbr_neon != 0) { change_epsilon(rayon_neon); }
	if (canon) {
		for(int i(1) ; i <= nbr_neon ; ++i)
		{
			double pas(i*rayon_neon);
			ajouterParticule(new GLNeon(Vecteur(pas,pas,pas), Vecteur(250,250,250)));
		}
	} else {
		for(int i(1) ; i <= nbr_neon ; ++i)
		{ ajouterParticule(new GLNeon(enceinte, tirage, temperature)); }
	}
}

void Systeme::initialise(unsigned int nbr_argon, unsigned int nbr_fluor,
                         unsigned int nbr_helium, unsigned int nbr_neon)
{
	epsilon = enceinte.getLargeur();
    ajouterArgon(nbr_argon);
    ajouterFluor(nbr_fluor);
	ajouterHelium(nbr_helium);
    ajouterNeon(nbr_neon);
}

void Systeme::initialise()
{
	initialise(tirage.uniforme_entier(0, 75),
	           tirage.uniforme_entier(0, 3),
	           tirage.uniforme_entier(0, 100),
	           tirage.uniforme_entier(0, 75)); 
} /// J'ai volontairement mis de petits nombres pour que l'on puisse s'amuser avec les canons avant que ça bugge.

void Systeme::change_epsilon(double rayon)
{ if (epsilon > rayon) { epsilon = rayon; }}
