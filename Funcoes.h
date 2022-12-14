#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <math.h>

//  px e py sao os ponteiros que vao armazenar os pontos;
void metodo_de_euler_explicito(double x1, double y1, double *px, double *py) {
  double x2, y2;

  x2 = x1 + H;
  *px = x2;

  y2 = y1 + derivada(x1, y1);
  *py = y2;

  return;
}

double bissecao(double f(), double a, double b, double *err, int *itr) {
  double m, fm, tolerance, m_a;
  int n, nmax;

  nmax = *itr;
  tolerance = *err;

  n=0;

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
    else if( f(b) * fm < 0){
      a = m;
    } else {
        printf("\nA raiz não pertence a esse intervalo.\n\n");
        m = NAN;
        break;
    }

    n++;
    *err = fabs(m - m_a) / fabs(m); // usa como estimativa o erro relativo
    printf("%2d\ta=%.10lf \tb=%.10lf\tm=%.10lfm\tf(m)= %.8lf\terr= %.2e\n", n, a, b, m, fm, *err);
  } while ((n < nmax) && (tolerance < *err));
  *itr = n;
  return m;
}


#endif
