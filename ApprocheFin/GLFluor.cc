/**
 * \file GLFluor.cc
 * \brief est la définition de la classe de la particule fluor en OpenGL qui a en plus une mémorisation et affichage de la trajectoire
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "GLFluor.h"

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
GLFluor::GLFluor(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 18.998, 0.42),  sphere(gluNewQuadric())
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
GLFluor::GLFluor(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 18.998, 0.42), sphere(gluNewQuadric())
{}

GLFluor::~GLFluor() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
 /*!
     *  \brief méthode évolue
     *
     * spéciale pour le fluor car on enresitre ça position dans un deque 
     * (une sorte de tableau) pour pouvoir afficher la trajectoire
     * 
     * \param dt : le pas de temps
     */
void GLFluor::evolue(double dt)
{
	Particule::evolue(dt);
	enregistrerCoordonnee();
}
 /*!
     *  \brief méthode qui enregistre la position/coordonnée de la particule
     */
void GLFluor::enregistrerCoordonnee()
{	
	//Partie deque
	if(dequePositions.size()>150)
	{
		dequePositions.pop_front();
	}
	dequePositions.push_back(new Vecteur(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ()));
}

 /*!
     *  \brief fonction qui surcharge l'opérateur *
     *
     * dessine les points contenu dans le tableau(deque)
     * 
     * dessine la particule de couleur à la position souhaitée par une matrice 
     * de translation 
     */
void GLFluor::dessine() const
{
	
	glColor4d(0.6, 0.34, 0.9, 1);
	glBegin(GL_LINE_STRIP);
	
	if(!dequePositions.empty())
	{
		for(size_t i(0);i<dequePositions.size()-1;i++)
		{
			glVertex3f((*dequePositions[i]).getX(), (*dequePositions[i]).getY(), (*dequePositions[i]).getZ());
		}
	}
	glEnd();
	
	glEnable(GL_COLOR_MATERIAL);// pour avoir de la couleur sur les boules
	glColor4d(0.6, 0.34, 0.9, 1); // couleur mauve
	
	//ajouter le déplacement
	glPushMatrix();
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
	
}
