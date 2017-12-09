#include <stdio.h>
#include <stdlib.h>

#include "backtrack1.h"
#include "backtrack2.h"
#include "utils.h"

int main() {
  /*
  int tam = 5;
  int conjunto[tam];
  int solucion[tam];
  int suma = 31;

  conjunto[0] =  1;
  conjunto[1] =  9;
  conjunto[2] = 10;
  conjunto[3] = 12;
  conjunto[4] = 30;

  int solucion_final[tam];

  crear(solucion, tam);
  crear(solucion_final, tam);
  conj_rec(solucion, 0, tam, conjunto, suma, solucion_final);
  printf("SOLUCION FINAL: ");
  imprimir(solucion_final, tam);
  system("PAUSE");
  */
  int tam = 10;
  int solucion[tam];

  crear(solucion, tam);
  tab_rec(solucion, 0, tam);
  return 0;
}


