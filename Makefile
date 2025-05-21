CC = gcc
SRC = main.c functions.c cliente.c
OUT = sistema-restaurante.exe

all: 
	$(CC) $(SRC) -o $(OUT)
	@echo "Compilação concluída com sucesso!"
run: all
	./$(OUT)
	@echo "Execução concluída com sucesso!"
