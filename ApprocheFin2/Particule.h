/**
 * \file Particule.h
 * \brief Prototype de la classe mère Particule
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H

#include "Vecteur.h"
#include "Dessinable.h"
#include "Enceinte.h"
#include "GenerateurAleatoire.h"

/** \class Particule
 *  \brief Classe mère dont hérite toutes les classes de type : TXTNom et GLNom
 *         Représentation d'une particule (ici version graphique)
 * 
 * C'est une classe virtuelle pure, on ne peut donc pas créer d'instances 
 * de cette classe car il n'est pas logique de créer l'objet générale mais
 * plutôt des classes spécialisées. Elle permet d'avoir une structure générale 
 * et des méthodes que chacunes des particules devra redéfinir.
 */

class Particule : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/	
	protected :
	/** Vecteur représentant la position de la particule dans l'enceinte */
	Vecteur position;
	/** Vecteur représentant la vitesse de la particule */
	Vecteur vitesse;
	/** Nombre réel représentant la masse de la particule (nécessaire pour le calcul des nouvelles vitesses lors d'une collision) */
	double const masse;
	/** Nombre réel représentant le rayon de la particule (nécessaire pour déterminer si des particules entrent en collision) */
	double const rayon;
	
/*================================================================================
 * Prototypage des constructeurs
 *================================================================================*/
	public :
	/// Constructeur par défaut
	Particule();
	/// Constructeur
	Particule(Vecteur position, Vecteur vitesse, double masse, double rayon);
	/// Constructeur
	Particule(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature, double masse, double rayon);
	
/*================================================================================
 * Prototypage des methodes
 *================================================================================*/
	
	/// Permet d'afficher les différents attributs de la particule
	std::ostream& afficher(std::ostream& sortie) const;
	/// S'occupe de faire évoluer la particule d'un temps dt
	virtual void evolue(double dt);
	/// Gére les sorties de l'enceinte
	void gere_sorties(Enceinte const& enceinte);
	/// Calcul le pavage cubique autour d'une particule
	Vecteur pavageCubique(double espsilon) const;
	/// Effectue la collision de deux particules
	void collision(Particule& p, GenerateurAleatoire& tirage);
	/// Getter
	double get_rayon();

};

/// Surcharge de l'opérateur d'affichage
std::ostream& operator<<(std::ostream& sortie, Particule const& p);

#endif // PRJ_PARTICULE_H
