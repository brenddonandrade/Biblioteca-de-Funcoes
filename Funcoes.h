#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


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
  double m, fm, tolerance, m_a;
  int n = 0, nmax = *itr;

  m_a = (b-a)/2;

  tolerance = *err;
  if(f(a)* f(b) > 0){
    printf("\n\nIntervalo nao recomendado. Encontre um que a funcao altere o sinal nos limites.\n\n");
    return 0;
  }
  printf("\n\nBissecao:\n");

  do {
    if (n > 0)
      m_a = m;
    m = (a + b) / 2;
    fm = f(m);
    if (fm == 0)
      break;
    if (f(a) * fm < 0)
      b = m;
    else
      a = m;

    n++;
    *err = fabs(m - m_a) / fabs(m); // usa como estimativa o erro relativo
    printf("%2d    a=%.8lf    b=%.2lf    m=%10lfm    f(m)=%.10lf    err=%.2e\n", n, a, b, m, fm, *err);
  } while ((n < nmax) && (tolerance < *err) && (fabs(fm) > 1e-4));
  return m;
}


double regula_falsi(double f(), double a, double b, double *err , int *itr) {
  double m, fm, fa, fb, tolerance, m_a; // x_a é o x anterior
  int n = 0, nmax = *itr;

  tolerance = *err;

  if(f(a)* f(b) > 0){
    printf("\n\nIntervalo nao recomendado. Encontre um que a funcao altere o sinal nos limites.\n\n");
    return 0;
  }
  
  printf("\n\nRegula Falsi:\n");
  do {
    fa = f(a);
    fb = f(b);

    
    m_a = m; // somente para o calculo do erro relativo

    m = ((a * fb) - (b * fa)) / (fb - fa);
    fm = f(m);

    if ((fa * fm) < 0) {
      b = m;
    } else {
      a = m;
    }
    n++;
    *err = fabs(m - m_a) / fabs(m);
    printf("%2d    a=%.10lf    b=%.10lf    m=%.10lf    f(m)=%.8lf    err=%.2e\n", n, a, b, m, fm, *err);
  } while ((n < nmax) && (tolerance < *err) && (fabs(fm) > 1e-4));

  return m;
}

double ponto_fixo(double f(), double x0, double *err, int *itr){
  double x1, tolerance;
  int nmax= *itr , n=0;

  tolerance = *err;

  do {
    x1 = f(x0);
    *err = fabs(x1-x0);
    n++;
    
    printf("%2d    x0=%.10lf    x1=%.10lf    err=%.2e\n", n, x0, x1, *err);
    x0 = x1;
  }while((n < nmax) && (*err > tolerance));

  
  *itr = n;
  return x1;
}

#endif
