#include "structs.h"
#include <stdio.h>
#include <string.h>

#define MAX_RESERVAS 100

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void carregarReservas() {
    FILE *f = fopen("reservas.dat", "rb");
    if (f) {
        fread(&totalReservas, sizeof(int), 1, f);
        fread(reservas, sizeof(Reserva), totalReservas, f);
        fclose(f);
    }
}

void salvarReservas() {
    FILE *f = fopen("reservas.dat", "wb");
    if (f) {
        fwrite(&totalReservas, sizeof(int), 1, f);
        fwrite(reservas, sizeof(Reserva), totalReservas, f);
        fclose(f);
    }
}

void cadastrarReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido.\n");
        return;
    }
    Reserva novaReserva;
    novaReserva.id = totalReservas + 1;
    printf("=== Cadastro de Reserva ===\n");
    printf("ID: %d\n", novaReserva.id);
    // Listar clientes
    extern void carregarClientes();
    extern Cliente clientes[];
    extern int totalClientes;
    carregarClientes();
    printf("Clientes disponíveis:\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d - Nome: %s\n", clientes[i].id, clientes[i].nome);
    }
    printf("Digite o ID do cliente: ");
    scanf("%d", &novaReserva.cliente_id);
    printf("Digite a data da reserva (DD/MM/AAAA): ");
    scanf("%s", novaReserva.data);
    printf("Digite a hora da reserva (HH:MM): ");
    scanf("%s", novaReserva.hora);
    // Listar mesas
    extern void carregarMesas();
    extern Mesa mesas[];
    extern int totalMesas;
    carregarMesas();
    printf("Mesas disponíveis:\n");
    for (int i = 0; i < totalMesas; i++) {
        printf("ID: %d - Numero: %d\n", mesas[i].id, mesas[i].numero);
    }
    printf("Digite o ID da mesa reservada: ");
    scanf("%d", &novaReserva.mesa_id);
    printf("Digite o status da reserva (confirmada, cancelada, pendente): ");
    scanf("%s", novaReserva.status);
    reservas[totalReservas] = novaReserva;
    totalReservas++;
    salvarReservas();
    printf("Reserva cadastrada com sucesso!\n");
}

void listarReservas() {
    printf("=== Lista de Reservas ===\n");
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }
    for (int i = 0; i < totalReservas; i++) {
        printf("ID: %d\n", reservas[i].id);
        printf("Cliente ID: %d\n", reservas[i].cliente_id);
        printf("Data: %s\n", reservas[i].data);
        printf("Hora: %s\n", reservas[i].hora);
        printf("Mesa ID: %d\n", reservas[i].mesa_id);
        printf("Status: %s\n", reservas[i].status);
        printf("-------------------------\n");
    }
}

Reserva* buscarReservaPorId(int id) {
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].id == id) {
            return &reservas[i];
        }
    }
    return NULL;
}

void editarReserva(int id) {
    Reserva *res = buscarReservaPorId(id);
    if (res == NULL) {
        printf("Reserva com ID %d nao encontrada.\n", id);
        return;
    }
    printf("=== Editar Reserva ===\n");
    printf("ID: %d\n", res->id);
    printf("Cliente ID atual: %d\n", res->cliente_id);
    printf("Digite o novo ID do cliente: ");
    scanf("%d", &res->cliente_id);
    printf("Data atual: %s\n", res->data);
    printf("Digite a nova data (DD/MM/AAAA): ");
    scanf("%s", res->data);
    printf("Hora atual: %s\n", res->hora);
    printf("Digite a nova hora (HH:MM): ");
    scanf("%s", res->hora);
    printf("Mesa ID atual: %d\n", res->mesa_id);
    printf("Digite o novo ID da mesa: ");
    scanf("%d", &res->mesa_id);
    printf("Status atual: %s\n", res->status);
    printf("Digite o novo status (confirmada, cancelada, pendente): ");
    scanf("%s", res->status);
    salvarReservas();
    printf("Reserva editada com sucesso!\n");
}

void removerReserva(int id) {
    int found = 0;
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].id == id) {
            found = 1;
        }
        if (found && i < totalReservas - 1) {
            reservas[i] = reservas[i + 1];
        }
    }
    if (found) {
        totalReservas--;
        salvarReservas();
        printf("Reserva removida com sucesso!\n");
    } else {
        printf("Reserva com ID %d nao encontrada.\n", id);
    }
}
