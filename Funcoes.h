#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <math.h>


// Tamanhos dos tipos da maquina
void size_types(){
  printf("\n=============== Types ================\n");
  printf("char          %2d bytes \n", sizeof(char));
  printf("int           %2d bytes \n", sizeof(int));
  printf("unsigned int  %2d bytes \n", sizeof(unsigned int));
  printf("long int      %2d bytes \n", sizeof(long int));
  printf("float         %2d bytes \n", sizeof(float));
  printf("double        %2d bytes \n", sizeof(double));
  printf("long double   %2d bytes \n", sizeof(long double));
  printf("======================================\n\n");

}


double bissecao(double f(), double a, double b, double *err, int *itr) {
  double m, fm, tolerance;
  int n, nmax;

  nmax = *itr;
  tolerance = *err;

  n=0;

  printf("\n\nBissecao:\n");

  do {
    
    m = (a + b) / 2;
    fm = f(m);
    if(fm == 0) break;
    if(f(a) *f(m) < 0)
      b = m;
    else
      a = m;

    n++;
    *err = b-a;
    
    printf("%2d\ta=%10lf \tb=%.10lf\tm=%.10lf\tf(m)= %.8lf\terr= %.2e\n", n, a, b, m, fm, *err);
  } while ((n < nmax) && (tolerance < *err));
  *itr = n;
  return m;
}




#endif
