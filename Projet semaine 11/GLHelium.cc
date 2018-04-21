#include "GLHelium.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLHelium::GLHelium(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 4.002602, 0.1), sphere(gluNewQuadric())
{
	
}

GLHelium::~GLHelium() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
/*void GLHelium::evolue(double dt)
{
	// mise à jour de la position à partir du pas de temps (via une
	// vitesse, arbitraire ici)
  position += dt / 15.0;
  while (position > 360.0) position -= 360.0;
}*/

void GLHelium::dessine() const
{	glColor4d(1.0, 0.5, 0.0, 1); // couleur rouge, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
}
