# --- Variáveis de compilador e flags ---
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -I./include

# --- Fontes e objetos ---
SRCS    := src/cpu_test.c \
           src/instructions.c

# Gera a lista de objetos a partir dos .c
# Ex: src/foo.c -> foo.o
OBJS    := $(patsubst src/%.c,%.o,$(SRCS))

TARGET  := cpu_sim

# --- Regra padrão (gera o executável) ---
all: $(TARGET)

# Linka os objetos e gera o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Regra genérica para compilar qualquer .c em src/ para um .o na raiz
# Exemplo: src/foo.c -> foo.o
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
