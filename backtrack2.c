#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtrack1.h"
#include "utils.h"

char letras[11] = "HARYPOTELS";

void tab_iniciar_valores(int valores[], int solucion[], int tam) {
  int i, j, k;
  crear(valores, tam);

  for (i = 0; i<tam; i++) {
    int disponible = 1;
    for (j = 0; j<tam && disponible == 1; j++) {
      if (i == solucion[j]) {
        disponible = 0;
      }
    }
    if (disponible == 1) {
      for (k = 0; k<tam; k++) {
        if (valores[k] == -1) {
          valores[k] = i;
          break;
        }
      }
    }
  }
}

int tab_valido(int solucion[], int tam) {
  if (solucion[0] == 0 || solucion[4] == 0 || solucion[6] == 0) {
    return 0;
  }
  return 1;
}

int tab_es_solucion(int solucion[], int tam) { // HARRY+POTTER=TROLLS
  int i;

  for (i = 0; i<tam; i++) { // Si todos están inicializados
    if (solucion[i] == -1) {
      return 0;
    }
  }
  int num1;
  int num2;
  int num_result;

  num1 = solucion[0];                           // H
  num1 = int_concat(num1, solucion[1]); // A
  num1 = int_concat(num1, solucion[2]); // R
  num1 = int_concat(num1, solucion[2]); // R
  num1 = int_concat(num1, solucion[3]); // Y

  num2 = solucion[4];                           // P
  num2 = int_concat(num2, solucion[5]); // O
  num2 = int_concat(num2, solucion[6]); // T
  num2 = int_concat(num2, solucion[6]); // T
  num2 = int_concat(num2, solucion[7]); // E
  num2 = int_concat(num2, solucion[2]); // R

  num_result = solucion[6];                                   // T
  num_result = int_concat(num_result, solucion[2]); // R
  num_result = int_concat(num_result, solucion[5]); // O
  num_result = int_concat(num_result, solucion[8]); // L
  num_result = int_concat(num_result, solucion[8]); // L
  num_result = int_concat(num_result, solucion[9]); // S

  if (num1 + num2 == num_result) {
    return 1;
  }
  return 0;
}

void tab_procesar_solucion(int solucion[], int tam) {
  int i;
  int tabla[11];
  int a_descifrar_tam = 14;
  char letras[tam+1];
  char a_descifrar[a_descifrar_tam];
  strcpy(letras, "HARYPOTELS");
  strcpy(a_descifrar, "6531484901984");
  for (i = 0; i<tam; i++) {
    tabla[solucion[i]] = i;
  }

  printf("Clave: %s\n", a_descifrar);
  printf("Clave desencriptada: ");
  for (i = 0; i<a_descifrar_tam; i++) {
    if (i == a_descifrar_tam-1) {
      printf("\n");
    } else {
      printf("%c", letras[tabla[a_descifrar[i] - '0']]);
    }
  }
  printf("Tabla utilizada:\n");
  printf("#############################################\n");
  printf("#   ");
  for (i = 0; i<tam; i++) {
    printf("%c   ", letras[i]);
  }
  printf("#\n#   ");
  for (i = 0; i<tam; i++) {
    printf("%i   ", solucion[i]);
  }
  printf("#\n#############################################\n");
}

void tab_rec(int solucion[], int etapa, int tam) {
  /* Posición 0: H;  1: A;  2: R;  3: Y;  4: P;  5: O;  6: T;  7: E;  8: L;  9: S  */
  if (etapa >= tam)  return;

  int valores[tam];
  tab_iniciar_valores(valores, solucion, tam);
//  imprimir(valores, tam);

  int i = 0;
  do {
//    printf("etapa: %d     i: %d\n", etapa, i);
    solucion[etapa] = valores[i];
//    printf("VALOR ACTUAL: %d\n", valores[i]);
//    printf("SOLU:");
//    imprimir(solucion, tam);
//    system("PAUSE");
    if (tab_valido(solucion, tam)) {
      if (tab_es_solucion(solucion, tam)) {
        tab_procesar_solucion(solucion, tam);
      } else {
        tab_rec(solucion,etapa+1, tam);
      }
    }
    i++;
  } while(i < tam && valores[i] != -1);
  solucion[etapa]=-1;
}

