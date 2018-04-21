/**
 * \file GLHelium.cc
 * \brief est la définition de la classe de la particule Helium en OpenGL
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "GLHelium.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
  /*!
     * sans le paramètre de température, initialise un rayon et une masse à notre particule
     * 
     * \param position : est la position de la particule que l'on souhaite
     * \param vitesse : est la vitesse de la particule que l'on souhaite 
     */
GLHelium::GLHelium(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 4.002602, 0.31), sphere(gluNewQuadric())
{}
  /*!
     * sans le paramètre de température, initialise un rayon et une masse à notre particule
     * 
     * \param enceinte : permet de connaitre les dimmensions de l'emceinte pour calculer les positions
     * \param tirage : donne une position aléatoire de la particule dans l'enceinte
     * \param gtempérature : la température que l'on souhaite pour calculer la vitesse
     */
GLHelium::GLHelium(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 4.002602, 0.31), sphere(gluNewQuadric())
{}

GLHelium::~GLHelium() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
 /*!
  * appelle la méthode évolue de la classe particule 
     * \param dt : le pas de temps
     */
void GLHelium::evolue(double dt)
{
	Particule::evolue(dt);
}

 /*!
     * dessine la particule de couleur à la position souhaitée par une matrice 
     * de translation 
     */
void GLHelium::dessine() const
{	
	glColor4d(1.0, 0.5, 0.0, 1);  /// orange 

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
}
