#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "utils.h"

int menu() {
  char seleccion;
  cls();
  printf("=========== BACKTRACKING ===========\n\n");
  printf("== Ejercicio a realizar: ==\n");
  printf("1. Conjuntos. Diferencia maxima absoluta.\n");
  printf("2. Tabla. Descifrar una clave.\n");
  printf("S. Salir\n");
  scanf(" %c", &seleccion);

  switch (tolower(seleccion)) {
  case '1':
    return 1;
  case '2':
    return 2;
  case 's':
    return 0;
  }
  return -1;
}
