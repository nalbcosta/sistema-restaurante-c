#include "relatorios.h"
#include "pedido.h"
#include "cliente.h"
#include "mesas.h"
#include "funcionarios.h"
#include <stdio.h>
#include <string.h>

void relatorioVendas() {
    printf("\n=== Relatorio de Vendas ===\n");
    carregarPedidos();
    carregarClientes();
    float totalVendas = 0;
    int encontrou = 0;
    for (int i = 0; i < 500; i++) {
        Pedido* p = buscarPedidoPorId(i+1);
        if (p && strcmp(p->status, "concluido") == 0) {
            Cliente* c = buscarClientePorId(p->cliente_id);
            printf("Pedido ID: %d | Cliente: %s | Mesa: %d | Data: %s | Valor: %.2f\n",
                p->id, c ? c->nome : "(desconhecido)", p->mesa_id, p->data, p->valor_total);
            totalVendas += p->valor_total;
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhuma venda concluida encontrada.\n");
    printf("Total de vendas: R$ %.2f\n", totalVendas);
}

void relatorioClientes() {
    printf("\n=== Relatorio de Clientes ===\n");
    carregarClientes();
    for (int i = 0; i < 100; i++) {
        Cliente* c = buscarClientePorId(i+1);
        if (c) {
            printf("ID: %d | Nome: %s | Telefone: %s | CPF: %s | Email: %s | Fidelidade: %d\n",
                c->id, c->nome, c->telefone, c->cpf, c->email, c->fidelidade);
        }
    }
}

void relatorioMesas() {
    printf("\n=== Relatorio de Mesas ===\n");
    carregarMesas();
    carregarFuncionarios();
    carregarClientes();
    for (int i = 0; i < 100; i++) {
        Mesa* m = buscarMesaPorId(i+1);
        if (m) {
            Funcionario* f = buscarFuncionarioPorId(m->garcom_id);
            Cliente* c = buscarClientePorId(m->cliente_id);
            printf("ID: %d | Numero: %d | Capacidade: %d | Status: %s | Garcom: %s | Cliente: %s | Localizacao: %s\n",
                m->id, m->numero, m->capacidade, m->status,
                f ? f->nome : "(nenhum)",
                c ? c->nome : "(nenhum)",
                m->localizacao);
        }
    }
}
