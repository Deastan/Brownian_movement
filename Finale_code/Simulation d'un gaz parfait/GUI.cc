/**
 * \file GUI.cc
 * \brief est la définition de l'application princpal qui lance tout le programme
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "GUI.h"
#include "Fenetre.h"

/* ===================================================================
   Implementation de l'application principale
   =================================================================== */

 /*!
  * Nous avons décider de faire une interface utilisateur et la première
  * question est où mettre un tel objet ? Ici dans onInit. C'est de savoir 
  * si on veut créer un système aléatoire ou pas et va le transmettre en arguments
  * pour que la donnée transite jusqu'où elle doit aller
  * 
     *  \return true si la fenere à pu être créé
     */
bool GUI::OnInit()
{
	/// variable utile pour enregistrer le choix de l'uitlisateur
	bool reglage(false);
	///permet de poser la question à l'utilisateur pour parameter le systeme ou non
	///si il dit oui, le booléens sera true !
	if (wxMessageBox(wxT("Voulez-vous paramétrer le système ?"), wxT("Lancement de la simulation"),
		wxYES_NO | wxICON_QUESTION)==wxYES)
	{ reglage = true; }
	
	Fenetre* f (nullptr);
	
	if (reglage) { f = new Fenetre(wxT("Simulation temps reel"),
                                   reglage, wxSize(800, 600)); }
    else { f = new Fenetre(wxT("Simulation temps reel"),
                           wxSize(800, 600)); }
    
	SetTopWindow(f);
	return (f != 0);
}

/* ===================================================================
   Equivalent de main()
   =================================================================== */
///remplace la main
IMPLEMENT_APP(GUI)
