/**
 * \file Canon.cc
 * \brief fichier permettant la définition de la classe Canon
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Canon.h"
#include <iostream>

using namespace std;

/*================================================================================
 * Definition des constructeurs
 *================================================================================*/
 /*!
     *  Constructeur de la classe du Canon qui initialise la longueur et 
     * le rayon et les quadrics qui permette d'avoir chacune des composants
     * de notre canon
     * cylindre : structure principale
     * Boule : permet d'avoir un arrondi sur le bout du canon
     * roue1 et roue2 sont les roues du canon
     * enjoliveurs sont les caches de roues
     * 
     */
Canon::Canon()
:rayon(3), longueur(10), cylindre(gluNewQuadric()), bouleFond(gluNewQuadric()), roue1(gluNewQuadric()),
	roue2(gluNewQuadric()), enjoliveur1(gluNewQuadric()), enjoliveur2(gluNewQuadric())
{}

/*================================================================================
 * Definition des méthodes
 *================================================================================*/
 /*!
     *
     *	elle va prendre prendre une couleur noire, et dessiner 
     * 	le canon qui a plusieurs composants dans les différents endroits
     * 	graĉe aux matrices de translations, rotations
     */
void Canon::dessine() const
{
	
	glColor4d(0.0, 0.0, 0.0, 1); // couleur vert, 100%
	///dessin du cylindre du canon
	glPushMatrix();
	glTranslated(-longueur/2,-longueur/2,-longueur/2);
	glRotated(55, -1,1,0);
	gluCylinder(cylindre, rayon, rayon, longueur, 10, 10);
	glPopMatrix();
	
	///dessin du fond du canon
	glPushMatrix();
	glTranslated(-longueur/2,-longueur/2,-longueur/2);
	gluSphere(bouleFond, rayon, 10, 10);
	glPopMatrix();
	
	///dessin de la roue 1
	glColor4d(0.7, 0.2, 0.2, 1);
	glPushMatrix();
	glTranslated(-longueur/1.5+rayon,-longueur/1.5,-longueur/1.5);
	glRotated(90, 1,1,0);
	gluDisk(enjoliveur1, 0, rayon/1.5, 10, 1);
	gluCylinder(roue1, rayon/1.5, rayon/1.5, longueur/10, 10, 10);
	glPopMatrix();
	
	///dessin de la roue deux
	glColor4d(0.7, 0.2, 0.2, 1);
	glPushMatrix();
	glTranslated(-longueur/1.5,-longueur/1.5+rayon,-longueur/1.5);
	glRotated(90, 1,1,0);
	gluDisk(enjoliveur2, 0,rayon/1.5, 10, 1);
	gluCylinder(roue2, rayon/1.5, rayon/1.5, longueur/10, 10, 10);
	glPopMatrix();
}


