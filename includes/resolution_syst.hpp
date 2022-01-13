
#include <cmath>
# include "../includes/Matrix.hpp"

Matrice grad_conj(Matrice A, Matrice B, double epsilon);
void transvection(Matrice& A, int i, int j, double alpha);
void echange(Matrice& A, int i, int j);
int max(int r);
void gauss(Matrice& A, Matrice& B);
void dilatation(Matrice& A, int i, double lambda);
Matrice resolution_gauss(const Matrice& A,const  Matrice& B);
