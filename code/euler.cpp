#include "../includes/euler.hpp"


const int N = 10;
const double t0 = 0. ;
const double tf = 0.5 ;
const double dx = 1./N;

Matrice get_D(){
    std::vector<double> v(N);
    for(int i=0;i<N;i++){
        v[i] = 1;

    }
    return Matrice(v, 1, N);
}
Matrice get_K(const Matrice D){
    std::vector<double> v(N*N);
    v[get_k(0,0,N)] = -D(0,0)-D(0,1);
    v[get_k(0,1,N)] = D(0,0);
    v[get_k(N-1,N-2,N)] = D(0,N-1);
    v[get_k(N-1,N-1,N)] = -D(0,N-1);
    for(int i=1; i<N-1; i++){
        v[get_k(i,i-1,N)] = D(0,i);
        v[get_k(i,i,N)] = -D(0,i)-D(0,i+1);
        v[get_k(i,i+1,N)] = D(0,i+1);

    }
    return (1./dx)* Matrice(v,N);
}
Matrice get_T(){
    std::vector<double> v(N);
    for (int i=0; i<N; i++){
        v[i] = 0.5 + std::sin(2*M_PI*i/N) - 0.5*std::cos(2*M_PI*i/N);
    }
    return Matrice (v, N, 1);


}








Matrice euler_explicite(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D();
    Matrice K = get_K(D);
    double t = t0;
    T.write();
    while(t<tf){
        T = (I + dt*K)*T;
        t = t + dt;
        T.matrice[0] = 0;
        T.matrice[N-1] = 0;
        T.write();
    }
    return T;

}
Matrice euler_implicite(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D();
    Matrice K = get_K(D);
    double t = t0;
    T.write();
    while(t<tf){
        T = grad_conj(I + dt*K, T, T, 0.1);
        t = t + dt;
        T.matrice[0] = 0;
        T.matrice[N-1] = 0;
        T.write();
    }
    return T;

}