#include "GLFluor.h"

/// Pour chaque type de particule j'ai mis comme rayon la "vraie" valeur
/// du rayon atomique (qu'il est apparement possible de calculer)
/// ... Tu savais que le neon était "plus petit" que le fluor ? ^^

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/

GLFluor::GLFluor(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 18.998, 0.42),  sphere(gluNewQuadric())
{}

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
void GLFluor::evolue(double dt)
{

	
	Particule::evolue(dt);
	enregistrerCoordonnee();
}

void GLFluor::enregistrerCoordonnee()
{	
	//Partie deque
	if(dequePositions.size()>150)
	{
		dequePositions.pop_front();
	}
	dequePositions.push_back(new Vecteur(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ()));
}

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
	//glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);
	
	//ajouter le déplacement
	glPushMatrix();
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
	
}
