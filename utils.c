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

void imprimir(int arr[], int tam) {
  int i;
  printf("{");
  for (i = 0; i<tam; i++) {
    printf("%d", arr[i]);
    if (i < tam - 1) {
      printf(",");
    }
  }
  printf("}\n");
}


void crear(int arr[], int tam) {
  int i;

  for (i = 0; i<tam; i++) {
    arr[i] = -1;
  }
}

int _ordenar(const void* a, const void* b) {
  int int_a = * ( (int*) a );
  int int_b = * ( (int*) b );

  if ( int_a == int_b ) return 0;
  else if ( int_a < int_b ) return -1;
  else return 1;
}

void ordenar(int arr[], int tam) {
  qsort(arr, tam, sizeof(int), _ordenar);
}

int comparar(int _arr1[], int _arr2[], int tam) {
  int i, j;
  int comparacion = 0;
  int arr1[tam];
  int arr2[tam];

  copiar(_arr1, arr1, tam);
  copiar(_arr2, arr2, tam);

  for (i = 0; i<tam; i++) {
    for (j = 0; j<tam; j++) {
      if (arr1[i] == arr2[j]) {
        comparacion++;
        arr2[j] = -1;
        break;
      }
    }
  }
  return comparacion == tam; // Devuelve 1 si iguales, 0 si diferentes
}

int diferencia_absoluta(int _arr[], int tam) {
  int max = 0;
  int maxdiff = 0;
  int i;
  int arr[tam];

  copiar(_arr, arr, tam);
  ordenar(arr, tam);

  for (i = tam - 1; i >= 0; i--) {
    if (arr[i] != -1) {
      if (max < arr[i]) {
        max = arr[i];
      }
      int diff = abs(max - arr[i]);
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
