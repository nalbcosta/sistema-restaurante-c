#include "mesas.h"
#include <stdio.h>
#include <string.h>

#define MAX_MESAS 100

static Mesa mesas[MAX_MESAS];
static int totalMesas = 0;

// Função para carregar mesas de um arquivo
void carregarMesas() {
    FILE *f = fopen("mesas.dat", "rb");
    if (f) {
        fread(&totalMesas, sizeof(int), 1, f);
        fread(mesas, sizeof(Mesa), totalMesas, f);
        fclose(f);
    }
}

// Função para salvar mesas em um arquivo
void salvarMesas() {
    FILE *f = fopen("mesas.dat", "wb");
    if (f) {
        fwrite(&totalMesas, sizeof(int), 1, f);
        fwrite(mesas, sizeof(Mesa), totalMesas, f);
        fclose(f);
    }
}

// Função para cadastrar uma mesa
void cadastrarMesa() {
    if (totalMesas >= MAX_MESAS) {
        printf("Limite de mesas atingido.\n");
        return;
    }

    Mesa novaMesa;
    printf("=== Cadastro de Mesa ===\n");
    printf("ID: %d\n", totalMesas + 1);
    printf("Digite o numero da mesa: ");
    scanf("%d", &novaMesa.numero);
    printf("Digite a capacidade da mesa: ");
    scanf("%d", &novaMesa.capacidade);
    printf("Digite o status da mesa (disponível, ocupada, reservada): ");
    // Mostrar um mini menu com as opções disponíveis
    printf("1. Disponível\n");
    printf("2. Ocupada\n");
    printf("3. Reservada\n");
    printf("Escolha uma opção: ");
    int opcao;
    // Transformar a opção escolhida em string
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(novaMesa.status, "disponível");
            break;
        case 2:
            strcpy(novaMesa.status, "ocupada");
            break;
        case 3:
            strcpy(novaMesa.status, "reservada");
            break;
        default:
            printf("Opção inválida. Mesa cadastrada como disponível.\n");
            strcpy(novaMesa.status, "disponível");
            break;
    }
    printf("Digite a localização da mesa: ");
    // Mostrar um mini menu com as opções disponíveis
    printf("1. Interior\n");
    printf("2. Varanda\n");
    printf("3. Terraço\n");
    printf("Escolha uma opção: ");
    // Transformar a opção escolhida em string
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(novaMesa.localizacao, "interior");
            break;
        case 2:
            strcpy(novaMesa.localizacao, "varanda");
            break;
        case 3:
            strcpy(novaMesa.localizacao, "terraço");
            break;
        default:
            printf("Opção inválida. Mesa cadastrada como interior.\n");
            strcpy(novaMesa.localizacao, "interior");
            break;
    }

    mesas[totalMesas] = novaMesa;
    totalMesas++;
    salvarMesas();
    printf("Mesa cadastrada com sucesso!\n");
}

// Função para listar mesas
void listarMesas() {
    printf("=== Listagem de Mesas ===\n");
    if (totalMesas == 0) {
        printf("Nenhuma mesa cadastrada.\n");
        return;
    }
    for (int i = 0; i < totalMesas; i++) {
        printf("ID: %d\n", mesas[i].id);
        printf("Número: %d\n", mesas[i].numero);
        printf("Capacidade: %d\n", mesas[i].capacidade);
        printf("Status: %s\n", mesas[i].status);
        printf("Garçom ID: %d\n", mesas[i].garcom_id);
        printf("Localização: %s\n", mesas[i].localizacao);
        printf("-------------------------\n");
    }
}

// Função para buscar mesa por ID
Mesa* buscarMesaPorId(int id) {
    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].id == id) {
            return &mesas[i];
        }
    }
    return NULL;
}

// Função para editar uma mesa
void editarMesa(int id) {
    Mesa *mesa = buscarMesaPorId(id);
    if (mesa == NULL) {
        printf("Mesa com ID %d não encontrada.\n", id);
        return;
    }
    printf("=== Editar Mesa ===\n");
    printf("ID: %d\n", mesa->id);
    printf("Número atual: %d\n", mesa->numero);
    printf("Digite o novo número da mesa: ");
    scanf("%d", &mesa->numero);
    printf("Capacidade atual: %d\n", mesa->capacidade);
    printf("Digite a nova capacidade da mesa: ");
    scanf("%d", &mesa->capacidade);
    printf("Status atual: %s\n", mesa->status);
    printf("Digite o novo status da mesa (disponível, ocupada, reservada): ");
    // Mostrar um mini menu com as opções disponíveis
    printf("1. Disponível\n");
    printf("2. Ocupada\n");
    printf("3. Reservada\n");
    printf("Escolha uma opção: ");
    int opcao;
    // Transformar a opção escolhida em string
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(mesa->status, "disponível");
            break;
        case 2:
            strcpy(mesa->status, "ocupada");
            break;
        case 3:
            strcpy(mesa->status, "reservada");
            break;
        default:
            printf("Opção inválida. Status não alterado.\n");
            break;
    }
    printf("Localização atual: %s\n", mesa->localizacao);
    printf("Digite a nova localização da mesa: ");
    // Mostrar um mini menu com as opções disponíveis
    printf("1. Interior\n");
    printf("2. Varanda\n");
    printf("3. Terraço\n");
    printf("Escolha uma opção: ");
    // Transformar a opção escolhida em string
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(mesa->localizacao, "interior");
            break;
        case 2:
            strcpy(mesa->localizacao, "varanda");
            break;
        case 3:
            strcpy(mesa->localizacao, "terraço");
            break;
        default:
            printf("Opção inválida. Localização não alterada.\n");
            break;
    }
    salvarMesas();
    printf("Mesa editada com sucesso!\n");
}

// Função para remover uma mesa
void removerMesa(int id) {
    int found = 0;
    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].id == id) {
            found = 1;
        }
        if (found && i < totalMesas - 1) {
            mesas[i] = mesas[i + 1];
        }
    }
    if (found) {
        totalMesas--;
        salvarMesas();
        printf("Mesa removida com sucesso!\n");
    } else {
        printf("Mesa com ID %d não encontrada.\n", id);
    }
}