#ifndef PRJ_H2O_H
#define PRJ_H2O_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Machin.h"

class H2O : public Machin
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	H2O();
	virtual ~H2O();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	void evolue(double dt);
	virtual void dessine() const;
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;
	
};

#endif 
