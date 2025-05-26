#include "produto.h"
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void carregarProdutos() {
    FILE *f = fopen("produtos.dat", "rb");
    if (f) {
        fread(&totalProdutos, sizeof(int), 1, f);
        fread(produtos, sizeof(Produto), totalProdutos, f);
        fclose(f);
    }
}

void salvarProdutos() {
    FILE *f = fopen("produtos.dat", "wb");
    if (f) {
        fwrite(&totalProdutos, sizeof(int), 1, f);
        fwrite(produtos, sizeof(Produto), totalProdutos, f);
        fclose(f);
    }
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    Produto novo;
    novo.id = totalProdutos + 1;
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Categoria: ");
    scanf(" %[^\n]", novo.categoria);
    printf("Preco: ");
    scanf("%f", &novo.preco);
    printf("Estoque: ");
    scanf("%d", &novo.estoque);
    printf("Descricao: ");
    scanf(" %[^\n]", novo.descricao);
    produtos[totalProdutos++] = novo;
    salvarProdutos();
    printf("Produto cadastrado!\n");
}

void listarProdutos() {
    printf("=== Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d | Nome: %s | Categoria: %s | Preco: %.2f | Estoque: %d\n",
            produtos[i].id, produtos[i].nome, produtos[i].categoria, produtos[i].preco, produtos[i].estoque);
    }
}

Produto* buscarProdutoPorId(int id) {
    for (int i = 0; i < totalProdutos; i++)
        if (produtos[i].id == id)
            return &produtos[i];
    return NULL;
}

void editarProduto(int id) {
    Produto *p = buscarProdutoPorId(id);
    if (!p) {
        printf("Produto nao encontrado.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Nova categoria: ");
    scanf(" %[^\n]", p->categoria);
    printf("Novo preco: ");
    scanf("%f", &p->preco);
    printf("Novo estoque: ");
    scanf("%d", &p->estoque);
    printf("Nova descricao: ");
    scanf(" %[^\n]", p->descricao);
    salvarProdutos();
    printf("Editado!\n");
}

void removerProduto(int id) {
    int found = 0;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id)
            found = 1;
        if (found && i < totalProdutos - 1)
            produtos[i] = produtos[i + 1];
    }
    if (found) {
        totalProdutos--;
        salvarProdutos();
        printf("Removido!\n");
    } else {
        printf("Nao encontrado.\n");
    }
}
