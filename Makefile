CC = gcc
SRC = main.c functions.c cliente.c mesas.c pedido.c funcionarios.c reserva.c pagamento.c promocao.c produto.c item_pedido.c categoria_produto.c relatorios.c
OUT = sistema-restaurante.exe

all: 
	$(CC) $(SRC) -o $(OUT)
	@echo "Compilação concluída com sucesso!"
run: all
	./$(OUT)
	@echo "Execução concluída com sucesso!"
