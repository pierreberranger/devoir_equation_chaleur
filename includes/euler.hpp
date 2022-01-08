#include<iostream>
#include<vector>
#include<cmath>
#include "../code/Matrix.cpp"
#include "../code/resolution_syst.cpp"

Matrice euler_explicite(double dt);
Matrice get_D();
Matrice get_K();
Matrice get_T();