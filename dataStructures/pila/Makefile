# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Archivos fuente
SRC = tests/test_header.c
TARGET = test_header

# Regla por defecto
all: $(TARGET)

# Compilación
$(TARGET): $(SRC)
	@echo "🔧 Compilando archivo de test: $(SRC)"
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Ejecuta los tests después de compilar
run: $(TARGET)
	@echo "🚀 Ejecutando pruebas..."
	./$(TARGET)

# Limpieza de ejecutable
clean:
	@echo "🧹 Limpiando archivos generados..."
	rm -f $(TARGET)
