#include "GLFluor.h"

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
GLFluor::GLFluor(Vecteur position, Vecteur vitesse)
:Particule(position, vitesse, 18.998, 0.5),  sphere(gluNewQuadric())
{}

GLFluor::GLFluor(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature)
:Particule(enceinte, tirage, temperature, 18.998, 0.5), sphere(gluNewQuadric())
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
	// mise à jour de la position à partir du pas de temps (via une
	// vitesse, arbitraire ici)
  //position += dt / 15.0;
  //while (position > 360.0) position -= 360.0;
  enregistrerCoordonnee();
  Particule::evolue(dt);
  //cout << "**************************************************************************************************"<<endl;
}

void GLFluor::enregistrerCoordonnee()
{	
	//Partie deque
	if(dequePositions.size()>200)
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
	glColor4d(0.6, 0.34, 0.9, 1); // couleur ??
	//glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);
	
	//ajouter le déplacement
	glPushMatrix();
	glTranslated(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	gluSphere(sphere, rayon,20,20);
	glPopMatrix();
	
}
