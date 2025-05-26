#include "promocao.h"
#include <stdio.h>
#include <string.h>

#define MAX_PROMOCOES 50
Promocao promocoes[MAX_PROMOCOES];
int totalPromocoes = 0;

void carregarPromocoes() {
    FILE *f = fopen("promocoes.dat", "rb");
    if (f) {
        fread(&totalPromocoes, sizeof(int), 1, f);
        fread(promocoes, sizeof(Promocao), totalPromocoes, f);
        fclose(f);
    }
}

void salvarPromocoes() {
    FILE *f = fopen("promocoes.dat", "wb");
    if (f) {
        fwrite(&totalPromocoes, sizeof(int), 1, f);
        fwrite(promocoes, sizeof(Promocao), totalPromocoes, f);
        fclose(f);
    }
}

void cadastrarPromocao() {
    if (totalPromocoes >= MAX_PROMOCOES) {
        printf("Limite atingido.\n");
        return;
    }
    Promocao nova;
    nova.id = totalPromocoes + 1;
    printf("Nome: ");
    scanf(" %[^\n]", nova.nome);
    printf("Tipo: ");
    scanf(" %[^\n]", nova.tipo);
    printf("Valor: ");
    scanf("%f", &nova.valor);
    printf("Validade: ");
    scanf(" %[^\n]", nova.validade);
    printf("ID do produto: ");
    scanf("%d", &nova.produto_id);
    promocoes[totalPromocoes++] = nova;
    salvarPromocoes();
    printf("Promocao cadastrada!\n");
}

void listarPromocoes() {
    printf("=== Promocoes ===\n");
    for (int i = 0; i < totalPromocoes; i++) {
        printf("ID: %d | Nome: %s | Tipo: %s | Valor: %.2f | Produto: %d\n",
            promocoes[i].id, promocoes[i].nome, promocoes[i].tipo, promocoes[i].valor, promocoes[i].produto_id);
    }
}

Promocao* buscarPromocaoPorId(int id) {
    for (int i = 0; i < totalPromocoes; i++)
        if (promocoes[i].id == id)
            return &promocoes[i];
    return NULL;
}

void editarPromocao(int id) {
    Promocao *p = buscarPromocaoPorId(id);
    if (!p) {
        printf("Nao encontrada.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Novo tipo: ");
    scanf(" %[^\n]", p->tipo);
    printf("Novo valor: ");
    scanf("%f", &p->valor);
    printf("Nova validade: ");
    scanf(" %[^\n]", p->validade);
    printf("Novo ID do produto: ");
    scanf("%d", &p->produto_id);
    salvarPromocoes();
    printf("Editada!\n");
}

void removerPromocao(int id) {
    int found = 0;
    for (int i = 0; i < totalPromocoes; i++) {
        if (promocoes[i].id == id)
            found = 1;
        if (found && i < totalPromocoes - 1)
            promocoes[i] = promocoes[i + 1];
    }
    if (found) {
        totalPromocoes--;
        salvarPromocoes();
        printf("Removida!\n");
    } else {
        printf("Nao encontrada.\n");
    }
}
