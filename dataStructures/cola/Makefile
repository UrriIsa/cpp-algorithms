# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Archivos fuente
SRC = tests/tests.c
TARGET = testc

# Regla por defecto
all: $(TARGET)

# Compilación
$(TARGET): $(SRC)
	@echo "Compilando archivo de test: $(SRC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Ejecuta los tests después de compilar
test: $(TARGET)
	@echo "Ejecutando pruebas..."
	@echo
	@./$(TARGET)

# Limpieza de ejecutable
clean:
	@echo "Limpiando archivos generados..."
	@rm -f $(TARGET)
