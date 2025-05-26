#ifndef PRODUTO_H
#define PRODUTO_H
#include "structs.h"
void cadastrarProduto();
void listarProdutos();
Produto* buscarProdutoPorId(int id);
void editarProduto(int id);
void removerProduto(int id);
void salvarProdutos();
void carregarProdutos();
#endif
