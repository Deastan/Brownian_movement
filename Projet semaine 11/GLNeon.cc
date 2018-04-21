#include "GLNeon.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLNeon::GLNeon(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 20.1797, 0.25), sphere(gluNewQuadric())
{
	
}

GLNeon::~GLNeon() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
/*void GLNeon::evolue(double dt)
{
	// mise à jour de la position à partir du pas de temps (via une
	// vitesse, arbitraire ici)
  position += dt / 15.0;
  while (position > 360.0) position -= 360.0;
}*/

void GLNeon::dessine() const
{	glColor4d(1.0, 0.0, 0.0, 1); // couleur rouge, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
}
