#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtrack2.h"
#include "utils.h"

// Función auxiliar: Iniciar valores
void tab_iniciar_valores(int valores[], int solucion[], int tam) {
  int i, j, k;
  crear(valores, tam);

  // Los valores serán los números del 0 al 9
  //   No repetimos los valores y siempre los ponemos de principio a fin
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

// Función auxiliar: Válido
int tab_valido(int solucion[], int tam) {
  // Como indica el enunciado, las palabras no pueden empezar con ceros
  //    El índice 0 corresponde con H  (HARRY)
  //    El índice 4 corresponde con P  (POTTER)
  //    El índice 6 corresponde con T  (TROLLS)
  if (solucion[0] == 0 || solucion[4] == 0 || solucion[6] == 0) {
    return 0;
  }
  return 1;
}

// Función auxiliar: Es solución
int tab_es_solucion(int solucion[], int tam) {
  int i;

  // Condición principal: Que todos los elementos tengan un valor
  for (i = 0; i<tam; i++) {
    if (solucion[i] == -1) {
      return 0;
    }
  }


  int num1; // El número correspondiente a "HARRY"
  int num2; // El número correspondiente a "POTTER"
  int num_result; // El número correspondiente a "TROLLS"

  // Vamos concatenando los números de la solución según la operación que nos dice el enunciado
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

  // Realizamos la operación que propone el enunciado
  //    En caso de ser correcta tenemos la solución
  if (num1 + num2 == num_result) {
    return 1;
  }
  return 0;
}

// Función auxiliar: Procesar solución
void tab_procesar_solucion(int solucion[], int tam) {
  // Como es una sola solución, solo imprimimos por pantalla el resultado
  int i;
  int tabla[11];
  int a_descifrar_tam = 14;
  char letras[tam+1];
  char a_descifrar[a_descifrar_tam];

  strcpy(letras, "HARYPOTELS"); // Las posibles letras (Las de la operación/suma)
  strcpy(a_descifrar, "6531484901984"); // La clave a descifrar

  printf("Clave: %s\n", a_descifrar);

  /*
    Como en el array solución tenemos la relación:
      solución[<letra>] = <valor>
    Necesitamos lo contrario para poder descifrar:
      tabla[<valor>] = <letra>
    Suponiendo que <letra> es el valor numérico de cada letra (sin descifrar)
  */
  for (i = 0; i<tam; i++) {
    tabla[solucion[i]] = i;
  }

  printf("Clave desencriptada: ");
  for (i = 0; i<a_descifrar_tam; i++) {
    if (i == a_descifrar_tam-1) {
      printf("\n"); // El último valor es el <fin de cadena>, así que ponemos un salto de linea
    } else {
      int numero = a_descifrar[i] - '0'; // Convertimos de "char" a "int"
      /*
        tabla[numero] nos da el valor numérico de la letra. (H -> 0, A -> 1, ...)
        Consultando este valor numérico en el array "letras" obtenemos la letra de verdad
      */
      printf("%c", letras[tabla[numero]]);
    }
  }
  // Imprimimos la relación letra/valor
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

// Función principal
int tab_rec(int solucion[], int etapa, int tam) {
  int exito = 0;

  if (etapa >= tam)  return exito;

  int valores[tam];
  tab_iniciar_valores(valores, solucion, tam);

  int i = 0;
  do {
    solucion[etapa] = valores[i];
    if (tab_valido(solucion, tam)) {
      if (tab_es_solucion(solucion, tam)) {
        tab_procesar_solucion(solucion, tam);
        exito = 1;
      } else {
        exito = tab_rec(solucion,etapa+1, tam);
      }
      if (exito == 0) {
        solucion[etapa]=-1;
      }
    }
    i++;
  } while(i < tam && valores[i] != -1 && exito == 0);
  return exito;
}
