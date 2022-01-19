

#if !defined(MATRIXC)
#define MATRIXC
#include "../includes/Matrix.hpp"




Matrice::Matrice(std::vector<double> v, int n, int k): matrice(v),p(n),q(k){};
Matrice::Matrice(std::vector<double> v, int n): matrice(v),p(n),q(n){};
Matrice::Matrice( int n): matrice(std::vector<double> (n*n,0.0)),p(n),q(n){};
Matrice::Matrice( int n, int k) : matrice(std::vector<double> (n*k,0.0)),p(n),q(k){};
Matrice::Matrice(const Matrice& m) : matrice(m.matrice), p(m.p), q(m.q){};
Matrice::Matrice(std::tuple<int, int> dim) {
    auto [n, k] = dim;
    this->matrice = std::vector<double> (n*k,0.0);
    this->p = n;
    this->q = k;
};

double Matrice::operator()(int i, int j) const{
    return this->matrice[i*this->q +j];

}

std::tuple<int,int> Matrice::get_i_j(int k) const{
    return {k/this->q, k % this->q};
}

int get_k(int i ,int j, int q){
    return i*q +j;
}
Matrice Matrice::operator+(const Matrice& m1) const{
    if (m1.p != this->p || m1.q != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas+");
    }
    std::vector<double> m(m1.matrice.size());
    
    for (int k=0; k<m.size(); k++){
        m[k] = m1.matrice[k] + this->matrice[k];
    }
    
    return Matrice(m, m1.p, m1.q);
}
Matrice Matrice::operator-(const Matrice& m1) const{
    if (m1.p != this->p || m1.q != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas-");
    }
    std::vector<double> m(m1.matrice.size());
    for (int k=0; k<m.size(); k++){
        m[k] =  this->matrice[k] - m1.matrice[k];
    }
    return Matrice(m, m1.p, m1.q);
}
Matrice Matrice::operator*(double lambda) const{
    std::vector<double> m(this->matrice.size());
    for (int k=0; k<m.size(); k++){
        m[k] =  this->matrice[k] * lambda;
    }
    return Matrice(m, this->p, this->q);
}
Matrice operator*(double lambda, const Matrice& m1){
    auto [p,q] = m1.dim();
    Matrice m = Matrice(p,q);
    for(int i=0; i<p; i++){
        for(int j=0;j<q; j++){
            m(i,j) = lambda*m1(i,j);
        }
    }
    return m;
}
Matrice Matrice::operator*(const Matrice& m1) const{
    if (m1.p != this->q){
        throw std::invalid_argument("les dimensions ne correspondent pas");
    }
    Matrice m = Matrice(this->p, m1.q);
    for (int i=0; i< this->p; i++){
        for (int j=0; j<m1.q; j++){
            double mk = 0;
            for (int l=0; l<m1.p; l++){
                mk = mk + (*this)(i,l) * m1(l,j);

            }
            m(i,j) = mk;
        }
    }
    return m;
}
void Matrice::print_matrix() const{
    for (int i=0; i<this->p; i++){
        for (int j=0; j<this->q; j++){
            std::cout<< (*this)(i,j)<<" ";

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
Matrice Matrice::transpose() {
    if (this-> p!=1 && this ->q!=1){
        throw std::invalid_argument("cette fonction transposée n'est prévue que pour les matrices lignes ou colonnes");
        
    }
    return Matrice (this->matrice, this->q, this->p);

    
}


/* cette fonction écrit (en ligne) une matrice colonne dans un fichier texte dont on a donné le nom, sans écraser le contenu du fichier*/
void Matrice::write(std::string name) const{
    if ( this ->q!=1){
        throw std::invalid_argument("cette fonction ne prend en argument que des matrices colonnes");
    }
        
    std::string path = "trace_python/";
    std::ofstream temperature(path + name, std::ios::app);
    for (int i=0; i<this->p; i++){
        temperature<<this->matrice[i]<<" ";
    }
    temperature<<std::endl;
    temperature.close();
}




double& Matrice::operator()(int i, int j) {
    return this->matrice[get_k(i ,j, this->q)];

}

std::tuple<int, int> Matrice::dim() const{
    return {this->p, this->q};
}



#endif