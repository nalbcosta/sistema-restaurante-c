#ifndef CATEGORIA_PRODUTO_H
#define CATEGORIA_PRODUTO_H
#include "structs.h"
void cadastrarCategoriaProduto();
void listarCategoriasProduto();
CategoriaProduto* buscarCategoriaProdutoPorId(int id);
void editarCategoriaProduto(int id);
void removerCategoriaProduto(int id);
void salvarCategoriasProduto();
void carregarCategoriasProduto();
#endif
