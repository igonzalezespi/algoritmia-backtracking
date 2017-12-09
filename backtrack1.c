#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtrack1.h"
#include "utils.h"

void conj_iniciar_valores(int valores[], int solucion[], int tam, int conjunto[]) {
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
        if (valores[k] == -1) {
          valores[k] = conjunto[i];
          break;
        }
      }
    }
  }
}

int conj_valido(int solucion[], int tam, int suma_total) {
  int i;
  int suma_parcial = 0;

  for (i = 0; i<tam; i++) {
    if (solucion[i] != -1) {
      suma_parcial += solucion[i];
      if (suma_parcial > suma_total) {
        return 0;
      }
    }
  }
  return 1;
}

int conj_es_solucion(int solucion[], int tam, int suma_total, int solucion_final[]) {
  int i;
  int suma_parcial = 0;

  if (comparar(solucion, solucion_final, tam) == 1) {
    return 0;
  }

  for (i = 0; i<tam; i++) {
    if (solucion[i] != -1) {
      suma_parcial += solucion[i];
    }
  }
  if (suma_parcial == suma_total) {
    return 1;
  }
  return 0;
}

void conj_procesar_solucion(int solucion[], int solucion_final[], int tam) {
  int diff_actual = diferencia_absoluta(solucion, tam);
  int diff_final = diferencia_absoluta(solucion_final, tam);
  if (diff_actual < diff_final || solucion_final[0] == -1) {
    copiar(solucion, solucion_final, tam);
  }
}

void conj_rec(int solucion[], int etapa, int tam, int conjunto[], int suma, int solucion_final[]) {
  if (etapa >= tam)  return;

  int valores[tam];
  conj_iniciar_valores(valores, solucion, tam, conjunto);

  int i = 0;
  do {
    solucion[etapa] = valores[i];
    if (conj_valido(solucion, tam, suma)) {
      if (conj_es_solucion(solucion, tam, suma, solucion_final)) {
        conj_procesar_solucion(solucion, solucion_final, tam);
      } else {
        conj_rec(solucion,etapa+1, tam, conjunto, suma, solucion_final);
      }
    }
    i++;
  } while(i < tam && valores[i] != -1);
  solucion[etapa]=-1;
}

