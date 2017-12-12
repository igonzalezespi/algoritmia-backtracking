#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "backtrack1.h"
#include "backtrack2.h"
#include "utils.h"

// Lee un número por pantalla. Si no es mayor que cero se vuelve a ejecutar mostrando un error por pantalla
int dame_int_rec() {
  int numero = dame_int();
  if (numero > 0) {
    return numero;
  } else {
    printf("Incorrecto. El numero debe ser mayor que cero.\n");
    return dame_int_rec();
  }
}

int main() {
  // Menú recursivo para elegir un ejercicio
  int ejercicio = menu();
  int nodos;
  while (ejercicio != 0) {
    if (ejercicio == 1) { // Elige el ejercicio 1
      int i;
      // Iniciando los valores necesarios
      printf("Tamano del conjunto (V):\n");
      int tam = dame_int_rec();
      int conjunto[tam];
      int solucion[tam];
      for (i = 0; i<tam; i++) {
        printf("Valor del elemento V(%d):\n", i + 1);
        conjunto[i] = dame_int_rec();
      }
      printf("Valor de la suma (C):\n");
      int suma = dame_int_rec();
      int solucion_final[tam];

      crear(solucion, tam); // Inicializamos a -1
      crear(solucion_final, tam);
      // Empieza backtracking
      nodos = 1; // Contamos el nodo raiz
      conj_rec(solucion, 0, tam, conjunto, suma, solucion_final, &nodos);
      printf("Solucion: ");
      imprimir(solucion_final, tam);
    } else if (ejercicio == 2) { // Elige el ejercicio 2
      int tam = 10; // Suma del número de letras en "HARRY POTTER TROLLS", quitando las repetidas
      int solucion[tam];

      // No se pide nada al usuario, nos lo da el enunciado.

      crear(solucion, tam); // Inicializamos a -1
      // Empieza backtracking
      nodos = 1; // Contamos el nodo raiz
      tab_rec(solucion, 0, tam, &nodos);
    }
    if (ejercicio == 1 || ejercicio == 2) {
      printf("Nodos generados: %d\n", nodos);
      system("PAUSE");
    }
    ejercicio = menu();
  }
  return 0;
}


