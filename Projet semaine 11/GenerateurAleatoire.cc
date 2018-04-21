#include "GenerateurAleatoire.h"

using namespace std;

GenerateurAleatoire::GenerateurAleatoire()
 : generateur(std::random_device()())
{}
	
GenerateurAleatoire::GenerateurAleatoire(unsigned int graine)
 : generateur(graine)
{}


double GenerateurAleatoire::uniforme(double min, double max) {
		return distribution_uniforme(generateur, std::uniform_real_distribution<double>::param_type{min, max});
	}
