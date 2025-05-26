#include "cliente.h"
#include "pedido.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 500

static Pedido pedidos[MAX_PEDIDOS];
static int totalPedidos = 0;
extern Mesa mesas[];
extern int totalMesas;
extern Reserva reservas[];
extern int totalReservas;

// Função para carregar Pedidos de um arquivo
void carregarPedidos() {
    FILE *f = fopen("pedidos.dat", "rb");
    if (f) {
        fread(&totalPedidos, sizeof(int), 1, f);
        fread(pedidos, sizeof(Pedido), totalPedidos, f);
        fclose(f);
    }
}

// Função para salvar mesas em um arquivo
void salvarPedidos() {
    FILE *f = fopen("pedidos.dat", "wb");
    if (f) {
        fwrite(&totalPedidos, sizeof(int), 1, f);
        fwrite(pedidos, sizeof(Pedido), totalPedidos, f);
        fclose(f);
    }
}

// Função para cadastrar um pedido
void cadastrarPedido() {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    // 1. Listar clientes ativos
    printf("\n--- Clientes Ativos ---\n");
    listarClientes();

    // 2. Selecionar cliente
    int clienteIdEscolhido;
    printf("Digite o ID do cliente: ");
    scanf("%d", &clienteIdEscolhido);

    // 3. Listar apenas mesas ocupadas ou reservadas pelo cliente escolhido
    printf("\n--- Mesas ocupadas ou reservadas pelo cliente ID %d ---\n", clienteIdEscolhido);
    carregarMesas();
    carregarReservas();
    int encontrouMesa = 0;
    for (int i = 0; i < totalMesas; i++) {
        // Verifica se a mesa está ocupada pelo cliente
        if (strcmp(mesas[i].status, "ocupada") == 0 && mesas[i].cliente_id == clienteIdEscolhido) {
            printf("ID: %d | Numero: %d | Capacidade: %d | Status: %s\n", mesas[i].id, mesas[i].numero, mesas[i].capacidade, mesas[i].status);
            encontrouMesa = 1;
        }
        // Verifica se a mesa está reservada para o cliente em alguma reserva confirmada
        for (int j = 0; j < totalReservas; j++) {
            if (reservas[j].mesa_id == mesas[i].id && reservas[j].cliente_id == clienteIdEscolhido && strcmp(reservas[j].status, "confirmada") == 0) {
                printf("ID: %d | Numero: %d | Capacidade: %d | Status: reservada (reserva confirmada)\n", mesas[i].id, mesas[i].numero, mesas[i].capacidade);
                encontrouMesa = 1;
            }
        }
    }
    if (!encontrouMesa) {
        printf("O cliente não está ocupando nem reservando nenhuma mesa no momento.\n");
        return;
    }

    Pedido novoPedido;
    novoPedido.id = totalPedidos + 1; // Corrige o ID
    novoPedido.cliente_id = clienteIdEscolhido;
    printf("=== Cadastro de Pedido ===\n");
    printf("ID: %d\n", novoPedido.id);
    printf("Digite o ID da mesa: ");
    scanf("%d", &novoPedido.mesa_id);
    printf("Digite a data do pedido (DD/MM/AAAA): ");
    scanf(" %[^]", novoPedido.data);
    printf("Digite o status do pedido (em andamento, concluido, cancelado): ");
    scanf(" %[^]", novoPedido.status);
    novoPedido.valor_total = 0;

    // Se a mesa estava reservada, muda para ocupada e atualiza status da reserva
    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].id == novoPedido.mesa_id && strcmp(mesas[i].status, "reservada") == 0) {
            strcpy(mesas[i].status, "ocupada");
            salvarMesas();
            carregarReservas();
            for (int j = 0; j < totalReservas; j++) {
                if (reservas[j].mesa_id == mesas[i].id && reservas[j].cliente_id == clienteIdEscolhido && strcmp(reservas[j].status, "pendente") == 0) {
                    strcpy(reservas[j].status, "confirmada");
                    salvarReservas();
                    break;
                }
            }
            break;
        }
    }

    pedidos[totalPedidos] = novoPedido;
    totalPedidos++;
    salvarPedidos();
    printf("Pedido cadastrado com sucesso!\n");

    // Adicionar itens ao pedido
    char adicionarMais = 's';
    while (adicionarMais == 's' || adicionarMais == 'S') {
        printf("Deseja adicionar um item ao pedido? (s/n): ");
        scanf(" %c", &adicionarMais);
        if (adicionarMais == 's' || adicionarMais == 'S') {
            printf("Chamando cadastro de item de pedido...\n");
            cadastrarItemPedido();
        }
    }
}

void listarPedidos() {
    printf("=== Lista de Pedidos ===\n");
    if (totalPedidos == 0) {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalPedidos; i++) {
        printf("ID: %d\n", pedidos[i].id);
        printf("Cliente ID: %d\n", pedidos[i].cliente_id);
        printf("Mesa ID: %d\n", pedidos[i].mesa_id);
        printf("Data: %s\n", pedidos[i].data);
        printf("Status: %s\n", pedidos[i].status);
        printf("Valor Total: %.2f\n", pedidos[i].valor_total);
        printf("-------------------------\n");
    }
}

Pedido* buscarPedidoPorId(int id) {
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id) {
            return &pedidos[i];
        }
    }
    return NULL;
}

void editarPedido(int id) {
    Pedido *pedido = buscarPedidoPorId(id);
    if (pedido == NULL) {
        printf("Pedido com ID %d não encontrado.\n", id);
        return;
    }
    printf("=== Editar Pedido ===\n");
    printf("ID: %d\n", pedido->id);
    printf("Cliente ID atual: %d\n", pedido->cliente_id);
    printf("Digite o novo ID do cliente: ");
    scanf("%d", &pedido->cliente_id);
    printf("Mesa ID atual: %d\n", pedido->mesa_id);
    printf("Digite o novo ID da mesa: ");
    scanf("%d", &pedido->mesa_id);
    printf("Data atual: %s\n", pedido->data);
    printf("Digite a nova data (DD/MM/AAAA): ");
    scanf("%s", pedido->data);
    printf("Status atual: %s\n", pedido->status);
    printf("Digite o novo status (em andamento, concluido, cancelado): ");
    scanf("%s", pedido->status);
    printf("Valor total atual: %.2f\n", pedido->valor_total);
    printf("Digite o novo valor total: ");
    scanf("%f", &pedido->valor_total);
    salvarPedidos();
    printf("Pedido editado com sucesso!\n");
}

void removerPedido(int id) {
    int found = 0;
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id) {
            found = 1;
        }
        if (found && i < totalPedidos - 1) {
            pedidos[i] = pedidos[i + 1];
        }
    }
    if (found) {
        totalPedidos--;
        salvarPedidos();
        printf("Pedido removido com sucesso!\n");
    } else {
        printf("Pedido com ID %d não encontrado.\n", id);
    }
}

