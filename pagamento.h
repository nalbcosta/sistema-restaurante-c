#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "structs.h"
void cadastrarPagamento();
void listarPagamentos();
Pagamento* buscarPagamentoPorId(int id);
void editarPagamento(int id);
void removerPagamento(int id);
void salvarPagamentos();
void carregarPagamentos();
#endif
