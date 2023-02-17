#include <math.h>
#include <stdio.h>
#define L 3 // m
#define PI 3.1415
#define E 70e9    // Pa
#define I 52.9e-6 // m^4
#define W_0 15e3  // N/m
#define ERRO 1e-4 // erro aceito
#define Y 9e-3 // m
#define NMAX 100 // maximo de iteracoes


// Funcao da questao pedida
double funcao(double x) {

  double p1, p2, p3, p4, p5;

  // Particionando as equacoes
  p1 = (W_0 * L) / (3 * pow(PI, 4) * E * I);
  p2 = (48 * pow(L, 3) * cos(((PI * x) / (2 * L))));
  p3 = -(48 * pow(L, 3));
  p4 = (3 * pow(PI, 3) * L * pow(x, 2));
  p5 = -(pow(PI, 3) * pow(x, 3));

  return ((p1 * (p2 + p3 + p4 + p5)) - Y);
}

// Derivada da funcao para o Método de Newton
double derivada(double x) {
  double p1, p2, p3, p4;

  // Particionando as equacoes
  p1 = (W_0 * L) / (3 * pow(PI, 4) * E * I);
  p2 = -(PI * 24 * pow(L, 2) * sin((PI * x) / 2 * L));
  p3 = 6 * pow(PI, 3) * L * x;
  p4 = -(3 * pow(PI, 3) * pow(x, 2));

  return (p1 * (p2 + p3 + p4));

}

// a é o limite inferior e b o superior do intervalo onde esta localizada a solucao. 
// O uso do endereco da variavel "itr" e do "err" é pra, caso necessário, poder ser usado na main
double bissecao(double f(), double a, double b, int *itr, double *err) {
  double m, fm, tolerance, m_a;
  int n = 0, nmax = *itr;

  tolerance = *err;

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
    printf("%2d \t m=%10lfm\tf(m)= %.8lf \terr= %.2e\n", n, m, fm, *err);
  } while ((n < nmax) && (tolerance < *err));
  return m;
}

double regula_falsi(double f(), double a, double b, int *itr, double *err) {
  double x, fx, fa, fb, tolerance, x_a; // x_a é o x anterior
  int n = 0, nmax = *itr;

  tolerance = *err;

  printf("\n\nRegula Falsi:\n");
  do {
    fa = f(a);
    fb = f(b);

    
    x_a = x; // somente para o calculo do erro relativo

    x = ((a * fb) - (b * fa)) / (fb - fa);
    fx = f(x);

    if ((fa * fx) < 0) {
      b = x;
    } else {
      a = x;
    }
    n++;
    *err = fabs(x - x_a) / fabs(x);
    printf("%2d \t x=%10lfm\tf(x))= %.8lf \terr= %.2e\n", n, x, fx, *err);
  } while ((n < nmax) && (tolerance < *err));

  return x;
}

double newton(double f(), double fl(), double a, int *itr, double *err) {
  double x , fx, x_a, tolerance;
  int nmax = *itr, n = 0;
  tolerance = *err;

  x_a = a;
  printf("\n\nNewton:\n");
  
  do {
    x = x_a - (f(x_a) / fl(x_a));
    fx = f(x);
    n++;
    *err = fabs(x - x_a) / fabs(x);
    x_a = x;
    printf("%2d \t x=%10lfm\tf(x)= %.8lf \terr= %.2e\n", n, x, fx, *err);
  } while ((n < nmax) && (tolerance < *err));

  return x;
}

double secante(double f(), double a, double b, int *itr, double *err) {
  double fx, x, x_1, x_2, tolerance;
  int nmax = *itr, n = 0;
  tolerance = *err;

  x_1 = a;
  x_2 = b;

  printf("\n\nSecante:\n");
  
  do {
    x = x_2 - ((f(x_2)*(x_1 - x_2))/(f(x_1)-f(x_2)));
    fx = f(x);
    n++;
    *err = fabs(x - x_2) / fabs(x);
    x_2 = x;
    printf("%2d \t x=%10lfm\tf(x)= %.8lf \terr= %.2e\n", n, x, fx, *err);
  }while( (n<nmax) && (tolerance < *err));
    
  return x;
}

int main(void) {
  int itr = NMAX;
  double err = ERRO;

  // os metodos poderiam ser usados como void pois nao utilizo os valores obtidos. 
  bissecao(funcao, 1, 2, &itr, &err);
  err = ERRO;
  regula_falsi(funcao, 1, 2, &itr, &err);
  err = ERRO;  
  newton(funcao, derivada, 1, &itr, &err);
  err = ERRO;  
  secante(funcao, 1, 2, &itr, &err);

  return 0;
}