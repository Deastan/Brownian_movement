/**
 * \file Systeme.cc
 * \brief Définition de la classe Systeme (objet formé d'une enceinte et de particules)
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "Systeme.h"
#include "GLNeon.h"
#include "GLHelium.h"
#include "GLArgon.h"
#include "GLFluor.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

using namespace std;

/*================================================================================
 * Definition des constructeurs et du destructeur
 *================================================================================*/

/** Initialise un nombre aléatoire de particules et dans une enceinte par défaut à la température normale */
Systeme::Systeme()
 : temperature(298) // Température normale : 25°C
{ initialise(); }

/** Ce constructeur permet à l'utilisateur de paramétrer lui même le systeme
 *  au lancement du programme grâce à une interface graphique.
 * 
 *  \param reglage booléen permettant de différencier l'initialisation
 *         par défaut et l'initialisation paramétrée
 *  */
Systeme::Systeme(bool reglage)
 : enceinte(reglage), temperature(298)
{
	do
	{
		temperature = wxAtoi(wxGetTextFromUser(wxT("Rentrez une température (entre 0 et 400 Kelvin)"), wxT("Température")));
	} while (temperature <= 0 or temperature > 400);
	
	double nbrArgon(0);
	do
	{
		nbrArgon = wxAtoi(wxGetTextFromUser(wxT("Rentrez le nombre de particules d'Argon (entre 0 et 425, Attention : ne pas créer plus de 425 particules en tout)"), wxT("Paramétrage du nombre de particules")));
	} while (nbrArgon < 0 or nbrArgon > 425);
	
	double nbrFluor(0);
	do
	{
		nbrFluor = wxAtoi(wxGetTextFromUser(wxT("Rentrez le nombre de particules de Fluor (entre 0 et 3, Attention : ne pas créer plus de 425 particules en tout)"), wxT("Paramétrage du nombre de particules")));
	} while (nbrFluor < 0 or nbrFluor > 3);
	
	double nbrHelium(0);
	do
	{
		nbrHelium = wxAtoi(wxGetTextFromUser(wxT("Rentrez le nombre de particules d'Helium (entre 0 et 425, Attention : ne pas créer plus de 425 particules en tout)"), wxT("Paramétrage du nombre de particules")));
	} while (nbrHelium < 0 or nbrHelium > 425);
	
	double nbrNeon(0);
	do
	{
		nbrNeon = wxAtoi(wxGetTextFromUser(wxT("Rentrez le nombre de particules de Néon (entre 0 et 425, Attention : ne pas créer plus de 425 particules en tout)"), wxT("Paramétrage du nombre de particules")));
	} while (nbrNeon < 0 or nbrNeon > 425);
	
	initialise(nbrArgon,nbrFluor,nbrHelium,nbrNeon);
}

/** Permet d'initialiser le systeme en fournissant tous les paramètres avant le lancement du programme.
 *  Les particules elles sont initialisées complètement au hasard.
 *  \param largeur Largeur de l'enceinte
 *  \param longueur Longueur de l'enceinte
 *  \param hauteur Hauteur de l'enceinte
 *  \param temperature Température du système
 */
Systeme::Systeme(double largeur, double longueur, double hauteur, double temperature)
 : enceinte(largeur, longueur, hauteur), temperature(temperature)
{ initialise(); }

/** Permet de libérer la mémoire allouée au moment de la création des unique_ptr<Particule> */
Systeme::~Systeme()
{ supprimerParticules(); }

/*================================================================================
 * Definition des methodes
 *================================================================================*/

/** \param particule Pointeur sur une particule à ajouter à collectionParticules */
void Systeme::ajouterParticule(Particule* particule)
{ 
	if(particule != nullptr)
	{ collectionParticules.push_back(unique_ptr<Particule>(particule)); }
}

/** Dessine l'enceinte, le canon et l'ensemble des particules du systeme */
void Systeme::dessine() const
{ 	
	glPushMatrix();
	glTranslated(-enceinte.getLargeur()/2,-enceinte.getLongueur()/2,-enceinte.getHauteur()/2);
	enceinte.dessine();
	canon.dessine();
	
	for(auto const& particule : collectionParticules) 
	{ particule->dessine(); }
	glPopMatrix();
}

/** (private pour éviter que n'importe qui est accès à cette méthode,
 *  la suppression des particules ne devant se faire que lors de la destruction du système)
 *  \return Retourne un booléen qui indique si la suppression s'est bien déroulée */
bool Systeme::supprimerParticules()
{
	for(auto& particule : collectionParticules)
	{ particule.reset(); }
	return true;
}

