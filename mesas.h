#ifndef MESAS_H
#define MESAS_H

#include "structs.h"
#include <stdio.h>
#include "functions.h"

void cadastrarMesa();
void listarMesas();
Mesa* buscarMesaPorId(int id);
void editarMesa(int id);
void removerMesa(int id);
void salvarMesas();
void carregarMesas();

#endif