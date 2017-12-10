#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// Limpia la pantalla
void cls() {
  system("cls");
}

// Copia un array por valor (no por referencia)
void copiar(int src[], int dst[], int tam) {
  int i;
  for (i = 0; i<tam; i++) {
    dst[i] = src[i];
  }
}

// Imprime un array de números por pantalla
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

// Inicializa un array
void crear(int arr[], int tam) {
  int i;

  for (i = 0; i<tam; i++) {
    arr[i] = -1;
  }
}

// Función callback para: ordenar()
int _ordenar(const void* a, const void* b) {
  int int_a = * ( (int*) a );
  int int_b = * ( (int*) b );

  if ( int_a == int_b ) return 0;
  else if ( int_a < int_b ) return -1;
  else return 1;
}

// Ordena un array de números ascendentemente
void ordenar(int arr[], int tam) {
  qsort(arr, tam, sizeof(int), _ordenar);
}

// Indica si dos arrays son iguales aunque estén desordenados
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

// Calcula la diferencia absoluta de un array de enteros
int diferencia_absoluta(int _arr[], int tam) {
  int i;
  int arr[tam];
  // Copiamos el array en uno temporal
  copiar(_arr, arr, tam);
  // Lo ordenamos ascendentemente
  ordenar(arr, tam);

  /*
    Al estar ordenados ya sabemos el mayor
    El valor menor, para no contar los -1 recorremos desde el principio hasta encontrar el primero
    Los restamos de forma que no salga negativo (mayor - menor) y lo devolvemos
  */
  for (i = 0; i<tam; i++) {
    if (arr[i] >= 0) {
      return arr[tam - 1] - arr[i];
    }
  }
  return 0;
}

// Concatena enteros como si fueran cadenas de caracteres
int int_concat(int a, int b) {
  int pow = 10;
  while(b >= pow) {
    pow *= 10;
  }
  return a * pow + b;
}

// Pide un entero por pantalla y lo devuelve
int dame_int() {
  int seleccion;
  scanf(" %d", &seleccion); // Se deja un espacio para no leer espacios
  return seleccion;
}
