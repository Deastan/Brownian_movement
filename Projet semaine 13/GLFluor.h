#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include <vector>
#include <deque>
#include "Vecteur.h"
#include "Particule.h"


class GLFluor : public Particule
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	GLFluor(Vecteur position, Vecteur vitesse);
	GLFluor(Enceinte const& enceinte, GenerateurAleatoire& tirage, double temperature);
	virtual ~GLFluor();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
	virtual void evolue(double dt);
	virtual void dessine() const;
	void enregistrerCoordonnee();
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	GLUquadric* sphere;
	std::deque<Vecteur*> dequePositions;
	// le paramètre dépendant du temps
	//double position;
};

