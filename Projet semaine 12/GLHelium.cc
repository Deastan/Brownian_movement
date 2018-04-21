#include "GLHelium.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLHelium::GLHelium(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 4.002602, 0.3), sphere(gluNewQuadric())
{}

GLHelium::GLHelium(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 4.002602, 0.3), sphere(gluNewQuadric())
{}

GLHelium::~GLHelium() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
void GLHelium::evolue(double dt)
{
Particule::evolue(dt);
}

void GLHelium::dessine() const
{	
	glEnable(GL_COLOR_MATERIAL);// pour avoir de la couleur sur les boules
	glColor4d(1.0, 0.5, 0.0, 1);  // orange ?

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
}
