# 🍽️ Sistema de Restaurante em C

## Descrição
Este repositório apresenta a implementação de um **Sistema de Administração de Restaurante** desenvolvido em linguagem **C**, utilizando **programação estruturada**. O projeto simula o funcionamento interno de um restaurante, oferecendo um ambiente digital para o gerenciamento de suas principais operações — como controle de clientes, pedidos, mesas, produtos, reservas, pagamentos, promoções e categorias de produto.

Idealizado para fins acadêmicos e educacionais, o sistema reforça conceitos fundamentais da linguagem C, como **uso de structs**, **ponteiros**, **manipulação de arquivos** e **organização modular do código**. A interface é baseada em menus de texto simples, voltados para facilitar a interação por parte de operadores e gestores.

---

## 🎯 Objetivo
Automatizar processos comuns de restaurantes de pequeno e médio porte, com foco na organização das entidades envolvidas na operação do negócio. O sistema substitui processos manuais por um controle digital unificado, visando reduzir erros operacionais e melhorar a eficiência do serviço.

---

## 📦 Funcionalidades Principais
- Cadastro, edição, exclusão e consulta de:
  - Clientes
  - Funcionários
  - Produtos
  - Categorias de Produto
- Gerenciamento de:
  - Pedidos e Itens de Pedido
  - Pagamentos
  - Promoções
  - Reservas e Mesas
- Relatórios de vendas, clientes e mesas
- Interface por linha de comando (CLI)
- Armazenamento de dados em arquivos binários

---

## 🧱 Estruturas de Dados (Structs)
O sistema é estruturado com as seguintes entidades:

- **Cliente**: `id`, `nome`, `telefone`, `CPF`, `email`, `fidelidade`
- **Mesa**: `id`, `número`, `capacidade`, `status`, `garçom_id`, `cliente_id`, `data_reserva`, `localização`
- **Pedido**: `id`, `cliente_id`, `mesa_id`, `data`, `status`, `valor_total`
- **ItemPedido**: `id`, `pedido_id`, `produto_id`, `quantidade`, `preco_unitario`, `subtotal`
- **Produto**: `id`, `nome`, `categoria`, `preço`, `estoque`, `descrição`
- **Funcionário**: `id`, `nome`, `cargo`, `salário`, `turno`, `telefone`
- **CategoriaProduto**: `id`, `nome`, `descrição`, `horário_disponível`, `prioridade`, `tipo`
- **Pagamento**: `id`, `pedido_id`, `valor`, `forma_pagamento`, `status`, `data`
- **Promoção**: `id`, `nome`, `tipo`, `valor`, `validade`, `produto_id`
- **Reserva**: `id`, `cliente_id`, `data`, `hora`, `mesa_id`, `status`

---

## 🚀 Tecnologias Utilizadas
- Linguagem C (C99)
- Programação Estruturada
- Manipulação de Arquivos Binários
- Interface de Texto (CLI)

---

## 🛠️ Compilação e Execução
### Pré-requisitos
- GCC ou outro compilador C compatível
- Make (opcional, mas recomendado)

### Compilação via Makefile (recomendado)
Abra o terminal na pasta do projeto e execute:

```sh
make
```

### Compilação manual
```sh
gcc main.c functions.c cliente.c mesas.c pedido.c funcionarios.c reserva.c pagamento.c promocao.c produto.c item_pedido.c categoria_produto.c relatorios.c -o sistema-restaurante.exe
```

### Execução
```sh
./sistema-restaurante.exe
```

---

## 📝 Organização dos Arquivos
- `main.c`: Função principal e inicialização do menu
- `functions.c/.h`: Menus e integração dos módulos
- `cliente.c/.h`, `mesas.c/.h`, `pedido.c/.h`, etc.: CRUD de cada entidade
- `structs.h`: Definição das structs principais
- `relatorios.c/.h`: Relatórios do sistema
- `Makefile`: Script de build automatizado

---

## 💡 Comentários e Dicas de Uso
- **Cadastro de Mesas**: Para associar um cliente à mesa, escolha o status "ocupada" e selecione o cliente.
- **Pedidos**: Só é possível cadastrar pedidos para mesas ocupadas ou reservadas pelo cliente.
- **Itens do Pedido**: Após cadastrar um pedido, adicione itens ao pedido pelo menu.
- **Relatórios**: Acesse relatórios de vendas, clientes e mesas pelo menu principal.
- **Strings com Espaços**: O sistema aceita nomes, descrições e outros campos com espaços.
- **Persistência**: Todos os dados são salvos em arquivos binários automaticamente.

---

## 📚 Documentação do Código
- Cada arquivo `.c` possui comentários explicativos nas funções principais.
- As funções CRUD seguem o padrão: `cadastrarX`, `listarX`, `editarX`, `removerX`, `salvarX`, `carregarX`.
- Os menus estão em `functions.c` e são facilmente extensíveis.
- O código é modular, facilitando manutenção e expansão.

---

## 🤝 Contribuição
Pull requests e sugestões são bem-vindos! Sinta-se à vontade para propor melhorias, correções ou novas funcionalidades.

---

## 🏷️ Licença
Este projeto é livre para fins acadêmicos e educacionais.
