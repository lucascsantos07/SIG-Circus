# Pego do Chat GPT 5
# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Arquivos fontes
SRC = main.c Informacoes/informacoes.c Agendamentos/agendamentos.c Clientes/clientes.c Funcionarios/funcionarios.c Utilitarios/utilitarios.c Ingressos/ingressos.c Interfaces/interface.c Validacao/validacao.c

# Objetos gerados
OBJ = $(SRC:.c=.o)

# Nome do executável
TARGET = programa

# Regra principal
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Como gerar os .o a partir dos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
ifeq ($(OS),Windows_NT)
	del /Q $(OBJ) $(TARGET).exe
else
	rm -f $(OBJ) $(TARGET)
endif

# Recompilar do zero
rebuild: clean all

# Executar o programa
run: $(TARGET)
ifeq ($(OS),Windows_NT)
	.\$(TARGET).exe
else
	./$(TARGET)
endif