/** Evolution déterministe sans sauvegarde.
 *  Pour chaque particule : on l'évolue, puis on regarde si elle sort de 
 *  l'enceinte et enfin on regarde si elle entre en collision avec une autre particule
 *  
 *  \param dt Pas de temps */
void Systeme::evolue(double dt)
{
	for (auto const& particule : collectionParticules) 
	{
		particule->evolue(dt);
		
		particule->gere_sorties(enceinte);
		
		vector<size_t> collisions_possibles (determine_collisions_possibles(particule));
		if (collisions_possibles.size() != 0)
		{ particule->collision(*collectionParticules[choisi_collision(collisions_possibles)], tirage); }
	}
}

/** \param p1 particule dont on doit déterminer les collisions possibles
 *  \return Retourne un tableau contenant les positions, dans le tableau collectionParticule,
 *          des particules qui sont assez proches de la particule que l'on traite pour entrer en collision */
vector<size_t> Systeme::determine_collisions_possibles(unique_ptr<Particule> const& p1)
{
	vector<size_t> tableau;
	for(size_t i(0);i<collectionParticules.size();++i)
	{
		if((p1 != collectionParticules[i]) and (p1->pavageCubique(epsilon) == collectionParticules[i]->pavageCubique(epsilon)))
		{ tableau.push_back(i); }
	}
	return tableau;
}

/** \param collisions_possibles Tableau contenant l'ensemble des positions (dans le tableau collectionParticule) des particules qui pourraient entrer en collision avec la particule traitée
 *  \return Retourne la position dans le tableau collectionParticules de la particule avec laquelle la particule traitée entre effectivement en collision */
size_t Systeme::choisi_collision(vector<size_t> const& collisions_possibles)
{ return collisions_possibles[tirage.uniforme_entier(0, collisions_possibles.size() - 1)]; }
  //le tirage uniforme d'ENTIER se faisant sur un intervalle fermé [a, b], il faut donc tirer sur [0, collisions_possibles.size() - 1] pour que ce soit juste

/** \param nbr_argon Nombre de particules d'Argon à ajouter au système
 *  \param canon booléen permettant de déterminer la manière dont l'ajout doit se faire :
 *         true -> tire de canon = ajout d'une file de particule allant toutes dans la même direction
 *         false -> initialisation aléatoire de la position et de la vitesse de chaque particule */
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

/** \param nbr_fluor Nombre de particules de Fluor à ajouter au système
 *  \param canon booléen permettant de déterminer la manière dont l'ajout doit se faire :
 *         true -> tire de canon = ajout d'une file de particule allant toutes dans la même direction
 *         false -> initialisation aléatoire de la position et de la vitesse de chaque particule */
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

/** \param nbr_helium Nombre de particules d'Helium à ajouter au système
 *  \param canon booléen permettant de déterminer la manière dont l'ajout doit se faire :
 *         true -> tire de canon = ajout d'une file de particule allant toutes dans la même direction
 *         false -> initialisation aléatoire de la position et de la vitesse de chaque particule */
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

/** \param nbr_neon Nombre de particules de Neon à ajouter au système
 *  \param canon booléen permettant de déterminer la manière dont l'ajout doit se faire :
 *         true -> tire de canon = ajout d'une file de particule allant toutes dans la même direction
 *         false -> initialisation aléatoire de la position et de la vitesse de chaque particule */
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

/** \param nbr_argon Nombre de particules d'Argon à ajouter au système
 *  \param nbr_fluor Nombre de particules de Fluor à ajouter au système
 *  \param nbr_helium Nombre de particules d'Helium à ajouter au système
 *  \param nbr_neon Nombre de particules de Neon à ajouter au système */
void Systeme::initialise(unsigned int nbr_argon, unsigned int nbr_fluor,
                         unsigned int nbr_helium, unsigned int nbr_neon)
{
	epsilon = enceinte.getLargeur();
    ajouterArgon(nbr_argon);
    ajouterFluor(nbr_fluor);
	ajouterHelium(nbr_helium);
    ajouterNeon(nbr_neon);
}

/** Pas de paramètres, le nombre de particule à ajouter est tiré au hasard pour chaque type de particules. */
void Systeme::initialise()
{
	initialise(tirage.uniforme_entier(0, 75),
	           tirage.uniforme_entier(0, 3),
	           tirage.uniforme_entier(0, 100),
	           tirage.uniforme_entier(0, 75)); 
}

/** Est appelé à l'initialisation du système et à chaque fois que l'on rajoute des particules avec le canon
 *  \param rayon Rayon de la particule qui vient d'être rajoutée */
void Systeme::change_epsilon(double rayon)
{ if (epsilon > rayon) { epsilon = rayon; }}
