#ifndef PEDIDO_H
#define PEDIDO_H

#include "structs.h"
#include <stdio.h>
#include "functions.h"

void cadastrarPedido();
void listarPedidos();
Pedido* buscarPedidoPorId(int id);
void editarPedido(int id);
void removerPedido(int id);
void salvarPedidos();
void carregarPedidos();

#endif
