#ifndef PRJ_GENERATEURALEATOIRE_H
#define PRJ_GENERATEURALEATOIRE_H

#include <random>

class GenerateurAleatoire {
	
	public:
	GenerateurAleatoire();
	GenerateurAleatoire(unsigned int graine);

	int uniforme_entier(int min, int max);
	double uniforme_reel(double min, double max);
	double gaussienne(double moyenne, double ecart_type);

private:
  std::default_random_engine generateur;
  std::uniform_int_distribution<int> distribution_uniforme_entier;
  std::uniform_real_distribution<double> distribution_uniforme_reel;
  std::normal_distribution<double> distribution_gaussienne;
  
};

#endif // PRJ_GENERATEURALEATOIRE_H
