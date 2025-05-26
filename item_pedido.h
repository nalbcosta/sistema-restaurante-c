#ifndef ITEM_PEDIDO_H
#define ITEM_PEDIDO_H
#include "structs.h"
void cadastrarItemPedido();
void listarItensPedido();
ItemPedido* buscarItemPedidoPorId(int id);
void editarItemPedido(int id);
void removerItemPedido(int id);
void salvarItensPedido();
void carregarItensPedido();
#endif
