#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* 
  DCLR_PILA(T, NOMBRE):
    - T: el tipo de elemento (int, float, struct MiTipo, …)
    - NOMBRE: prefijo para los tipos y funciones (p.ej. “Int” o “Flt”)


    pop es elimina
    peek es mira
    push es agrega   

     0 = vacío, 1 = éxito
*/

#define DCLR_PILA(T, NOMBRE)                                            \
                                                                        \
    typedef struct NOMBRE##Elmt{                                        \
        T dato ;                                                        \
        struct NOMBRE##Elmt* sig ;                                      \
    } NOMBRE##Elmt ;                                                    \
                                                                        \
    typedef struct{                                                     \
        NOMBRE##Elmt* tope ;                                            \
    } NOMBRE##Pila ;                                                    \
                                                                        \
    typedef struct {                                                    \
        int valido ;                                                    \
        T   valor ;                                                     \
    } NOMBRE##Result ;                                                  \
                                                                        \
    static inline void NOMBRE##_agrega(NOMBRE##Pila* p, T valor){       \
        NOMBRE##Elmt* el = malloc(sizeof(NOMBRE##Elmt)) ;               \
        el->dato = valor ;                                              \
        el->sig = p->tope ;                                             \
        p->tope = el ;                                                  \
    }                                                                   \
                                                                        \
    static inline NOMBRE##Result NOMBRE##_elimina(NOMBRE##Pila* p){     \
        NOMBRE##Result res = { .valido = 0 };                           \
                                                                        \
        if (p->tope) {                                                  \
            NOMBRE##Elmt* el = p->tope ;                                \
            res.valor = el->dato ;                                      \
            res.valido = 1 ;                                            \
            p->tope = el->sig ;                                         \
            free(el) ;                                                  \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline bool NOMBRE##_esVacio(NOMBRE##Pila* p){               \
        return p->tope == NULL ;                                        \
    }                                                                   \
                                                                        \
    static inline NOMBRE##Result NOMBRE##_mira(NOMBRE##Pila* p){        \
        NOMBRE##Result res = { .valido = 0 } ;                          \
                                                                        \
        if(p->tope){                                                    \
            res.valor = p->tope->dato ;                                 \
            res.valido = 1 ;                                            \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \

#endif