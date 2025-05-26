#include "cliente.h"
#include "mesas.h"
#include <stdio.h>
#include <string.h>

#define MAX_MESAS 100

Mesa mesas[MAX_MESAS];
int totalMesas = 0;

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
    novaMesa.id = totalMesas + 1; // Corrige o ID
    printf("=== Cadastro de Mesa ===\n");
    printf("ID: %d\n", novaMesa.id);
    printf("Digite o numero da mesa: ");
    scanf("%d", &novaMesa.numero);
    printf("Digite a capacidade da mesa: ");
    scanf("%d", &novaMesa.capacidade);
    // Carregar funcionários do arquivo
    FILE *ff = fopen("funcionarios.dat", "rb");
    Funcionario funcionarios[100];
    int totalFuncionarios = 0;
    if (ff) {
        fread(&totalFuncionarios, sizeof(int), 1, ff);
        fread(funcionarios, sizeof(Funcionario), totalFuncionarios, ff);
        fclose(ff);
    }
    // Listar apenas funcionários com cargo "Garcom"
    int encontrouGarcom = 0;
    for (int i = 0; i < totalFuncionarios; i++) {
        if (strcmp(funcionarios[i].cargo, "Garcom") == 0) {
            if (!encontrouGarcom) {
                printf("Garcons disponíveis:\n");
                encontrouGarcom = 1;
            }
            printf("ID: %d - Nome: %s\n", funcionarios[i].id, funcionarios[i].nome);
        }
    }
    int garcomIdEscolhido = 0;
    if (!encontrouGarcom) {
        printf("Nenhum garcom cadastrado. Atribuindo garcom_id = 0.\n");
        novaMesa.garcom_id = 0;
    } else {
        printf("Digite o ID do garcom para atribuir a mesa: ");
        scanf("%d", &garcomIdEscolhido);
        novaMesa.garcom_id = garcomIdEscolhido;
    }

    printf("Digite o status da mesa (disponivel, ocupada, reservada):\n");
    printf("1. Disponivel\n");
    printf("2. Ocupada\n");
    printf("3. Reservada\n");
    printf("Escolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(novaMesa.status, "disponivel");
            novaMesa.cliente_id = 0; // Nenhum cliente
            break;
        case 2:
            strcpy(novaMesa.status, "ocupada");
            // Listar clientes para escolher o ID
            printf("Clientes disponíveis para ocupar a mesa:\n");
            carregarClientes();
            for (int i = 0; i < totalClientes; i++) {
                printf("ID: %d - Nome: %s\n", clientes[i].id, clientes[i].nome);
            }
            printf("Digite o ID do cliente que está ocupando a mesa: ");
            int clienteIdEscolhido;
            scanf("%d", &clienteIdEscolhido);
            novaMesa.cliente_id = clienteIdEscolhido;
            break;
        case 3:
            strcpy(novaMesa.status, "reservada");
            printf("Para reservar esta mesa, utilize o menu de reservas!\n");
            novaMesa.cliente_id = 0;
            novaMesa.data_reserva[0] = '\0';
            break;
        default:
            printf("Opção inválida. Mesa cadastrada como disponível.\n");
            strcpy(novaMesa.status, "disponivel");
            novaMesa.cliente_id = 0;
            break;
    }
    printf("Digite a localização da mesa:\n");
    printf("1. Interior\n");
    printf("2. Varanda\n");
    printf("3. Terraco\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(novaMesa.localizacao, "interior");
            break;
        case 2:
            strcpy(novaMesa.localizacao, "varanda");
            break;
        case 3:
            strcpy(novaMesa.localizacao, "terraco");
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
        printf("Numero: %d\n", mesas[i].numero);
        printf("Capacidade: %d\n", mesas[i].capacidade);
        printf("Status: %s\n", mesas[i].status);
        printf("Garcom ID: %d\n", mesas[i].garcom_id);
        printf("Cliente ID: %d\n", mesas[i].cliente_id);
        printf("Localizacão: %s\n", mesas[i].localizacao);
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
        printf("Mesa com ID %d nao encontrada.\n", id);
        return;
    }
    printf("=== Editar Mesa ===\n");
    printf("ID: %d\n", mesa->id);
    printf("Numero atual: %d\n", mesa->numero);
    printf("Digite o novo numero da mesa: ");
    scanf("%d", &mesa->numero);
    printf("Capacidade atual: %d\n", mesa->capacidade);
    printf("Digite a nova capacidade da mesa: ");
    scanf("%d", &mesa->capacidade);
    printf("Status atual: %s\n", mesa->status);
    printf("Digite o novo status da mesa (disponivel, ocupada, reservada):\n");
    printf("1. Disponivel\n");
    printf("2. Ocupada\n");
    printf("3. Reservada\n");
    printf("Escolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(mesa->status, "disponivel");
            mesa->cliente_id = 0;
            break;
        case 2:
            strcpy(mesa->status, "ocupada");
            printf("Clientes disponíveis para ocupar a mesa:\n");
            carregarClientes();
            for (int i = 0; i < totalClientes; i++) {
                printf("ID: %d - Nome: %s\n", clientes[i].id, clientes[i].nome);
            }
            printf("Digite o ID do cliente que está ocupando a mesa: ");
            int clienteIdEscolhido;
            scanf("%d", &clienteIdEscolhido);
            mesa->cliente_id = clienteIdEscolhido;
            break;
        case 3:
            strcpy(mesa->status, "reservada");
            printf("Para reservar esta mesa, utilize o menu de reservas!\n");
            mesa->cliente_id = 0;
            break;
        default:
            printf("Opção inválida. Status não alterado.\n");
            break;
    }
    printf("Localização atual: %s\n", mesa->localizacao);
    printf("Digite a nova localização da mesa:\n");
    printf("1. Interior\n");
    printf("2. Varanda\n");
    printf("3. Terraco\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            strcpy(mesa->localizacao, "interior");
            break;
        case 2:
            strcpy(mesa->localizacao, "varanda");
            break;
        case 3:
            strcpy(mesa->localizacao, "terraco");
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
        printf("Mesa com ID %d nao encontrada.\n", id);
    }
}
