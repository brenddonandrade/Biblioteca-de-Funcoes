#include <stdio.h>
#include <math.h>

#include "./Funcoes.h"

double funcao(double x){
    return (sin(x));
}

int main(){
    
    // Buttom intervall (a) and top intervall (b)
    double a =-1, b=2;
    double x0;

    // Iteractions 
    int i = 100;

    // Error
    double err = 0.001;

    // x0 = bissecao(funcao, a, b, &err, &i);

    x0 = regula_falsi(funcao, a, b, &err, &i);

    printf("\n\nRaiz: %.10lf\n\n", x0);

    
    // Number of iteractions
    int itr;

    
}