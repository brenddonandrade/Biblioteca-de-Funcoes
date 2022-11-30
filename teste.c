#include <stdio.h>

#include "./Funcoes.h"

double funcao(double x){
    return (x*x*x);
}

int main(){

    double a, b, erro, *perro, raiz;
    int *itr, i;

    a =-1;
    b = 2;

    erro = 1e-4;
    i = 100;

    perro = &erro;
    itr = &i;

    raiz = bissecao(funcao, a, b, perro, itr);    

    printf("\n\nRaiz= %.10lf\n\n", raiz);

    return 0;
}