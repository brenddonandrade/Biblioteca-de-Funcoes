#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "./Funcoes.h"

# define M_PI 3.14159265358979323846

double funcao(double x){
    return ((x*exp((-x)/3.0)) - 1);
}

double derivada(double x){
    return (exp(-(x/3.0))*(1 - ((pow(x, 2))/3.0)));
}

int main(int argc, char **argv){
    
    // Buttom intervall (a) and top intervall (b)
    int i, itr;
    double a, b, err, x0;
    
    a = atof(argv[1]);
    b = atof(argv[2]);


    // Iteractions  
    i = atoi(argv[3]);
    itr = i;

    // Error
    err = atof(argv[4]);

    

    
    // x0 = ponto_fixo(funcao, a, &err, &itr);


    x0 = newton(funcao, derivada, a , &err, &itr);

    printf("\n\nx0=%.10lf\n\n", x0);
    
    return 0;
}