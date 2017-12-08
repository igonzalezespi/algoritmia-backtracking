#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtracking.h"
#include "utils.h"

void iniciarValores(int valores[], int solucion[], int tam, int conjunto[]) {
  int i, j, k;
  crear(valores, tam);

  for (i = 0; i<tam; i++) {
    int disponible = 1;
    for (j = 0; j<tam && disponible == 1; j++) {
      if (conjunto[i] == solucion[j]) {
        disponible = 0;
      }
    }
    if (disponible == 1) {
      for (k = 0; k<tam; k++) {
        if (valores[k] == 0) {
          valores[k] = conjunto[i];
          break;
        }
      }
    }
  }
}

int valido(int solucion[], int tam, int sumaTotal) {
  int i;
  int sumaParcial = 0;

  for (i = 0; i<tam; i++) {
    sumaParcial += solucion[i];
    if (sumaParcial > sumaTotal) {
      return 0;
    }
  }
  return 1;
}

int esSolucion(int solucion[], int tam, int sumaTotal, int solucionFinal[]) {
  int i;
  int sumaParcial = 0;

  if (comparar(solucion, solucionFinal, tam) == 1) {
    return 0;
  }

  for (i = 0; i<tam; i++) {
    sumaParcial += solucion[i];
  }
  if (sumaParcial == sumaTotal) {
    return 1;
  }
  return 0;
}

void procesarSolucion(int solucion[], int solucionFinal[], int tam) {
  int diffActual = diferenciaAbsoluta(solucion, tam);
  int diffFinal = diferenciaAbsoluta(solucionFinal, tam);
  if (diffActual < diffFinal || solucionFinal[0] == 0) {
    copiar(solucion, solucionFinal, tam);
  }
}

void conjuntosRec(int solucion[], int etapa, int tam, int conjunto[], int suma, int solucionFinal[]) {
  if (etapa >= tam)  return;

  int valores [tam];
  iniciarValores(valores, solucion, tam, conjunto);

  int i = 0;
  do {
    solucion[etapa] = valores[i];
    if (valido(solucion, tam, suma)) {
      if (esSolucion(solucion, tam, suma, solucionFinal)) {
        procesarSolucion(solucion, solucionFinal, tam);
      } else {
        conjuntosRec(solucion,etapa+1, tam, conjunto, suma, solucionFinal);
      }
    }
    i++;
  } while(i < tam && valores[i] != 0);
  solucion[etapa]=0;
}

