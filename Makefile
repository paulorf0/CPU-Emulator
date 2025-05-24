# --- Variáveis de compilador e flags ---
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 \
          -I./assembly \
          -I./compiler \
          -I./handlers \
          -I./hardware \
          -I./software

# --- Fontes e objetos ---
SRCS    = software/Test.c \
          handlers/handler.c

OBJS    = Test.o \
          handler.o

TARGET  = cpu_sim

# --- Regra padrão (gera o executável) ---
all: $(TARGET)

# Linka os objetos e gera o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compila software/Test.c para Test.o
Test.o: software/Test.c
	$(CC) $(CFLAGS) -c software/Test.c -o Test.o

# Compila handlers/handler.c para handler.o
handler.o: handlers/handler.c
	$(CC) $(CFLAGS) -c handlers/handler.c -o handler.o

# Remove executável e arquivos .o
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
