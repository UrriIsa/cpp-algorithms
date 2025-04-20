#ifndef COLECCION_H
#define COLECCION_H

#include <stdbool.h>
#include <stddef.h> // Para size_t

// Declaración adelantada de la estructura Collection.
typedef struct Colección Colección ;

// Definición de la vtable con métodos genéricos.
typedef struct {
    bool (*isEmpty) (Colección *self) ; 
    size_t (*size) (Colección *self ) ;
    bool (*contains) (Colección *self, const void *element) ;
    void (*clear) (Colección *self) ;

   /*toString()
    equals()
    retainAll(Collection<?> c) 
    removeAll(Collection<?> c)
    remove(Object o) 
    addAll(Collection<? extends E> c)
    containsAll(Collection<?> c) */

} ColecciónVTable;

// Estructura base "abstracta".
struct Colección {
    ColecciónVTable *vtable ;
    size_t tam ;
    void **data ;                    // Arreglo de punteros a elementos
    int (*compare)(const void *a, const void *b) ; // Función de comparación para determinar igualdad entre elementos. Por convención, debe devolver 0 si los elementos son iguales.
} ;


// Métodos genéricos en la base:
bool colecciónIsEmpty(Colección *self) ;
size_t colecciónSize(Colección *self) ;
bool colecciónContains(Colección *self, const void *element) ;
void colecciónClear(Colección *self) ;


#endif // COLLECTION_H




