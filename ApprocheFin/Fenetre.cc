/**
 * \file Fenetre.cc
 * \brief est la définition de la classe fenêtre en OpenGL
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#include "Fenetre.h"

/* ===================================================================
   Implementation de Fenetre
   =================================================================== */

BEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_MENU( wxID_EXIT, Fenetre::OnExit )
END_EVENT_TABLE()

// ======================================================================
/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Vecteur avec trois arguements de type double
     *
     * \param titre : le nom que portera la fenetre
     * \param taille : donne la taille de la fenetre
     * \param position : place la fenetre à l'endroit voulu
     * \param style : style de la fenêtre
     */
Fenetre::Fenetre( wxString const& titre 
				, bool reglage
                , wxSize   const& taille
                , wxPoint  const& position
                , long            style
                )
: wxFrame(0, wxID_ANY, titre, position, taille, style)
, fogl(new Vue_OpenGL(this, reglage))
{
	/// Barre de menu
  wxMenu* winMenu = new wxMenu;
	/// Barre de menu
  winMenu->Append(wxID_EXIT, wxT("&Close"));
	/// Barre de menu
  wxMenuBar* menuBar = new wxMenuBar;
   /// Barre de menu
  menuBar->Append(winMenu, wxT("&Window"));

  SetMenuBar(menuBar);

  /// Affiche (montre) la fenetre
  Show(true);

  /// Initialise OpenGL
  fogl->InitOpenGL();
}
