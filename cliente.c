#include "cliente.h"
#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// Função para carregar clientes de um arquivo
void carregarClientes() {
    FILE *f = fopen("clientes.dat", "rb");
    if (f) {
        fread(&totalClientes, sizeof(int), 1, f);
        fread(clientes, sizeof(Cliente), totalClientes, f);
        fclose(f);
    }
}

// Função para salvar clientes em um arquivo
void salvarClientes() {
    FILE *f = fopen("clientes.dat", "wb");
    if (f) {
        fwrite(&totalClientes, sizeof(int), 1, f);
        fwrite(clientes, sizeof(Cliente), totalClientes, f);
        fclose(f);
    }
}

//Função para cadastrar um cliente
void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;
    novoCliente.id = totalClientes + 1; // Corrige o ID
    printf("=== Cadastro de Cliente ===\n");
    printf("ID: %d\n", novoCliente.id);
    printf("Digite o nome do cliente: ");
    scanf("%[^\n]", novoCliente.nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", novoCliente.cpf);
    printf("Digite o telefone do cliente: ");
    scanf("%s", novoCliente.telefone);
    printf("Digite o email do cliente: ");
    scanf("%s", novoCliente.email);
    novoCliente.fidelidade = 0;
    clientes[totalClientes] = novoCliente;
    totalClientes++;
    salvarClientes();
    printf("Cliente cadastrado com sucesso!\n");
}

// Função para listar todos os clientes
void listarClientes() {
    printf("=== Lista de Clientes ===\n");
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Email: %s\n", clientes[i].email);
        printf("Fidelidade: %d\n", clientes[i].fidelidade);
        printf("-------------------------\n");
    }
}

// Função para buscar um cliente pelo ID
Cliente* buscarClientePorId(int id) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            return &clientes[i];
        }
    }
    return NULL;
}

// Função para editar um cliente
void editarCliente(int id){
    Cliente *cliente = buscarClientePorId(id);
    if (cliente == NULL){
        printf("Cliente com ID %d não encontrado.\n", id);
        return;
    }
    printf("=== Editar Cliente ===\n");
    printf("ID: %d\n", cliente->id);
    printf("Nome atual: %s\n", cliente->nome);
    printf("Digite o novo nome do cliente: ");
    scanf("%s", cliente->nome);
    printf("Telefone atual: %s\n", cliente->telefone);
    printf("Digite o novo telefone do cliente: ");
    scanf("%s", cliente->telefone);
    printf("CPF atual: %s\n", cliente->cpf);
    printf("Digite o novo CPF do cliente: ");
    scanf("%s", cliente->cpf);
    printf("Email atual: %s\n", cliente->email);
    printf("Digite o novo email do cliente: ");
    scanf("%s", cliente->email);
    printf("Fidelidade atual: %d\n", cliente->fidelidade);
    printf("Digite os novos pontos de fidelidade do cliente: ");
    scanf("%d", &cliente->fidelidade);
    salvarClientes();
    printf("Cliente editado com sucesso!\n");
}

void removerCliente(int id) {
    int found = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            found = 1;
        }
        if (found && i < totalClientes - 1) {
            clientes[i] = clientes[i + 1];
        }
    }
    if (found) {
        totalClientes--;
        salvarClientes();
        printf("Cliente removido com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }
}