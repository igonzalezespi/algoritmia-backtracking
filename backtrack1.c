#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtrack1.h"
#include "utils.h"

// Función auxiliar: Iniciar valores
void conj_iniciar_valores(int valores[], int solucion[], int tam, int conjunto[]) {
  int i, j, k;
  crear(valores, tam); // Iniciamos a -1 todo

  // Ponemos en valores[] los elementos de conjunto[] que no estén en solucion[]
  for (i = 0; i<tam; i++) {
    int disponible = 1;
    for (j = 0; j<tam && disponible == 1; j++) {
      if (conjunto[i] == solucion[j]) {
        disponible = 0;
      }
    }
    if (disponible == 1) {
      // No dejamos huecos en valores[], se insertan desde el inicio hasta el final
      for (k = 0; k<tam; k++) {
        if (valores[k] == -1) {
          valores[k] = conjunto[i];
          break;
        }
      }
    }
  }
}

// Función auxiliar: Válido
int conj_valido(int solucion[], int tam, int suma_total) {
  int i;
  int suma_parcial = 0;

  // Verificamos que la suma de los elementos es menor o igual a la suma indicada por el usuario (C)
  //   En caso contrario no es válido y seguiremos por otra rama
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

// Función auxiliar: Es solucion
int conj_es_solucion(int solucion[], int tam, int suma_total, int solucion_final[]) {
  int i;
  int suma_parcial = 0;

  // Si ya existe esta solución (aunque ordenada de otra forma) saltamos
  if (comparar(solucion, solucion_final, tam) == 1) {
    return 0;
  }

  for (i = 0; i<tam; i++) {
    if (solucion[i] != -1) {
      suma_parcial += solucion[i];
    }
  }
  // Si la suma de los elementos es igual a la suma que indica el usuario (C) tenemos una posible solución
  if (suma_parcial == suma_total) {
    return 1;
  }
  return 0;
}

// Función auxiliar: Procesar solucion
void conj_procesar_solucion(int solucion[], int solucion_final[], int tam) {
  // En caso de que no exista solucion_final[] la ponemos sin comprobar nada más
  if (solucion_final[0] != -1) {
    // Si ya existe una solución calculamos sus diferencias máximas y nos quedamos con la menor
    int diff_actual = diferencia_absoluta(solucion, tam);
    int diff_final = diferencia_absoluta(solucion_final, tam);
    if (diff_actual >= diff_final) {
      return;
    }
  }
  copiar(solucion, solucion_final, tam);
}

// Función principal
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

