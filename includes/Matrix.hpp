#if !defined(MATRIX)
#define MATRIX
#include<vector>
#include<iostream>
#include<tuple>
#include<fstream>
#include<stdexcept>
#include <string>

class Matrice{
    private:
        std::vector <double> matrice;
        int p;
        int q;

    public:
        Matrice(std::vector<double> v, int n, int k);
        Matrice(std::vector<double> v, int n);
        Matrice(int n);
        Matrice(int n, int k);
        Matrice(const Matrice& m);
        Matrice(std::tuple<int, int> dim);
        double operator()(int i, int j) const;
        std::tuple<int,int> get_i_j(int k) const;
        Matrice operator+(const Matrice& m1) const;
        Matrice operator-(const Matrice& m1) const;
        Matrice operator*(const Matrice& m1) const;
        Matrice operator*(double lambda) const;
        void print_matrix() const;
        Matrice transpose();
        void write(std::string name) const;
        std::tuple<int, int> dim() const;
        double& operator()(int i, int j) ;
};
int get_k(int i, int j, int q);
Matrice operator*(double lambda, const Matrice& m1) ;
Matrice Mat_identite(int n);
#endif