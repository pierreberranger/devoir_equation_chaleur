#include<iostream>
#include<vector>
#include<cmath>
#include <random>
#include <string>


#include "../includes/Matrix.hpp"
#include "../includes/resolution_syst.hpp"


Matrice euler_explicite(double dt);
Matrice get_D();
Matrice get_K(Matrice D);
Matrice get_T();
Matrice get_D_heterogene();
Matrice euler_implicite(double dt);
Matrice euler_implicite_heterogene(double dt);
Matrice euler_explicite_heterogene(double dt);
void clean(std::string name);
