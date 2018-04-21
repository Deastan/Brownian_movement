#include "GenerateurAleatoire.h"

using namespace std;

GenerateurAleatoire::GenerateurAleatoire()
 : generateur(std::random_device()())
{}
	
GenerateurAleatoire::GenerateurAleatoire(unsigned int graine)
 : generateur(graine)
{}

int GenerateurAleatoire::uniforme_entier(int min, int max) {
	return distribution_uniforme_entier(generateur, std::uniform_int_distribution<int>::param_type{min, max});
}

double GenerateurAleatoire::uniforme_reel(double min, double max) {
	return distribution_uniforme_reel(generateur, std::uniform_real_distribution<double>::param_type{min, max});
}

double GenerateurAleatoire::gaussienne(double moyenne, double ecart_type) {
    return distribution_gaussienne(generateur, std::normal_distribution<double>::param_type{moyenne, ecart_type});
}
