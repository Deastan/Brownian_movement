#include "Vue_OpenGL.h"

/* ===================================================================
   Implementation de Vue_OpenGL
   =================================================================== */

int Vue_OpenGL::TIMER_ID(12);

BEGIN_EVENT_TABLE(Vue_OpenGL, wxGLCanvas)
    EVT_PAINT(          Vue_OpenGL::dessine       )
    EVT_SIZE(           Vue_OpenGL::OnSize        )
    EVT_KEY_DOWN(       Vue_OpenGL::OnKeyDown     )
    EVT_ENTER_WINDOW(   Vue_OpenGL::OnEnterWindow )
    EVT_TIMER(TIMER_ID, Vue_OpenGL::OnTimer       )
END_EVENT_TABLE()

// ======================================================================

Vue_OpenGL::Vue_OpenGL( wxWindow*      parent
                      , wxSize  const& taille
                      , wxPoint const& position
                      )
: wxGLCanvas(parent, wxID_ANY, position, taille, 
             wxSUNKEN_BORDER|wxFULL_REPAINT_ON_RESIZE , wxT(""))
, theta(35.0), phi(20.0), r(5.0)
, timer(new wxTimer(this, TIMER_ID))
, blob()
{}

// ======================================================================
void Vue_OpenGL::dessine(wxPaintEvent&)
{
  if (!GetContext()) return;

  SetCurrent();

  // commence par effacer l'ancienne image
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* part du système de coordonnées de base 
   * (dessin à l'origine : matrice identité) */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // place la caméra
  gluLookAt(r,   0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 1.0);
  glRotated(theta, 0.0, 1.0, 0.0); 
  glRotated(phi,   0.0, 0.0, 1.0);

 //ICI QUIL FAUT S'AMUSER
	blob.dessine();

  // Finalement, on envoie le dessin à l'écran
  glFlush();
  SwapBuffers();
}

// ======================================================================
void Vue_OpenGL::OnSize(wxSizeEvent& event)
{
  // Nécessaire pour mettre à jour le contexte sur certaines plateformes
  wxGLCanvas::OnSize(event);

  if (GetContext()) {
    // set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
    int w, h;
    GetClientSize(&w, &h);
    SetCurrent();
    glViewport(0, 0, (GLint) w, (GLint) h);
  } 
}

// ======================================================================
void Vue_OpenGL::OnKeyDown( wxKeyEvent& event )
{
  switch( event.GetKeyCode() ) {
  case WXK_LEFT: 
    RotatePhi( 2.0);
    Refresh(false);
    break;

  case WXK_RIGHT: 
    RotatePhi( -2.0);
    Refresh(false);
    break;

  case WXK_UP: 
    RotateTheta( 2.0);
    Refresh(false);
    break;

  case WXK_DOWN: 
    RotateTheta(-2.0);
    Refresh(false);
    break;

  case WXK_HOME:
    r     =  5.0;   // On revient à un point fixé
    theta = 35.0;
    phi   = 20.0;
    Refresh(false);
    break;

  case WXK_PAGEUP:
    deplace(-1.0);    // On se rapproche
    Refresh(false);
    break;

  case WXK_PAGEDOWN:
    deplace(1.0);     // On s'éloigne
    Refresh(false);
    break;

  // Pause sur la touche "espace"
  case ' ':
    if (timer->IsRunning()) {
      timer->Stop();
    } else {
      timer->Start();
    }
    break;
  }
  
  event.Skip();
}

// ======================================================================
void Vue_OpenGL::RotateTheta(GLdouble deg)
{
  theta += deg;
  while (theta < -180.0) { theta += 360.0; }
  while (theta >  180.0) { theta -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::RotatePhi(GLdouble deg)
{
  phi += deg;
  while (phi <   0.0) { phi += 360.0; }
  while (phi > 360.0) { phi -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::deplace(GLdouble dr)
{
  r += dr;
  if (r < 1.0) r = 1.0;
  else if (r > 1000.0) r = 1000.0;
}

// ======================================================================
void Vue_OpenGL::InitOpenGL() 
{
  // Initialisation OpenGL

  SetCurrent();

  // active la gestion de la profondeur
  glEnable(GL_DEPTH_TEST);    

  // active la transparence
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // fixe la perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, 4./3., 1.0, 1000.0);

  // fixe la couleur du fond à noir
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // lance le Timer
  timer->Start(20);
}

// ======================================================================
void Vue_OpenGL::OnTimer(wxTimerEvent& event)
{
  blob.evolue(event.GetInterval());

  // demande l'affichage
  Refresh(false);
}
