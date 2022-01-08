
#include <iostream>
#include "euler.cpp"
#include <fstream>
#include "resolution_syst.cpp"

int main(){
    std::vector<double> m1{1, 2, 3, 4};
    std::vector<double> m2{1, 2, 3, 3, 4, 5};
    Matrice a = Matrice(m1,3,2);
    Matrice b = Matrice(m2,2,3);
    Matrice d = Matrice(1, 2);
    Matrice c = a * b ;
    
    Matrice D = get_D();
    Matrice K = get_K(D);
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    
    /*T = euler_explicite(0.01);*/
    double norme_Rk = (T.transpose()*T)(0,0);
    std::cout<<norme_Rk;


    Matrice X = grad_conj(I, 0.01*T, T, 0.1 );
    X.print_matrix();
    T.print_matrix();


    



    
    




    
    




    return EXIT_SUCCESS;

}
