#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include <iostream>
#include "Enceinte.h"

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
Enceinte::Enceinte()
:largeur(20), longueur(20), hauteur(20)
{
	this->dessine();
}

Enceinte::Enceinte(double largeur, double longueur, double hauteur)
:largeur(largeur), longueur(longueur), hauteur(hauteur) 
{
	
}

/*================================================================================
 * Definition des méthodes
 *================================================================================*/
double Enceinte::getLargeur() const
{
	return largeur;
}
double Enceinte::getLongueur() const
{
	return longueur;
}
double Enceinte::getHauteur() const
{
	return hauteur;
}
	
void Enceinte::display() const
{
	cout << largeur << ", " << longueur << ", " << hauteur << endl;
}

void Enceinte::dessine() const
{
	glColor4d(0.0, 0.0, 0.0, 0.5);
	glPointSize(4);
	//fond
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,0);
	glVertex3d(largeur,0,0);
	glVertex3d(largeur,longueur,0);
	glVertex3d(0,longueur,0);
	glVertex3d(0,0,0);
	glEnd();
	
	//fond gauche
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,0);
	glVertex3d(0,0,hauteur);
	glEnd();
	
	//fond droite
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,longueur,0);
	glVertex3d(0, longueur,hauteur);
	glEnd();
	
	//devant gauche
	glBegin(GL_LINE_STRIP);
	glVertex3d(largeur,0,0);
	glVertex3d(largeur,0,hauteur);
	glEnd();
	
	//devant droite
	glBegin(GL_LINE_STRIP);
	glVertex3d(largeur, longueur,0);
	glVertex3d(largeur,longueur,hauteur);
	glEnd();
	
	
	
	//plafond
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,hauteur);
	glVertex3d(largeur,0,hauteur);
	glVertex3d(largeur,longueur,hauteur);
	glVertex3d(0,longueur,hauteur);
	glVertex3d(0,0,hauteur);
	glEnd();
}


