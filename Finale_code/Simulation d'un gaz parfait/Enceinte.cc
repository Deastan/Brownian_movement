/**
 * \file Enceinte.cc
 * \brief fichier permettant la définition de la classe enceinte
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

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
 /*!
     *  Constructeur de la classe de l'enceinte mais qui initialise à
     * largeur = 100, longueur =100, hauteur = 100
     */
Enceinte::Enceinte()
:largeur(100), longueur(100), hauteur(100)
{}

 /*!
     *  Constructeur de la classe de l'enceinte mais qui initialise 
     * aux valeurs prises comme paramètre
     * 
     * \param bool reglage : permet en fonction de l'utilisateur souhaite
     * d'avoir un appel différents du constructeur
     */
Enceinte::Enceinte(bool reglage)
{
	do
	{
		largeur = wxAtoi(wxGetTextFromUser(wxT("Rentrez une largeur (entre 0 et 150)"), wxT("Paramétrage de l'enceinte")));
	} while (largeur <= 0 or largeur > 150);
	
	do
	{
		longueur = wxAtoi(wxGetTextFromUser(wxT("Rentrez une longueur (entre 0 et 150)"), wxT("Paramétrage de l'enceinte")));
	} while (longueur <= 0 or longueur > 150);
	
	do
	{
		hauteur = wxAtoi(wxGetTextFromUser(wxT("Rentrez une hauteur (entre 0 et 150)"), wxT("Paramétrage de l'enceinte")));
	} while (hauteur <= 0 or hauteur > 150);
}

 /*!
     *  Constructeur de la classe de l'enceinte mais qui initialise 
     * aux valeurs prises comme paramètre
     * 
     * \param double largeur 
     * \param double longueur 
     * \param double hauteur
     */
Enceinte::Enceinte(double largeur, double longueur, double hauteur)
:largeur(largeur), longueur(longueur), hauteur(hauteur) 
{}

/*================================================================================
 * Definition des méthodes
 *================================================================================*/
  /*!
     *  Methode qui permet de retourner les attributs privés de la largeur
     *
     *  \return la largeur
     */
double Enceinte::getLargeur() const
{
	return largeur;
}
  /*!
     *  Methode qui permet de retourner les attributs privés de la longueur
     *
     *  \return la longueur
     */
double Enceinte::getLongueur() const
{
	return longueur;
}
  /*!
     *  Methode qui permet de retourner les attributs privés de la hauteur
     *
     *  \return la hauteur
     */
double Enceinte::getHauteur() const
{
	return hauteur;
}
/*!
 * méthode pour afficher dans le terminal la dimension de l'enceinte
     */
void Enceinte::display() const
{
	cout << largeur << ", " << longueur << ", " << hauteur << endl;
}

 /*!
     *  \brief définition de la méthode dessine de l'enceinte en OpenGL
     *
     *	elle va prendre prendre une couleur noire, et dessiner 
     * des traits qui vont faire le tours de l'enceinte
     *
     */
void Enceinte::dessine() const
{
	glColor4d(0.0, 0.0, 0.0, 0.5);
	glPointSize(4);
	
	//fond de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,0);
	glVertex3d(largeur,0,0);
	glVertex3d(largeur,longueur,0);
	glVertex3d(0,longueur,0);
	glVertex3d(0,0,0);
	glEnd();
	
	//fond gauche de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,0);
	glVertex3d(0,0,hauteur);
	glEnd();
	
	//fond droite de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,longueur,0);
	glVertex3d(0, longueur,hauteur);
	glEnd();
	
	//devant gauche de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(largeur,0,0);
	glVertex3d(largeur,0,hauteur);
	glEnd();
	
	//devant droite de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(largeur, longueur,0);
	glVertex3d(largeur,longueur,hauteur);
	glEnd();
	
	//plafond  de l'enceinte
	glBegin(GL_LINE_STRIP);
	glVertex3d(0,0,hauteur);
	glVertex3d(largeur,0,hauteur);
	glVertex3d(largeur,longueur,hauteur);
	glVertex3d(0,longueur,hauteur);
	glVertex3d(0,0,hauteur);
	glEnd();
}


