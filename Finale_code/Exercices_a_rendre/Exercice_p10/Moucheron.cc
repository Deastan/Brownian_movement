#include "Moucheron.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
Moucheron::Moucheron(double position)
:position(position), sphere(gluNewQuadric())
{}

Moucheron::~Moucheron() 
{ gluDeleteQuadric(sphere); }


/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
void Moucheron::evolue(double dt)
{
	// mise à jour de la position à partir du pas de temps (via une
	// vitesse, arbitraire ici)
  position += dt / 15.0;
  while (position > 360.0) position -= 360.0;
}

void Moucheron::dessine() const
{
 	// Dessin de la petite sphère qui tourne
	glPushMatrix();
	glRotated(position, 0.0, 0.0, 1.0); /* on la fait tourner de "position" 
										* autour de Oz...                   */
	glTranslated(2.0, 0.0, 0.0);        /* ...sur un cercle de rayon 2.0     */
	glColor4d(1.0, 0.0, 0.0, 0.6); // couleur rouge, transparente à 40%
	gluSphere(sphere, 0.1, 30, 30);
	glPopMatrix();
}
