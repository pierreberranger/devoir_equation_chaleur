
#if !defined(GRADIENT)
#define GRADIENT
#include "../includes/resolution_syst.hpp"




Matrice grad_conj(Matrice A, Matrice B, double epsilon){
    Matrice X = Matrice(B.dim());
    Matrice R = B - A*X;
    Matrice P = R;
    double norme_Rk = (R.transpose()*R)(0,0);
    while(norme_Rk>epsilon){
        double p = (P.transpose()*A*P)(0,0);
        double alpha = norme_Rk/p;
        X = X + alpha*P;
        R = R - alpha*A*P;
        double beta = (R.transpose()*R)(0,0)/ norme_Rk;
        norme_Rk = (R.transpose()*R)(0,0);
        P = R + beta* P;
    }
    return X;
}

void transvection(Matrice& A, int i, int j, double alpha){
    auto [n,p] = A.dim();
    for (int k=0; k<p; k++){
        A(i,k) = A(i,k) + alpha*A(j,k);
    }
}

void echange(Matrice& A, int i, int j){
    auto [n,p] = A.dim();
    for (int k=0; k<p; k++){
        double x = A(i,k);
        A(i,k) = A(j,k);
        A(j,k) = x;
    }
}

int max(int r, Matrice A){
    auto [n,p] = A.dim();
    double max = std::abs(A(r,r));
    int indice = r;
    for (int k=r+1; k<n;k++){
        if (A(k,r)>max){
            max = std::abs(A(k,r));
            indice = k;
        }
    }
    return indice;
}
void dilatation(Matrice& A, int i, double lambda){
    auto [n,p] = A.dim();
    for (int k=0; k<p; k++){
        A(i,k) = lambda*A(i,k);
    }
}

void gauss(Matrice& A, Matrice& B){

    auto [n,p] = A.dim();
    for (int k=0;k<n; k++){
        int l = max(k, A);
        echange(A,k,l);
        echange(B,k,l);
        if (A(k,l)!=0.){
            dilatation(B, k, 1./A(k,l));
            dilatation(A, k, 1./A(k,l));
            for (int m=0; m<n; m++){
                if (m!=k){
                    transvection(B, m, k, -A(m,k));
                    transvection(A, m, k, -A(m,k));
                    
                }

            }
        }
    }
}
Matrice resolution_gauss(const Matrice& A, const Matrice& B){
    Matrice A_g = A;
    Matrice B_g = B;
    
    gauss(A_g,B_g);
    
    return B_g;
    
}


    





#endif



