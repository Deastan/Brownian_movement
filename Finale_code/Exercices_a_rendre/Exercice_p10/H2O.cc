#include "H2O.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
H2O::H2O()
:sphere(gluNewQuadric())
{}

H2O::~H2O() 
{ 
	gluDeleteQuadric(sphere); 
}


/*================================================================================
 * Definition des méthodes 
 *================================================================================*/
void H2O::evolue(double dt)
{}

void H2O::dessine() const
{
	// dessin de la première sphère
    glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
    glTranslated(-1.0, 0.0, 0.5);  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
    glColor4d(0.0, 0.0, 1.0, 1.0); // Choisir la couleur (bleu ici)
    gluSphere(sphere, 1.0, 30, 30);// Dessiner une sphère
    glPopMatrix();                 // Revenir à l'ancienne position

    // dessin de la seconde sphère
    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0); 
    glColor4d(0.0, 1.0, 1.0, 1.0); // choisi la couleur (turquoise ici)
    gluSphere(sphere, 1.5, 50, 50);
    glPopMatrix();

    // dessin de la troisième sphère
    glPushMatrix();
    glTranslated(1.0, 0.0, 0.5);
    glColor4d(0.0, 0.8, 0.0, 1.0);  //vert
    gluSphere(sphere, 1.0, 50, 50);
    glPopMatrix();
}
