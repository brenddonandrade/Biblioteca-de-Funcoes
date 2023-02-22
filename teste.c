#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "./Funcoes.h"


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

    
    
    return 0;
}