/**
 * \file GLFluor.h
 * \brief est le prototype de la classe de la particule fluor en OpenGL 
 * qui a en plus une mémorisation et affichage de la trajectoire
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include <vector>
#include <deque>
#include "Vecteur.h"
#include "Particule.h"

/*! \class GLFluor
   * \brief Prototype de la classe GLluor
   *
   * Cette classe est celle qui permet de créer une particule de fluor
   * en OpenGL et permet aussi de suivre à la trace cette particule
   * grâce à un deque qui enregistre chaque position pendant un certain intervalle.
   * Nous avos pas besoins de toutes les positions d'ou le fait que nous supprimons 
   * après 150 pas de temps les anciennes positions.
   * Nous avos choisis un deque car il fallait une faible complexité pour 
   * détruire la première ligne.
   *    */
class GLFluor : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
 ///Constructeur avec arguments sans la température du système
	GLFluor(Vecteur position, Vecteur vitesse);
	 ///Constructeur avec arguments avec la température du système et le tirage aléatoire des vecteurs positions
	GLFluor(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature);
	/// Dstructeurs
	virtual ~GLFluor();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	/// Prototype de la méthode evolue 
	virtual void evolue(double dt);
	/// Prototype de la méthode evolue 
	virtual void dessine() const;
	/// Prototye de la méthode qui va enregistrer les coordonnées
	void enregistrerCoordonnee();
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;
	std::deque<Vecteur*> dequePositions;
};

