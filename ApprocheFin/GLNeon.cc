/**
 * \file GLNeon.cc
 * \brief est la définition de la classe de la particule Néon en OpenGL
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "GLNeon.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
  /*!
     *  \brief Construteur
     *
     * sans le paramètre de température, initialise un rayon et une masse à notre particule
     * 
     * \param position : est la position de la particule que l'on souhaite
     * \param vitesse : est la vitesse de la particule que l'on souhaite 
     */
GLNeon::GLNeon(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 20.1797, 0.38), sphere(gluNewQuadric())
{}
  /*!
     *  \brief Construteur
     *
     * sans le paramètre de température, initialise un rayon et une masse à notre particule
     * 
     * \param enceinte : permet de connaitre les dimmensions de l'emceinte pour calculer les positions
     * \param tirage : donne une position aléatoire de la particule dans l'enceinte
     * \param gtempérature : la température que l'on souhaite pour calculer la vitesse
     */
GLNeon::GLNeon(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 20.1797, 0.38), sphere(gluNewQuadric())
{}

GLNeon::~GLNeon() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
 /*!
     *  \brief méthode évolue
     *
     * \param dt : le pas de temps
     */
void GLNeon::evolue(double dt)
{
	Particule::evolue(dt);
}

 /*!
     *  \brief fonction qui surcharge l'opérateur *
     *
     * dessine la particule de couleur à la position souhaitée par une matrice 
     * de translation 
     */
void GLNeon::dessine() const
{	glColor4d(1.0, 0.0, 0.0, 1); // couleur rouge, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
}
