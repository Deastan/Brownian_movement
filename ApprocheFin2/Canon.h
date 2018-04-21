/**
 * \file Canon.h
 * \brief est la classe qui contient l'objet enceinte qui est la boîte où seront nos particules
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_CANON_H
#define PRJ_CANON_H
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Dessinable.h"

/*! \class Canon
   * \brief Prototype de la classe Canon
   *
   * Cette classe est celle qui permet de créer et de dessiner un canon 
   * à particule. Nous avons dessidé de le faire car nous voulions ajouté
   * des particules au systeme.
   * 
   * Elle hérite de dessinable car il fallait avoir une méthode dessine et
   * cela respecte le bonne programmation car on utilise l'héritage.
   * 
   */
class Canon : public Dessinable
{
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	double rayon;
	double longueur;
	GLUquadric* cylindre;
	GLUquadric* bouleFond;
	GLUquadric* roue1;
	GLUquadric* roue2;
	GLUquadric* enjoliveur1;
	GLUquadric* enjoliveur2;
	
	
	public:
/*================================================================================
 * Prototype du constructeur
 *================================================================================*/
	/// Constructeur sans paramètre
	Canon();
	
	/// Destructeur de Canon qui détruit chacune des parties du canons
	~Canon() 
	{
		gluDeleteQuadric(cylindre);
		gluDeleteQuadric(bouleFond);
		gluDeleteQuadric(roue1);
		gluDeleteQuadric(roue2);
		gluDeleteQuadric(enjoliveur1);
		gluDeleteQuadric(enjoliveur2);
	}
	
	
/*================================================================================
 * Prototype des méthodes
 *================================================================================*/

 	/// Prototype de la méthode dessine en OpenGL
	virtual void dessine() const;
};

#endif // PRJ_CANON_H
