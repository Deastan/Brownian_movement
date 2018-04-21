/**
 * \file Systeme.h
 * \brief Prototype de la classe de la classe Systeme (objet formé d'une enceinte et de particules)
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H

#include <memory>
#include <vector>

#include "Particule.h"
#include "Enceinte.h"
#include "Canon.h"

/** \class Systeme
 *  \brief Permet de créer, de dessiner et de faire évoluer des objets de type Systeme
 *         formés d'une enceinte et de particules */

class Systeme : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private :
	/// Tableau contenant des unique_ptr sur des particules
	/** (permet la résolution dynamique des liens et donc le polymorphisme) */
	std::vector<std::unique_ptr<Particule>> collectionParticules;
	/// Enceinte dans laquelle évolue les particules
	Enceinte enceinte;
	/// Température du systeme
	/** (en Kelvin)
	 *  Nécessaire pour l'initialisation aléatoire des positions et des vitesse des particules */
	double temperature;
	/// Pas d'espace
	double epsilon;
	/// GenerateurAleatoire permettant l'initialisation aléatoire des positions et des vitesse des particules 
	GenerateurAleatoire tirage;
	/// Element graphique
	/** Un canon est dessiné à l'un des coins de l'enceinte */
	Canon canon;
	
/*================================================================================
 * Prototypes des constructeurs et du destructeur
 *================================================================================*/	
	public :
	///Constructeur par défaut
	Systeme();
	/// Constructeur
	Systeme(bool reglage);
	/// Constructeur
	Systeme(double largeur, double longueur, double hauteur, double temperature); /// j'ai enlevé la valeur par défaut parce que conceptuellement c'est mieux, on initialise rien (hasard total) ou tout (determination totale)
	/// Destructeur
	~Systeme();
	
	private :
	Systeme(Systeme const& autre) = delete; //suppression du constructeur de copie
	
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	public :
	/// Permet l'ajout de nbr_argon particules d'Argon
	void ajouterArgon(unsigned int nbr_argon, bool canon = false);
	/// Permet l'ajout de nbr_fluor particules de Fluor
	void ajouterFluor(unsigned int nbr_fluor, bool canon = false);
	/// Permet l'ajout de nbr_helium particules d'Helium
	void ajouterHelium(unsigned int nbr_helium, bool canon = false);
	/// Permet l'ajout de nbr_neon particules de Neon
	void ajouterNeon(unsigned int nbr_neon, bool canon = false);
	/// Dessine le systeme (version graphique)
	void dessine() const override;
	/// Evolue le systeme d'un temps dt
	void evolue(double dt);

	private :
	/// Ajoute une particule au système
	void ajouterParticule(Particule* particule);
	/// Supprime l'ensemble des particules du systeme
	bool supprimerParticules();
	
	Systeme& operator=(Systeme aCopier) = delete; //suppression de l'operateur = pour un systemme
	
	/// Détermine s'il y a des collisions possibles de p1 entre d'autres particules du systeme
	std::vector<size_t> determine_collisions_possibles(std::unique_ptr<Particule> const& p1);
	/// Choisi au hasard qu'elle collision (parmi l'ensemble des collisions possibles)
	/// s'effectue effectivement
	size_t choisi_collision(std::vector<size_t> const& collisions_possibles);
	/// Initialise collectionParticules avec un nombre donné de chaque type de Particule possible
	void initialise(unsigned int nbr_argon, unsigned int nbr_fluor, unsigned int nbr_helium, unsigned int nbr_neon);
	/// Initialise collectionParticules avec un nombre tiré au hasard de chaque type de Particule possible
	void initialise();
	/// Permet d'adapter le pas d'espace aux molécules qui se trouvent effectivement dans l'enceinte
	void change_epsilon(double rayon);
};

#endif // PRJ_SYSTEME_H
