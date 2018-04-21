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
     *  \brief méthode qui lance toute l'application et qui va cérer la fenêtre
     *
     *  \return true si la fenere à pu être créé
     */
bool GUI::OnInit()
{
	bool reglage(false);
	if (wxMessageBox(wxT("Voulez-vous paramétrer le système ?"), wxT("Lancement de la simulation"),
		wxYES_NO | wxICON_QUESTION)==wxYES)
	{
		reglage = true;
	}


	
  // Crée la fenêtre principale
  Fenetre* f = new Fenetre(wxT("Simulation temps reel"),
                            reglage, wxSize(800, 600));
  SetTopWindow(f);
  return (f != 0);
}

/* ===================================================================
   Equivalent de main()
   =================================================================== */
///remplace la main
IMPLEMENT_APP(GUI)
