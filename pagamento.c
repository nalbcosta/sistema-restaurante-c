#include "pagamento.h"
#include <stdio.h>
#include <string.h>

#define MAX_PAGAMENTOS 200
Pagamento pagamentos[MAX_PAGAMENTOS];
int totalPagamentos = 0;

void carregarPagamentos() {
    FILE *f = fopen("pagamentos.dat", "rb");
    if (f) {
        fread(&totalPagamentos, sizeof(int), 1, f);
        fread(pagamentos, sizeof(Pagamento), totalPagamentos, f);
        fclose(f);
    }
}

void salvarPagamentos() {
    FILE *f = fopen("pagamentos.dat", "wb");
    if (f) {
        fwrite(&totalPagamentos, sizeof(int), 1, f);
        fwrite(pagamentos, sizeof(Pagamento), totalPagamentos, f);
        fclose(f);
    }
}

void cadastrarPagamento() {
    if (totalPagamentos >= MAX_PAGAMENTOS) {
        printf("Limite atingido.\n");
        return;
    }
    Pagamento novo;
    novo.id = totalPagamentos + 1;
    printf("ID do pedido: ");
    scanf("%d", &novo.pedido_id);
    getchar(); // Limpa buffer
    printf("Valor: ");
    scanf("%f", &novo.valor);
    getchar(); // Limpa buffer
    printf("Forma de pagamento: ");
    scanf("%s", novo.forma_pagamento);
    printf("Status: ");
    scanf("%s", novo.status);
    printf("Data (DD/MM/AAAA): ");
    scanf("%s", novo.data);
    pagamentos[totalPagamentos++] = novo;
    salvarPagamentos();
    printf("Pagamento cadastrado!\n");
}

void listarPagamentos() {
    printf("=== Pagamentos ===\n");
    for (int i = 0; i < totalPagamentos; i++) {
        printf("ID: %d | Pedido: %d | Valor: %.2f | Forma: %s | Status: %s\n",
            pagamentos[i].id, pagamentos[i].pedido_id, pagamentos[i].valor, pagamentos[i].forma_pagamento, pagamentos[i].status);
    }
}

Pagamento* buscarPagamentoPorId(int id) {
    for (int i = 0; i < totalPagamentos; i++)
        if (pagamentos[i].id == id)
            return &pagamentos[i];
    return NULL;
}

void editarPagamento(int id) {
    Pagamento *p = buscarPagamentoPorId(id);
    if (!p) {
        printf("Nao encontrado.\n");
        return;
    }
    printf("Novo valor: ");
    scanf("%f", &p->valor);
    printf("Nova forma de pagamento: ");
    scanf("%s", p->forma_pagamento);
    printf("Novo status: ");
    scanf("%s", p->status);
    printf("Nova data: ");
    scanf("%s", p->data);
    salvarPagamentos();
    printf("Editado!\n");
}

void removerPagamento(int id) {
    int found = 0;
    for (int i = 0; i < totalPagamentos; i++) {
        if (pagamentos[i].id == id)
            found = 1;
        if (found && i < totalPagamentos - 1)
            pagamentos[i] = pagamentos[i + 1];
    }
    if (found) {
        totalPagamentos--;
        salvarPagamentos();
        printf("Removido!\n");
    } else {
        printf("Nao encontrado.\n");
    }
}
