#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include "structs.h"
#include <stdio.h>
#include "functions.h"

void cadastrarFuncionario();
void listarFuncionarios();
Funcionario* buscarFuncionarioPorId(int id);
void editarFuncionario(int id);
void removerFuncionario(int id);
void salvarFuncionarios();
void carregarFuncionarios();

#endif