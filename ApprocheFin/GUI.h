/**
 * \file GUI.h
 * \brief est le prototype de l'application princpal qui lance tout le programme
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date mai 2014
 */

#ifndef PRJ_GUI_H
#define PRJ_GUI_H

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

/*! \class GUI
   * \brief Application principale
   * 
   */
class GUI : public wxApp
{
	public:
	/// prototype qui lance l'application en appelant les différents constructeurs
	bool OnInit();

};
#endif 
