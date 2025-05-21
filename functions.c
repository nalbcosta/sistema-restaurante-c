#include <stdio.h>
#include "functions.h"
#include "cliente.h"
#include "mesas.h"

void menuPrincipal() {
    int opcao;
    do {
        printf("\n=== Sistema Restaurante ===\n");
        printf("1. Clientes\n");
        printf("2. Mesas\n");
        printf("3. Pedidos\n");
        printf("4. Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nClientes selecionado.\n");
                menuClientes();
                break;
            case 2:
                printf("\nMesas selecionado.\n");
                menuMesas();
                break;
            case 3:
                printf("\nPedidos selecionado.\n");
                menuPedidos();
                break;
            case 4:
                printf("\nProdutos selecionado.\n");
                menuProdutos();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
    printf("\nSistema encerrado.\n");
}

void menuClientes() {
    int opcao;
    do {
        printf("\n=== Menu Clientes ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Editar Cliente\n");
        printf("4. Remover Cliente\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nAdicionar Cliente selecionado.\n");
                cadastrarCliente();
                break;
            case 2:
                printf("\nListar Clientes selecionado.\n");
                listarClientes();
                break;
            case 3:
                printf("\nEditar Cliente selecionado.\n");
                printf("Digite o ID do cliente a ser editado: ");
                int id;
                scanf("%d", &id);
                editarCliente(id);
                break;
            case 4:
                printf("\nRemover Cliente selecionado.\n");
                printf("Digite o ID do cliente a ser removido: ");
                scanf("%d", &id);
                removerCliente(id);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    }
    while (opcao != 0);
}

void menuMesas() {
    int opcao;
    do {
        printf("\n=== Menu Mesas ===\n");
        printf("1. Adicionar Mesa\n");
        printf("2. Listar Mesas\n");
        printf("3. Editar Mesa\n");
        printf("4. Remover Mesa\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nAdicionar Mesa selecionado.\n");
                // Aqui você pode chamar a função para adicionar mesa
                break;
            case 2:
                printf("\nListar Mesas selecionado.\n");
                // Aqui você pode chamar a função para listar mesas
                break;
            case 3:
                printf("\nEditar Mesa selecionado.\n");
                // Aqui você pode chamar a função para editar mesa
                break;
            case 4:
                printf("\nRemover Mesa selecionado.\n");
                // Aqui você pode chamar a função para remover mesa
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuPedidos() {
    int opcao;
    do {
        printf("\n=== Menu Pedidos ===\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Listar Pedidos\n");
        printf("3. Editar Pedido\n");
        printf("4. Remover Pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Adicionar Pedido selecionado.\n");
                // Aqui você pode chamar a função para adicionar pedido
                break;
            case 2:
                printf("Listar Pedidos selecionado.\n");
                // Aqui você pode chamar a função para listar pedidos
                break;
            case 3:
                printf("Editar Pedido selecionado.\n");
                // Aqui você pode chamar a função para editar pedido
                break;
            case 4:
                printf("Remover Pedido selecionado.\n");
                // Aqui você pode chamar a função para remover pedido
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuProdutos() {
    int opcao;
    do {
        printf("\n=== Menu Produtos ===\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Editar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Adicionar Produto selecionado.\n");
                // Aqui você pode chamar a função para adicionar produto
                break;
            case 2:
                printf("Listar Produtos selecionado.\n");
                // Aqui você pode chamar a função para listar produtos
                break;
            case 3:
                printf("Editar Produto selecionado.\n");
                // Aqui você pode chamar a função para editar produto
                break;
            case 4:
                printf("Remover Produto selecionado.\n");
                // Aqui você pode chamar a função para remover produto
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuRelatorios() {
    int opcao;
    do {
        printf("\n=== Menu Relatórios ===\n");
        printf("1. Relatório de Vendas\n");
        printf("2. Relatório de Clientes\n");
        printf("3. Relatório de Mesas\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Relatório de Vendas selecionado.\n");
                // Aqui você pode chamar a função para gerar relatório de vendas
                break;
            case 2:
                printf("Relatório de Clientes selecionado.\n");
                // Aqui você pode chamar a função para gerar relatório de clientes
                break;
            case 3:
                printf("Relatório de Mesas selecionado.\n");
                // Aqui você pode chamar a função para gerar relatório de mesas
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}
