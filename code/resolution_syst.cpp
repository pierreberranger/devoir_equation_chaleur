
#if !defined(GRADIENT)
#define GRADIENT
#include "../includes/resolution_syst.hpp"



Matrice grad_conj(Matrice A, Matrice B,  Matrice X0, double epsilon){
    Matrice X = X0;
    Matrice R = B - A*X;
    Matrice P = R;
    double norme_Rk = (R.transpose()*R)(0,0);
    while(norme_Rk>epsilon){
        double p = (P.transpose()*A*P)(0,0);
        double alpha = norme_Rk/p;
        X = X + alpha*P;
        R = R - alpha*A*P;
        double beta = (R.transpose()*R)(0,0)/ norme_Rk;
        double norme_Rk = (R.transpose()*R)(0,0);
        P = R + beta* P;
    }
    return X;
}
#endif