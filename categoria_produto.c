#include "categoria_produto.h"
#include <stdio.h>
#include <string.h>

#define MAX_CATEGORIAS 50
CategoriaProduto categorias[MAX_CATEGORIAS];
int totalCategorias = 0;

void carregarCategoriasProduto() {
    FILE *f = fopen("categorias.dat", "rb");
    if (f) {
        fread(&totalCategorias, sizeof(int), 1, f);
        fread(categorias, sizeof(CategoriaProduto), totalCategorias, f);
        fclose(f);
    }
}

void salvarCategoriasProduto() {
    FILE *f = fopen("categorias.dat", "wb");
    if (f) {
        fwrite(&totalCategorias, sizeof(int), 1, f);
        fwrite(categorias, sizeof(CategoriaProduto), totalCategorias, f);
        fclose(f);
    }
}

void cadastrarCategoriaProduto() {
    if (totalCategorias >= MAX_CATEGORIAS) {
        printf("Limite atingido.\n");
        return;
    }
    CategoriaProduto c;
    c.id = totalCategorias + 1;
    printf("Nome: ");
    scanf(" %[^]", c.nome);
    printf("Descricao: ");
    scanf(" %[^]", c.descricao);
    printf("Horario disponivel: ");
    scanf(" %[^]", c.horario_disponivel);
    printf("Prioridade: ");
    scanf(" %[^]", c.prioridade);
    printf("Tipo: ");
    scanf(" %[^]", c.tipo);
    categorias[totalCategorias++] = c;
    salvarCategoriasProduto();
    printf("Categoria cadastrada!\n");
}

void listarCategoriasProduto() {
    printf("=== Categorias ===\n");
    for (int i = 0; i < totalCategorias; i++) {
        printf("ID: %d | Nome: %s | Tipo: %s\n",
            categorias[i].id, categorias[i].nome, categorias[i].tipo);
    }
}

CategoriaProduto* buscarCategoriaProdutoPorId(int id) {
    for (int i = 0; i < totalCategorias; i++)
        if (categorias[i].id == id)
            return &categorias[i];
    return NULL;
}

void editarCategoriaProduto(int id) {
    CategoriaProduto *c = buscarCategoriaProdutoPorId(id);
    if (!c) {
        printf("Nao encontrada.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^]", c->nome);
    printf("Nova descricao: ");
    scanf(" %[^]", c->descricao);
    printf("Novo horario disponivel: ");
    scanf(" %[^]", c->horario_disponivel);
    printf("Nova prioridade: ");
    scanf(" %[^]", c->prioridade);
    printf("Novo tipo: ");
    scanf(" %[^]", c->tipo);
    salvarCategoriasProduto();
    printf("Editada!\n");
}

void removerCategoriaProduto(int id) {
    int found = 0;
    for (int i = 0; i < totalCategorias; i++) {
        if (categorias[i].id == id)
            found = 1;
        if (found && i < totalCategorias - 1)
            categorias[i] = categorias[i + 1];
    }
    if (found) {
        totalCategorias--;
        salvarCategoriasProduto();
        printf("Removida!\n");
    } else {
        printf("Nao encontrada.\n");
    }
}
