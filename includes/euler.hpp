#include<iostream>
#include<vector>
#include<cmath>
#include <random>
#include <string>


#include "../includes/Matrix.hpp"
#include "../includes/resolution_syst.hpp"


Matrice euler_explicite(const double& dt);
Matrice get_D();
Matrice get_K(Matrice D);
Matrice get_T();
Matrice get_D_heterogene();
Matrice euler_implicite(const double& dt);
Matrice euler_implicite_heterogene(const double& dt);
Matrice euler_explicite_heterogene(const double& dt);
void clean(std::string name);
