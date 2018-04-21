#include "GLHelium.h"

/// Pour chaque type de particule j'ai mis comme rayon la "vraie" valeur
/// du rayon atomique (qu'il est apparement possible de calculer)
/// ... Tu savais que le neon était "plus petit" que le fluor ? ^^

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/

GLHelium::GLHelium(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 4.002602, 0.31), sphere(gluNewQuadric())
{}

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
	
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
}
