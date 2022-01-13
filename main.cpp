
#include <iostream>
#include "includes/euler.hpp"
#include <fstream>
#include "includes/resolution_syst.hpp"

int main(){
    /*std::vector<double> m1{1, 2, 3, 4};
    std::vector<double> m2{1, 2, 3, 3, 4, 5};
    Matrice a = Matrice(m1,3,2);
    Matrice b = Matrice(m2,2,3);
    Matrice d = Matrice(1, 2);
    Matrice c = a * b ;
    
    Matrice D = get_D();
    Matrice K = get_K(D);
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    
    Matrice S = resolution_gauss(K,T);
    Matrice C= K*S;
    */
    double dt1 = 0.005;
    double dt2 = 0.0008;
    euler_explicite(dt2);
    euler_explicite_heterogene(dt2);
    euler_implicite_heterogene(dt1);
    euler_implicite(dt1);
    std::cout<<"Vous pouvez aller checker les différents résultats dans le notebook python: trace_temperature du dossier trace_python"<<std::endl;

    
    
    
    /*K*T.print_matrix();
    
    Matrice S = resolution_gauss(K,T);
    S.print_matrix();
    std::cout<<std::endl;
    T.print_matrix();
    (K*T).print_matrix();*/
    
    
    /*T = euler_implicite(0.1);*/
    

    
    /*double norme_Rk = (T.transpose()*T)(0,0);
    std::cout<<norme_Rk;*/


    /*Matrice X = grad_conj(I, T, T, 0.1 );
    X.print_matrix();
    T.print_matrix();*/


    



    
    




    
    




    return EXIT_SUCCESS;

}
