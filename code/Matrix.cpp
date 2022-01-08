#include<vector>
#include<iostream>
#include<stdexcept>

#if !defined(MATRIX)
#define MATRIX
#include "/mnt/c/Users/pierr/info/devoir_equation_chaleur/includes/Matrix.hpp"



Matrice::Matrice(std::vector<double> v, int n, int k): matrice(v),p(n),q(k){};
Matrice::Matrice(std::vector<double> v, int n): matrice(v),p(n),q(n){};
Matrice::Matrice( int n): matrice(std::vector<double> (n*n,0.0)),p(n),q(n){};
Matrice::Matrice( int n, int k) : matrice(std::vector<double> (n*k,0.0)),p(n),q(k){};


double Matrice::operator()(int i, int j){
    return this->matrice[i*this->q +j];

}

std::tuple<int,int> Matrice::get_i_j(int k){
    return {k/this->q, k % this->q};
}

int get_k(int i ,int j, int q){
    return i*q +j;
}
Matrice Matrice::operator+(Matrice m1){
    if (m1.p != this->p || m1.q != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas+");
    }
    std::vector<double> m(m1.matrice.size());
    
    for (int k=0; k<m.size(); k++){
        m[k] = m1.matrice[k] + this->matrice[k];
    }
    
    return Matrice(m, m1.p, m1.q);
}
Matrice Matrice::operator-(Matrice m1){
    if (m1.p != this->p || m1.q != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas-");
    }
    std::vector<double> m(m1.matrice.size());
    for (int k=0; k<m.size(); k++){
        m[k] =  this->matrice[k] - m1.matrice[k];
    }
    return Matrice(m, m1.p, m1.q);
}
Matrice Matrice::operator*(double lambda){
    std::vector<double> m(this->matrice.size());
    for (int k=0; k<m.size(); k++){
        m[k] =  this->matrice[k] * lambda;
    }
    return Matrice(m, this->p, this->q);
}
Matrice operator*(double lambda, Matrice m1){
    std::vector<double> m(m1.matrice.size());
    for (int k=0; k<m.size(); k++){
        m[k] =  m1.matrice[k] * lambda;
    }
    return Matrice(m, m1.p, m1.q);
}
Matrice Matrice::operator*(Matrice m1){
    if (m1.p != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas");
    }
    std::vector<double> m(m1.q * this->p);
    for (int i=0; i< this->p; i++){
        for (int j=0; j<m1.q; j++){
            double mk = 0;
            for (int l=0; l<m1.p; l++){
                mk = mk + this->matrice[get_k(i,l, this->q)] * m1(l,j);

            }
        int k = get_k(i, j, m1.q);
        m[k] =  mk;
        }
    }
    return Matrice(m, this->p, m1.q);
}
void Matrice::print_matrix(){
    for (int i=0; i<this->p; i++){
        for (int j=0; j<this->q; j++){
            std::cout<< this->matrice[get_k(i, j, this->q)]<<" ";

        }
        std::cout<<std::endl;
    }
}
Matrice Mat_identite(int n){
    std::vector<double> v(n*n);
    for(int i=0; i<n; i++){
        v[i*n+i] = 1.;
    }
    return Matrice(v, n, n);
}
Matrice Matrice::transpose(){
    if (this-> p!=1 && this ->q!=1){
        throw std::invalid_argument("cette fonction transposée n'est prévue que pour les matrices lignes ou colonnes");
        
    }
    return Matrice (this->matrice, this->q, this->p);

    
}

void Matrice::write(){
    std::ofstream temperature("temperature.txt", std::ios::app);
    for (int i=0; i<this->p; i++){
        temperature<<this->matrice[i]<<" ";
    }
    temperature<<std::endl;
}
#endif