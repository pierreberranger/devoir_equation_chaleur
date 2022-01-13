#include "../includes/euler.hpp"



const int N = 20;
const double t0 = 0. ;
const double tf = 0.5 ;
const double dx = 1./N;

void clean(std::string name){
    std::string path = "trace_python/";
    std::ofstream file(path + name);
    file.close();
}


Matrice get_D(){
    std::vector<double> v(N);
    for(int i=0;i<N;i++){
        v[i] = 1;

    }
    return Matrice(v, 1, N);
}
Matrice get_D_heterogene(){
    std::vector<double> v(N);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0.5,1.5);

    for(int i=0;i<N;i++){
        v[i] = distr(eng);

    }
    return Matrice(v, 1, N);
}

Matrice get_K( Matrice D){
    Matrice K = Matrice(N,N);
    /* Les CI sont prises en compte directement dans euler pour garder une matrice symétrique*/
    K(0,0) = -D(0,0)-D(0,1);
    K(0,1) = D(0,1);
    K(N-1, N-2) = D(0, N-1);
    K(N-1, N-1) = -D(0, N-1);

    for(int i=1; i<N-1; i++){
        K(i,i-1) = D(0,i);
        K(i,i) = -D(0,i)-D(0,i+1);
        K(i, i+1) = D(0,i+1);

    }
    return (1./(dx*dx))* K;
}
Matrice get_T(){
    std::vector<double> v(N);
    for (int i=0; i<N; i++){
        v[i] = 0.5 + std::sin(2*M_PI*i/(N-1)) - 0.5*std::cos(2*M_PI*i/(N-1));
    }
    return Matrice (v, N, 1);


}








Matrice euler_explicite(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D();
    Matrice K = get_K(D);
    double t = t0;
    std::string name = "temperature_explicite_homogene.txt";
    clean(name);
    T.write(name);
    while(t<tf){
        T = (I + dt*K)*T;
        t = t + dt;
        T(0,0) = 0.;
        T(N-1,0) = 0.;
        T.write(name);
    }
    return T;

}
Matrice euler_implicite(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D();
    Matrice K = get_K(D);
    double t = t0;
    std::string name = "temperature_implicite_homogene.txt";
    clean(name);
    T.write(name);
    while(t<tf){
        T = grad_conj(I - dt*K, T, 0.001);
        t = t + dt;
        T(0,0) = 0.;
        T(N-1,0) = 0.;
        T.write(name);
    }
    return T;
}
Matrice euler_implicite_heterogene(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D_heterogene();
    Matrice K = get_K(D);
    double t = t0;
    std::string name = "temperature_implicite_heterogene.txt";
    clean(name);
    T.write(name);
    while(t<tf){
        T = resolution_gauss(I -dt*K, T);
        t = t + dt;
        T(0,0) = 0.;
        T(N-1,0) = 0.;
        T.write(name);
    }
    return T;

}

Matrice euler_explicite_heterogene(double dt){
    Matrice T = get_T();
    Matrice I = Mat_identite(N);
    Matrice D = get_D_heterogene();
    Matrice K = get_K(D);
    double t = t0;
    std::string name = "temperature_explicite_heterogene.txt";
    clean(name);
    T.write(name);
    while(t<tf){
        T = (I + dt*K)*T;
        t = t + dt;
        T(0,0) = 0.;
        T(N-1,0) = 0.;
        T.write(name);
    }
    return T;
}
