#include <stdio.h>
#include "functions.h"
#include "cliente.h"
#include "mesas.h"
#include "pedido.h"
#include "funcionarios.h"
#include "reserva.h"
#include "produto.h"
#include "categoria_produto.h"
#include "item_pedido.h"
#include "pagamento.h"
#include "promocao.h"
#include "relatorios.h"
void menuPrincipal() {
    int opcao;
    do {
        printf("\n=== Sistema Restaurante ===\n");
        printf("1. Clientes\n");
        printf("2. Mesas\n");
        printf("3. Pedidos\n");
        printf("4. Produtos\n");
        printf("5. Categorias de Produto\n");
        printf("6. Itens de Pedido\n");
        printf("7. Pagamentos\n");
        printf("8. Promocoes\n");
        printf("9. Funcionarios\n");
        printf("10. Reservas\n");
        printf("11. Relatorios\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
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
            case 5:
                printf("\nCategorias de Produto selecionado.\n");
                menuCategoriasProduto();
                break;
            case 6:
                printf("\nItens de Pedido selecionado.\n");
                menuItensPedido();
                break;
            case 7:
                printf("\nPagamentos selecionado.\n");
                menuPagamentos();
                break;
            case 8:
                printf("\nPromocoes selecionado.\n");
                menuPromocoes();
                break;
            case 9:
                printf("\nFuncionarios selecionado.\n");
                menuFuncionarios();
                break;
            case 10:
                printf("\nReservas selecionado.\n");
                menuReservas();
                break;
            case 11:
                menuRelatorios();
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
        getchar(); // Limpa o buffer antes de ler string
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
                getchar(); // Limpa o buffer antes de ler string
                editarCliente(id);
                break;
            case 4:
                printf("\nRemover Cliente selecionado.\n");
                printf("Digite o ID do cliente a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
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
    int id;
    do {
        printf("\n=== Menu Mesas ===\n");
        printf("1. Adicionar Mesa\n");
        printf("2. Listar Mesas\n");
        printf("3. Editar Mesa\n");
        printf("4. Remover Mesa\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                printf("\nAdicionar Mesa selecionado.\n");
                cadastrarMesa();
                break;
            case 2:
                printf("\nListar Mesas selecionado.\n");
                listarMesas();
                break;
            case 3:
                printf("\nEditar Mesa selecionado.\n");
                printf("Digite o ID da mesa a ser editada: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarMesa(id);
                break;
            case 4:
                printf("\nRemover Mesa selecionado.\n");
                printf("Digite o ID da mesa a ser removida: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerMesa(id);
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
    int id;
    do {
        printf("\n=== Menu Pedidos ===\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Listar Pedidos\n");
        printf("3. Editar Pedido\n");
        printf("4. Remover Pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                printf("Adicionar Pedido selecionado.\n");
                cadastrarPedido();
                break;
            case 2:
                printf("Listar Pedidos selecionado.\n");
                listarPedidos();
                break;
            case 3:
                printf("Editar Pedido selecionado.\n");
                printf("Digite o ID do pedido a ser editado: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarPedido(id);
                break;
            case 4:
                printf("Remover Pedido selecionado.\n");
                printf("Digite o ID do pedido a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerPedido(id);
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
    int opcao, id;
    do {
        printf("\n=== Menu Produtos ===\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Editar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                printf("Digite o ID do produto a ser editado: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarProduto(id);
                break;
            case 4:
                printf("Digite o ID do produto a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerProduto(id);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuCategoriasProduto() {
    int opcao, id;
    do {
        printf("\n=== Menu Categorias de Produto ===\n");
        printf("1. Adicionar Categoria\n");
        printf("2. Listar Categorias\n");
        printf("3. Editar Categoria\n");
        printf("4. Remover Categoria\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                cadastrarCategoriaProduto();
                break;
            case 2:
                listarCategoriasProduto();
                break;
            case 3:
                printf("Digite o ID da categoria a ser editada: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarCategoriaProduto(id);
                break;
            case 4:
                printf("Digite o ID da categoria a ser removida: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerCategoriaProduto(id);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuItensPedido() {
    int opcao, id;
    do {
        printf("\n=== Menu Itens de Pedido ===\n");
        printf("1. Adicionar Item ao Pedido\n");
        printf("2. Listar Itens de Pedido\n");
        printf("3. Editar Item de Pedido\n");
        printf("4. Remover Item de Pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                cadastrarItemPedido();
                break;
            case 2:
                listarItensPedido();
                break;
            case 3:
                printf("Digite o ID do item a ser editado: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarItemPedido(id);
                break;
            case 4:
                printf("Digite o ID do item a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerItemPedido(id);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuPagamentos() {
    int opcao, id;
    do {
        printf("\n=== Menu Pagamentos ===\n");
        printf("1. Adicionar Pagamento\n");
        printf("2. Listar Pagamentos\n");
        printf("3. Editar Pagamento\n");
        printf("4. Remover Pagamento\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                cadastrarPagamento();
                break;
            case 2:
                listarPagamentos();
                break;
            case 3:
                printf("Digite o ID do pagamento a ser editado: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarPagamento(id);
                break;
            case 4:
                printf("Digite o ID do pagamento a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerPagamento(id);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuPromocoes() {
    int opcao, id;
    do {
        printf("\n=== Menu Promocoes ===\n");
        printf("1. Adicionar Promocao\n");
        printf("2. Listar Promocoes\n");
        printf("3. Editar Promocao\n");
        printf("4. Remover Promocao\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                cadastrarPromocao();
                break;
            case 2:
                listarPromocoes();
                break;
            case 3:
                printf("Digite o ID da promocao a ser editada: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarPromocao(id);
                break;
            case 4:
                printf("Digite o ID da promocao a ser removida: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerPromocao(id);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuFuncionarios() {
    int opcao;
    int id;
    do {
        printf("\n=== Menu Funcionários ===\n");
        printf("1. Adicionar Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("3. Editar Funcionário\n");
        printf("4. Remover Funcionário\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                printf("Adicionar Funcionário selecionado.\n");
                cadastrarFuncionario();
                break;
            case 2:
                printf("Listar Funcionários selecionado.\n");
                listarFuncionarios();
                break;
            case 3:
                printf("Editar Funcionário selecionado.\n");
                printf("Digite o ID do funcionário a ser editado: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarFuncionario(id);
                break;
            case 4:
                printf("Remover Funcionário selecionado.\n");
                printf("Digite o ID do funcionário a ser removido: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerFuncionario(id);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuReservas() {
    int opcao;
    int id;
    do {
        printf("\n=== Menu Reservas ===\n");
        printf("1. Adicionar Reserva\n");
        printf("2. Listar Reservas\n");
        printf("3. Editar Reserva\n");
        printf("4. Remover Reserva\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                printf("Adicionar Reserva selecionado.\n");
                cadastrarReserva();
                break;
            case 2:
                printf("Listar Reservas selecionado.\n");
                listarReservas();
                break;
            case 3:
                printf("Editar Reserva selecionado.\n");
                printf("Digite o ID da reserva a ser editada: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                editarReserva(id);
                break;
            case 4:
                printf("Remover Reserva selecionado.\n");
                printf("Digite o ID da reserva a ser removida: ");
                scanf("%d", &id);
                getchar(); // Limpa o buffer antes de ler string
                removerReserva(id);
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
        printf("\n=== Menu Relatorios ===\n");
        printf("1. Relatorio de Vendas\n");
        printf("2. Relatorio de Clientes\n");
        printf("3. Relatorio de Mesas\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer antes de ler string
        switch (opcao) {
            case 1:
                relatorioVendas();
                break;
            case 2:
                relatorioClientes();
                break;
            case 3:
                relatorioMesas();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}