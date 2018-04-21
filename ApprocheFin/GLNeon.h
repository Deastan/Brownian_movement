/**
 * \file GLNeon.h
 * \brief est le prototype de la classe de la particule néon en OpenGL
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

/*! \class GLNeon
   * \brief Prototype de la classe GLNeon
   *
   * Cette classe est celle qui permet de créer une particule de néon
   * en OpenG
   * 
   */
class GLNeon : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
 ///Constructeur avec arguments sans la température du système
	GLNeon(Vecteur position, Vecteur vitesse);
	 ///Constructeur avec arguments avec la température du système et le tirage aléatoire des vecteurs positions
	GLNeon(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature);
	/// Dstructeurs
	virtual ~GLNeon();
	
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

