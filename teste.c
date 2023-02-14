#include <stdio.h>

#include "./Funcoes.h"

double funcao(double x){
    return (x*x*x);
}

int main(){
    
    // Buttom intervall (a) and top intervall (b)
    double a =-2, b=3;
    double x0;

    // Iteractions 
    int i = 100;

    // Error
    double err = 0.001;

    x0 = bissecao(funcao, a, b, &err, &i);

    printf("\n\nRaiz: %.10lf\n\n", x0);

    
    // Number of iteractions
    int itr;

    
}