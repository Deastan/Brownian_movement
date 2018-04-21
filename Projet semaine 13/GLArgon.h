#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "Particule.h"

class GLArgon : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	GLArgon(Vecteur position, Vecteur vitesse);
	GLArgon(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature);
	virtual ~GLArgon();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	virtual void evolue(double dt);
	virtual void dessine() const;
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;

};

