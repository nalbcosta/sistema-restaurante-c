#ifndef PROMOCAO_H
#define PROMOCAO_H
#include "structs.h"
void cadastrarPromocao();
void listarPromocoes();
Promocao* buscarPromocaoPorId(int id);
void editarPromocao(int id);
void removerPromocao(int id);
void salvarPromocoes();
void carregarPromocoes();
#endif
