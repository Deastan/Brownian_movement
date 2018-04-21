#ifndef PRJ_VUE_OPENGL_H
#define PRJ_VUE_OPENGL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Blob.h"
#include <GL/gl.h>
#include <GL/glu.h>

class Vue_OpenGL : public wxGLCanvas
{
public:
	Vue_OpenGL( wxWindow*      parent
            , wxSize  const& taille   = wxDefaultSize     
            , wxPoint const& position = wxDefaultPosition
            );
  virtual ~Vue_OpenGL() {};
  void InitOpenGL();

protected:


  void dessine(wxPaintEvent& evenement);
  void OnSize(wxSizeEvent& evenement);
  void OnKeyDown(wxKeyEvent& evenement);
  void OnEnterWindow(wxMouseEvent& evenement) { SetFocus(); }
  void OnTimer(wxTimerEvent& event);

  void RotateTheta(GLdouble deg);
  void RotatePhi(GLdouble deg);
  void deplace(double dr);
  
private:
  Blob blob;
  double theta;
  double phi;
  double r;

  // le "Timer"
  wxTimer* timer;
  static int TIMER_ID;

  // le paramètre dépendant du temps
  //double position;

DECLARE_EVENT_TABLE()
};
#endif 
