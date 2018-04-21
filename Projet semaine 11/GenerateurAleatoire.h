#ifndef PRJ_GENERATEURALEATOIRE_H
#define PRJ_GENERATEURALEATOIRE_H

#include <random>

class GenerateurAleatoire {
	
	public:
	GenerateurAleatoire();
	GenerateurAleatoire(unsigned int graine);

	double uniforme(double min, double max);
	
	/*  double gaussienne(double mu, double sigma) {
			return distribution_gaussienne(generateur, std::normal_distribution<double>::param_type{mu, sigma});
		}
    */  ///pour la distibution gaussienne des vitesses au dbt;
    

private:
  std::default_random_engine              generateur            ;
  std::uniform_real_distribution<double>  distribution_uniforme ;
  
  //std::normal_distribution<double> distribution_gaussienne;
  
};

#endif // PRJ_GENERATEURALEATOIRE_H
