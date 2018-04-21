/**
 * \file GenerateurAleatoire.cc
 * \brief Définition de la classe qui permet de générer des nombres aléatoires
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "GenerateurAleatoire.h"

using namespace std;

/** Constructeur sans paramètre.
 *  Permet d'initialiser l'attribut générateur avec un nombre aléatoire
 */
GenerateurAleatoire::GenerateurAleatoire()
 : generateur(std::random_device()())
{}

/** Constructeur prenant un paramètre de type int.
 *  Permet d'initialiser l'attribut générateur avec un nombre donné (utile pour debugger)
 */
GenerateurAleatoire::GenerateurAleatoire(unsigned int graine)
 : generateur(graine)
{}

/** \param min minimum de l'intervalle sur lequel le tirage s'effectue
 *  \param max maximum de l'intervalle sur lequel le tirage s'effectue
 * 
 *  \return Retourne un entier tiré uniformément sur [min, max]
 */
int GenerateurAleatoire::uniforme_entier(int min, int max) {
	return distribution_uniforme_entier(generateur, std::uniform_int_distribution<int>::param_type{min, max});
}

/** \param min minimum de l'intervalle sur lequel le tirage s'effectue
 *  \param max maximum de l'intervalle sur lequel le tirage s'effectue
 * 
 *  \return Retourne un réel tiré uniformément sur [min, max[
 */
double GenerateurAleatoire::uniforme_reel(double min, double max) {
	return distribution_uniforme_reel(generateur, std::uniform_real_distribution<double>::param_type{min, max});
}

/** \param moyenne valeur autour de laquelle s'effectue le tirage
 *  \param ecart_type valeur représentant l'écart moyen à la moyenne des valeurs du tirage
 * 
 *  \return Retourne un réel tiré selon la loi normale N(moyenne, ecart_type)
 */
double GenerateurAleatoire::gaussienne(double moyenne, double ecart_type) {
    return distribution_gaussienne(generateur, std::normal_distribution<double>::param_type{moyenne, ecart_type});
}
