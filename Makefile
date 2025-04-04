# Nombre del ejecutable
EJECUTABLE = app1

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Archivos fuente
SRC = main.c utils.c 
OBJ = $(SRC:.c=.o)


# Regla principal
all: $(EJECUTABLE)

# Compilar el ejecutable
$(EJECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EJECUTABLE) $(OBJ)

# Compilar archivos .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos .o
# Limpiar archivos .exe
clean:
	del /f /q $(OBJ) 
	del *.exe