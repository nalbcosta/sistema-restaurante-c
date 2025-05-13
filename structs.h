// Structs do Sistema do Restaurante

//1. Cliente
typedef struct {
  int id;              // Identificador único do cliente
  char nome[50];       // Nome do cliente (Limitado a 50 caracteres)
  char telefone[15];   // Telefone do cliente (Limitado a 15 caracteres)
  char cpf[15];        // CPF do cliente (Limitado a 15 caracteres)
  char email[80];      // Email do cliente (Limitado a 80 caracteres)
  int fidelidade;      // Pontos de fidelidade do cliente
} Cliente;

//2. Mesa
typedef struct {
  int id;              // Identificador único da mesa
  int numero;          // Número da mesa
  int capacidade;      // Capacidade da mesa (número de pessoas)
  char status[10];     // Status da mesa (disponível, ocupada, reservada)
  int garcom_id;       // Identificador do garçom responsável pela mesa
  char localizacao[20];  // Localização da mesa (ex: interior, varanda, terraço)
} Mesa;

//3. Pedido
typedef struct{
  int id;              // Identificador único do pedido
  int cliente_id;      // Identificador do cliente que fez o pedido
  int mesa_id;         // Identificador da mesa onde o pedido foi feito
  char data[20];       // Data do pedido (formato: DD/MM/AAAA)
  char status[10];     // Status do pedido (em andamento, concluído, cancelado)
  float valor_total;   // Valor total do pedido
} Pedido;

//4. ItemPedido
typedef struct{
  int id;              // Identificador único do item do pedido
  int pedido_id;       // Identificador do pedido ao qual o item pertence
  int produto_id;      // Identificador do produto que foi pedido
  int quantidade;      // Quantidade do produto que foi pedido
  float preco_unitario;    // Preço unitário do produto
  float subtotal;      // Subtotal do item do pedido (quantidade * preco_unitario)
} ItemPedido;

//5. Produto
typedef struct{
  int id;              // Identificador único do produto
  char nome[50];       // Nome do produto (Limitado a 50 caracteres)
  char categoria[20];  // Categoria do produto (ex: prato principal, sobremesa, bebida)
  float preco;         // Preço do produto
  int estoque;         // Quantidade em estoque do produto
  char descricao[200];  // Descrição do produto (Limitado a 200 caracteres)
} Produto;

//6. Funcionário
typedef struct{
  int id;              // Identificador único do funcionário
  char nome[50];       // Nome do funcionário (Limitado a 50 caracteres)
  char cargo[20];      // Cargo do funcionário (ex: gerente, garçom, cozinheiro)
  float salario;       // Salário do funcionário
  char turno[10];      // Turno de trabalho do funcionário (ex: manhã, tarde, noite)
  char telefone[15];   // Telefone do funcionário (Limitado a 15 caracteres)
} Funcionario;

//7. CategoriaProduto
typedef struct{
  int id;              // Identificador único da categoria do produto
  char nome[50];       // Nome da categoria do produto (Limitado a 50 caracteres)
  char descricao[200];  // Descrição da categoria do produto (Limitado a 200 caracteres)
  char horario_disponivel[20];  // Horário disponível para consumo (ex: almoço, jantar, 24 horas)
  char prioridade[10];  // Prioridade da categoria (ex: alta, média, baixa)
  char tipo[20];       // Tipo da categoria (ex: prato principal, sobremesa, bebida)
} CategoriaProduto;

//8. Pagamento
typedef struct{
  int id;              // Identificador único do pagamento
  int pedido_id;       // Identificador do pedido ao qual o pagamento pertence
  float valor;         // Valor do pagamento
  char forma_pagamento[20];  // Forma de pagamento (ex: cartão de crédito, dinheiro, pix)
  char status[10];     // Status do pagamento (aprovado, recusado, pendente)
  char data[20];       // Data do pagamento (formato: DD/MM/AAAA)
} Pagamento;

//9. Promoção
typedef struct{
  int id;              // Identificador único da promoção
  char nome[50];       // Nome da promoção (Limitado a 50 caracteres)
  char tipo[20];       // Tipo da promoção (ex: desconto, combo, happy hour)
  float valor;         // Valor da promoção (ex: 10% de desconto, valor fixo)
  char validade[20];   // Validade da promoção (formato: DD/MM/AAAA)
  int produto_id;      // Identificador do produto ao qual a promoção se aplica
} Promocao;

//10. Reserva
typedef struct{
  int id;              // Identificador único da reserva
  int cliente_id;      // Identificador do cliente que fez a reserva
  char data[20];       // Data da reserva (formato: DD/MM/AAAA)
  char hora[10];       // Hora da reserva (formato: HH:MM)
  int mesa_id;         // Identificador da mesa reservada
  char status[10];     // Status da reserva (confirmada, cancelada, pendente)
} Reserva;