#include "GLArgon.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLArgon::GLArgon(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 39.948, 0.9), sphere(gluNewQuadric())
{}

GLArgon::GLArgon(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 39.948, 0.9), sphere(gluNewQuadric())
{}

GLArgon::~GLArgon() 
{ 
	gluDeleteQuadric(sphere); 
}

/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
void GLArgon::evolue(double dt)
{
Particule::evolue(dt);
}

void GLArgon::dessine() const
{	
	glEnable(GL_COLOR_MATERIAL);// pour avoir de la couleur sur les boules
	glColor4d(0.0, 1.0, 0.0, 1); // couleur vert, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
}
