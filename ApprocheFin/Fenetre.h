/**
 * \file Fenetre.h
 * \brief est le prototype de la classe fenetre qui permettra de créer une fentre contenant notre application
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#ifndef PRJ_FENETRE_H
#define PRJ_FENETRE_H

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Vue_OpenGL.h"


/*! \class Fenetre
   * \brief Prototype de la classe Fenetre pour l'OpenGL
   * 
   */
class Fenetre: public wxFrame
{
	public:
	/// Constructeur avec arguments 
	Fenetre( wxString const& titre 
		 , bool reglage
         , wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );
	/// destructeur de fenetre
	virtual ~Fenetre() {}

	protected:
	///méthode pour pouvoir refermer la fenetre
	void OnExit(wxCommandEvent& event) { Close(true); }
	
	//attibut
	Vue_OpenGL* fogl;

DECLARE_EVENT_TABLE()
};
#endif 
