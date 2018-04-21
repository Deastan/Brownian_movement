/**
 * \file GLHelium.h
 * \brief est le prototype de la classe de la particule Helium en OpenGL
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "Particule.h"

/*! \class GLHelium
   * \brief Prototype de la classe GLHelium
   *
   * Cette classe est celle qui permet de créer une particule d'helium
   * en OpenG
   *    */
class GLHelium : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
 ///Constructeur avec arguments sans la température du système
	GLHelium(Vecteur position, Vecteur vitesse);
	 ///Constructeur avec arguments avec la température du système et le tirage aléatoire des vecteurs positions
	GLHelium(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature);
	/// Dstructeurs
	virtual ~GLHelium();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
 /// Prototype de la méthode evolue 
	virtual void evolue(double dt);
	/// Prototype de la méthode evolue 
	virtual void dessine() const;
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;
};

