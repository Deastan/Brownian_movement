#ifndef PRJ_MOUCHERON_H
#define PRJ_MOUCHERON_H

#include "Machin.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

class Moucheron : public Machin
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	Moucheron(double position);
	virtual ~Moucheron();
	
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
	// le paramètre dépendant du temps
	double position;
	
};
#endif 
