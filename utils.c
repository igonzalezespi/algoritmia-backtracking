#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void cls() {
  system("cls");
}

void copiar(int src[], int dst[], int tam) {
  int i;
  for (i = 0; i<tam; i++) {
    dst[i] = src[i];
  }
}

void imprimir(int conjunto[], int tam) {
  int i;
  printf("{");
  for (i = 0; i<tam; i++) {
    printf("%d", conjunto[i]);
    if (i < tam - 1) {
      printf(",");
    }
  }
  printf("}\n");
}


void crear(int conjunto[], int tam) {
  int i;

  for (i = 0; i<tam; i++) {
    conjunto[i] = -1;
  }
}

int _ordenar(const void* a, const void* b) {
  int int_a = * ( (int*) a );
  int int_b = * ( (int*) b );

  if ( int_a == int_b ) return 0;
  else if ( int_a < int_b ) return -1;
  else return 1;
}

void ordenar(int conjunto[], int tam) {
  qsort(conjunto, tam, sizeof(int), _ordenar);
}

int comparar(int _conjunto1[], int _conjunto2[], int tam) {
  int i, j;
  int comparacion = 0;
  int conjunto1[tam];
  int conjunto2[tam];

  copiar(_conjunto1, conjunto1, tam);
  copiar(_conjunto2, conjunto2, tam);

  for (i = 0; i<tam; i++) {
    for (j = 0; j<tam; j++) {
      if (conjunto1[i] == conjunto2[j]) {
        comparacion++;
        conjunto2[j] = -1;
        break;
      }
    }
  }
  return comparacion == tam; // Devuelve 1 si iguales, 0 si diferentes
}

int diferencia_absoluta(int _conjunto[], int tam) {
  int max = 0;
  int maxdiff = 0;
  int i;
  int conjunto[tam];

  copiar(_conjunto, conjunto, tam);
  ordenar(conjunto, tam);

  for (i = tam - 1; i >= 0; i--) {
    if (conjunto[i] != -1) {
      if (max < conjunto[i]) {
        max = conjunto[i];
      }
      int diff = abs(max - conjunto[i]);
      if (maxdiff < diff) {
        maxdiff = diff;
      }
    }
  }

  return maxdiff;
}

int int_concat(int a, int b) {
  int pow = 10;
  while(b >= pow) {
    pow *= 10;
  }
  return a * pow + b;
}
