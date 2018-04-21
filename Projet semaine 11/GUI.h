#ifndef PRJ_GUI_H
#define PRJ_GUI_H

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL



// ----------------------------------------------------------------------
// Nouvelle application
class GUI : public wxApp
{
	public:
	bool OnInit();
};
#endif 
