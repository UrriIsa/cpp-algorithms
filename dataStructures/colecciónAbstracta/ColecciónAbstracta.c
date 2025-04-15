#include "ColecciónAbstracta.h"
#include "Comparadores.h"
#include <stdbool.h>

// Implementación de los métodos comunes:

bool collectionIsEmpty(Collection *self) {
    return self->tam == 0;
}

size_t collectionSize(Collection *self) {
    return self->tam;
}

void collectionClear(Collection *self) {
    // Este método debe ser sobrescrito en las estructuras derivadas.
    // Por ejemplo, liberando memoria específica.
    self->tam = 0;
}

bool collectionContains(Collection *self, int element) {
    if (!self || !self->data) {
        return false;
    }
    
    // Iteramos sobre cada elemento almacenado.
    for (size_t i = 0; i < self->tam; i++) {
        // Usamos la función de comparación asignada en self->compare.
        // Por convención, compare devuelve 0 si los dos elementos son iguales.
        if (self->compare && self->compare(self->data[i], element) == 0) {
            return true;
        }
    }
}


bool colecciónIsEmpty(Colección *self) ;
size_t colecciónSize(Colección *self) ;
bool colecciónContains(Colección *self, const void *element) ;
void colecciónClear(Colección *self) ;
