
#include<vector>
#include<iostream>
#include<tuple>
#include<fstream>

class Matrice{
    public:
        std::vector <double> matrice;
        int p;
        int q;
        Matrice(std::vector<double> v, int n, int k);
        Matrice(std::vector<double> v, int n);
        Matrice(int n);
        Matrice(int n, int k);
        double operator()(int i, int j);
        std::tuple<int,int> get_i_j(int k);
        Matrice operator+(Matrice m1);
        Matrice operator-(Matrice m1);
        Matrice operator*(Matrice m1);
        Matrice operator*(double lambda);
        void print_matrix();
        Matrice transpose();
        void write();
};
int get_k(int i, int j, int q);
Matrice operator*(double lambda, Matrice m1);
Matrice Mat_identite(int n);
