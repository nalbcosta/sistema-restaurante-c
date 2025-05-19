#ifndef CLIENTE_H
#define CLIENTE_H

#include '../includes/structs.h'

void cadastrarCliente();
void listarClientes();
Cliente* buscarClientePorId(int id);
void editarCliente(int id);
void removerCliente(int id);
void salvarClientes();
void carregarClientes();

#endif