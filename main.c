#include <stdio.h>
#include <locale.h>
#include "functions.h"


int main(void) {
  setlocale(LC_ALL, "Portuguese_Brazil.1252");
  menuPrincipal();
  return 0;
}