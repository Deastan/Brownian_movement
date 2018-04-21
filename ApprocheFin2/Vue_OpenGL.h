/**
 * \file Vue_OenGL.h
 * \brief est le prototype de la classe qui crée et lance le système, timer, evolue de notre système, dessione, etc...
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#ifndef PRJ_VUE_OPENGL_H
#define PRJ_VUE_OPENGL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Systeme.h"
#include <GL/gl.h>
#include <GL/glu.h>


/*! \class Vue_OpenGL
   * \brief Prototype de la classe Vue_OpenGL
   *
   * Cette classe est ce qui remplira la fenêtre et qui gère les animations 
   * dans celle-ci comme notre simulation du gaz parfait.
   * Elle est écrite avec du C++ et de l'OpenGL. representant la partie de 
   * l'OpenGL qui va instancier presque toutes les parties de notre simulation
   */
class Vue_OpenGL : public wxGLCanvas
{
	public:
	///constructeur Vue_OpenGL
	Vue_OpenGL( wxWindow*      parent
            , wxSize  const& taille   = wxDefaultSize     
            , wxPoint const& position = wxDefaultPosition
           
            );
	///constructeur Vue_OpenGL
	Vue_OpenGL( wxWindow*      parent
			, bool reglage
            , wxSize  const& taille   = wxDefaultSize     
            , wxPoint const& position = wxDefaultPosition
           
            );
/*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Vue_OpenGL
     */
	virtual ~Vue_OpenGL() {};
	
	///prototype public de la méthode qui va appeler evolue de systeme
	void InitOpenGL();

	protected:
	///prototype de la méthode dessine 
	void dessine(wxPaintEvent& evenement);
	void OnSize(wxSizeEvent& evenement);
	///prototype de la méthode qui gère les événements du claviers
	void OnKeyDown(wxKeyEvent& evenement);
	///prototype de la méthode qui gères les éveénement de la souris
	void OnEnterWindow(wxMouseEvent& evenement) { SetFocus(); }
	///prototype de la méthode du Timer qui va appeler la méthode évolue du système
	void OnTimer(wxTimerEvent& event);
	///prototype de la méthode qui fait la rotation de l'angle theta pour la caméra 
	void RotateTheta(GLdouble deg);
	///prototype de la méthode qui fait la rotation de l'angle phi pour la caméra
	void RotatePhi(GLdouble deg);
	///prototype de la méthode qui fait le déplacement de la caméra 
	void deplace(double dr);
  
	private:
	Systeme systeme;
	double theta;
	double phi;
	double r;
	// le "Timer"
	wxTimer* timer;
	static int TIMER_ID;

DECLARE_EVENT_TABLE()
};
#endif 
