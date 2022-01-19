
#include <iostream>
#include "includes/euler.hpp"
#include <fstream>
#include "includes/resolution_syst.hpp"

int main(){
    
    

    const double dt1 = 0.005;
    const double dt2 = 0.0008;
    euler_explicite(dt2);
    euler_explicite_heterogene(dt2);
    euler_implicite_heterogene(dt1);
    euler_implicite(dt1);
    std::cout<<"Vous pouvez aller checker les différents résultats dans le notebook python: trace_temperature du dossier trace_python"<<std::endl;
    
    return EXIT_SUCCESS;

}
