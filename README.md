# 🍽️ Sistema de Restaurante em C

## Descrição: 
Este repositório apresenta a implementação de um **Sistema de Administração de Restaurante** desenvolvido em linguagem **C**, utilizando **programação estruturada**. O projeto simula o funcionamento interno de um restaurante, oferecendo um ambiente digital para o gerenciamento de suas principais operações — como controle de clientes, pedidos, mesas, produtos, reservas, pagamentos e promoções.

Idealizado para fins acadêmicos e educacionais, o sistema reforça conceitos fundamentais da linguagem C, como **uso de structs**, **ponteiros**, **alocação dinâmica de memória**, **manipulação de arquivos** e **organização modular do código**. A interface é baseada em menus de texto simples, mas eficazes, voltados para facilitar a interação por parte de operadores e gestores.

## 🎯 Objetivo:
Automatizar processos comuns de restaurantes de pequeno e médio porte, com foco na organização das entidades envolvidas na operação do negócio. O sistema substitui processos manuais por um controle digital unificado, visando reduzir erros operacionais e melhorar a eficiência do serviço.

---

## 📦 Funcionalidades Principais
- Cadastro, edição, exclusão e consulta de:
  - Clientes
  - Funcionários
  - Produtos
- Gerenciamento de:
  - Pedidos e Itens de Pedido
  - Pagamentos
  - Promoções
  - Reservas e Mesas
- Organização por Categorias de Produto
- Interface por linha de comando (CLI)
- Armazenamento de dados em arquivos

---

## 🧱 Estruturas de Dados (Structs)
O sistema é estruturado com as seguintes entidades:

- **Cliente**: `id`, `nome`, `telefone`, `CPF`, `email`, `fidelidade`
- **Mesa**: `id`, `número`, `capacidade`, `status`, `garçom_id`, `localização`
- **Pedido**: `id`, `cliente_id`, `mesa_id`, `data`, `status`, `valor_total`
- **ItemPedido**: `id`, `pedido_id`, `produto_id`, `quantidade`, `preco_unitario`, `subtotal`
- **Produto**: `id`, `nome`, `categoria`, `preço`, `estoque`, `descrição`
- **Funcionário**: `id`, `nome`, `cargo`, `salário`, `turno`, `telefone`
- **CategoriaProduto**: `id`, `nome`, `descrição`, `horário_disponível`, `prioridade`, `tipo`
- **Pagamento**: `id`, `pedido_id`, `valor`, `forma_pagamento`, `data`, `status`
- **Promoção**: `id`, `nome`, `tipo`, `valor`, `validade`, `produto_id`
- **Reserva**: `id`, `cliente_id`, `data`, `hora`, `mesa_id`, `status`

--- 

## 🚀 Tecnologias Utilizadas
- Linguagem C
- Programação Estruturada
- Manipulação de Arquivos
- Interface de Texto (CLI)

---

## 🛠️ Compilação e Execução
Para compilar o projeto, utilize um compilador C como `gcc`:

```bash
gcc -o restaurante main.c
./restaurante
