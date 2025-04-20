#include "ColecciónAbstracta.h"
#include "Comparadores.h"
#include <stdbool.h>

// Implementación de los métodos comunes:

bool collectionIsEmpty(Colección *self) {
    return self->tam == 0;
}

size_t collectionSize(Colección *self) {
    return self->tam;
}

void collectionClear(Colección *self) {
    if (self == NULL) return; // Verifica que la instancia no sea NULL

    // Liberar los elementos del arreglo `data`
    for (size_t i = 0; i < self->tam; ++i) {
        free(self->data[i]); // Liberar cada elemento dinámico
        self->data[i] = NULL; // Prevenir acceso accidental
    }

    // Liberar el arreglo `data`
    free(self->data);
    self->data = NULL; // Prevenir acceso accidental

    // Liberar la estructura principal
    free(self);

    self->tam = 0;
}

bool collectionContains(Colección *self, int element) {
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
