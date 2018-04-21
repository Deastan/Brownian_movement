#include "GLNeon.h"

/// Pour chaque type de particule j'ai mis comme rayon la "vraie" valeur
/// du rayon atomique (qu'il est apparement possible de calculer)
/// ... Tu savais que le neon était "plus petit" que le fluor ? ^^

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/

GLNeon::GLNeon(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 20.1797, 0.38), sphere(gluNewQuadric())
{}

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
void GLNeon::evolue(double dt)
{
	Particule::evolue(dt);
}

void GLNeon::dessine() const
{	glColor4d(1.0, 0.0, 0.0, 1); // couleur rouge, 100%

	//ajouter le déplacement
	glPushMatrix();
	
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	
	gluSphere(sphere,rayon,10,10); /// J'ai remis 10 partout
	glPopMatrix();
}
