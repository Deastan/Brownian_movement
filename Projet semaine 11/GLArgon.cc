#include "GLArgon.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLArgon::GLArgon(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 39.948, 0.5), sphere(gluNewQuadric())
{
	
}

GLArgon::~GLArgon() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
/*void GLArgon::evolue(double dt)
{
	// mise à jour de la position à partir du pas de temps (via une
	// vitesse, arbitraire ici)
  position += dt / 15.0;
  while (position > 360.0) position -= 360.0;
}*/

void GLArgon::dessine() const
{	glColor4d(0.0, 1.0, 0.0, 1); // couleur rouge, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
}
