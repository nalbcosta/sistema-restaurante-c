#include "item_pedido.h"
#include "produto.h"
#include <stdio.h>
#include <string.h>

#define MAX_ITENS 500
ItemPedido itens[MAX_ITENS];
int totalItens = 0;

void carregarItensPedido() {
    FILE *f = fopen("itens_pedido.dat", "rb");
    if (f) {
        fread(&totalItens, sizeof(int), 1, f);
        fread(itens, sizeof(ItemPedido), totalItens, f);
        fclose(f);
    }
}

void salvarItensPedido() {
    FILE *f = fopen("itens_pedido.dat", "wb");
    if (f) {
        fwrite(&totalItens, sizeof(int), 1, f);
        fwrite(itens, sizeof(ItemPedido), totalItens, f);
        fclose(f);
    }
}

void cadastrarItemPedido() {
    if (totalItens >= MAX_ITENS) {
        printf("Limite atingido.\n");
        return;
    }
    ItemPedido novo;
    novo.id = totalItens + 1;
    printf("ID do pedido: ");
    scanf("%d", &novo.pedido_id);
    printf("ID do produto: ");
    scanf("%d", &novo.produto_id);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    Produto* prod = buscarProdutoPorId(novo.produto_id);
    if (!prod) {
        printf("Produto nao encontrado!\n");
        return;
    }
    novo.preco_unitario = prod->preco;
    novo.subtotal = novo.preco_unitario * novo.quantidade;
    if (prod->estoque < novo.quantidade) {
        printf("Estoque insuficiente!\n");
        return;
    }
    prod->estoque -= novo.quantidade;
    salvarProdutos();
    itens[totalItens++] = novo;
    salvarItensPedido();
    printf("Item adicionado ao pedido!\n");
}

void listarItensPedido() {
    printf("=== Itens de Pedido ===\n");
    for (int i = 0; i < totalItens; i++) {
        printf("ID: %d | Pedido: %d | Produto: %d | Qtd: %d | Subtotal: %.2f\n",
            itens[i].id, itens[i].pedido_id, itens[i].produto_id, itens[i].quantidade, itens[i].subtotal);
    }
}

ItemPedido* buscarItemPedidoPorId(int id) {
    for (int i = 0; i < totalItens; i++)
        if (itens[i].id == id)
            return &itens[i];
    return NULL;
}

void editarItemPedido(int id) {
    ItemPedido *it = buscarItemPedidoPorId(id);
    if (!it) {
        printf("Nao encontrado.\n");
        return;
    }
    printf("Nova quantidade: ");
    int novaQtd;
    scanf("%d", &novaQtd);
    Produto* prod = buscarProdutoPorId(it->produto_id);
    if (!prod) {
        printf("Produto nao encontrado!\n");
        return;
    }
    if (prod->estoque + it->quantidade < novaQtd) {
        printf("Estoque insuficiente!\n");
        return;
    }
    prod->estoque += it->quantidade - novaQtd;
    it->quantidade = novaQtd;
    it->subtotal = it->preco_unitario * novaQtd;
    salvarProdutos();
    salvarItensPedido();
    printf("Editado!\n");
}

void removerItemPedido(int id) {
    int found = 0;
    for (int i = 0; i < totalItens; i++) {
        if (itens[i].id == id)
            found = 1;
        if (found && i < totalItens - 1)
            itens[i] = itens[i + 1];
    }
    if (found) {
        totalItens--;
        salvarItensPedido();
        printf("Removido!\n");
    } else {
        printf("Nao encontrado.\n");
    }
}
