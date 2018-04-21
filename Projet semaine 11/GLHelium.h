#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "Particule.h"

class GLHelium : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	GLHelium(Vecteur position, Vecteur vitesse);
	virtual ~GLHelium();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	//void evolue(double dt);
	virtual void dessine() const;
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;
	// le paramètre dépendant du temps
	//double position;
};

