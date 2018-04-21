/**
 * \file GenerateurAleatoire.h
 * \brief Prototype de la classe qui permet de générer des nombres aléatoires
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#ifndef PRJ_GENERATEURALEATOIRE_H
#define PRJ_GENERATEURALEATOIRE_H

#include <random>

/** \class GenerateurAleatoire
 *  \brief Représente des objets capables de générer des nombres aléatoires
 * 
 * Plusieurs méthodes peuvent être utilisées pour réaliser différents types de tirage
 */

class GenerateurAleatoire {
	
	public:
	
	/// Constructeur par défaut
	GenerateurAleatoire();
	/// Constructeur
	GenerateurAleatoire(unsigned int graine);
	
	/// Méthode permettant de tirer uniformément un entier sur l'intervalle [min, max]
	int uniforme_entier(int min, int max);
	/// Méthode permettant de tirer uniformément un réel sur l'intervalle [min, max[
	double uniforme_reel(double min, double max);
	/// Méthode permettant de tirer un réel suivant la loi normale des probablités (dîtes loi de Gauss)
	double gaussienne(double moyenne, double ecart_type);
	
	private:
	
	/// Graine utile au méthode pour générer des nombres aléatoires
	std::default_random_engine generateur;
	/// Attribut utile pour le tirage uniforme d'entiers
	std::uniform_int_distribution<int> distribution_uniforme_entier;
	/// Attribut utile pour le tirage uniforme de réels
	std::uniform_real_distribution<double> distribution_uniforme_reel;
	/// Attribut utile pour le tirage normal (ou gaussien) de réels
	std::normal_distribution<double> distribution_gaussienne;
  
};

#endif // PRJ_GENERATEURALEATOIRE_H
