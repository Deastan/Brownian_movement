#ifndef PRJ_FENETRE_H
#define PRJ_FENETRE_H

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Vue_OpenGL.h"

class Fenetre: public wxFrame
{
public:
  Fenetre( wxString const& titre 
         , wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );

  virtual ~Fenetre() {}

protected:
  void OnExit(wxCommandEvent& event) { Close(true); }

  Vue_OpenGL* fogl;

DECLARE_EVENT_TABLE()
};
#endif 
