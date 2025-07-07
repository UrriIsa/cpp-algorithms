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

#define PILA_DCLR(T, NOMBRE)                                            \
                                                                        \
    typedef struct Elmt##NOMBRE{                                        \
        T dato ;                                                        \
        struct Elmt##NOMBRE* sig ;                                      \
    } Elmt##NOMBRE ;                                                    \
                                                                        \
    typedef struct{                                                     \
        Elmt##NOMBRE* tope ;                                            \
        int tam ;                                                       \
    } Pila##NOMBRE ;                                                    \
                                                                        \
    typedef struct {                                                    \
        bool valido ;                                                   \
        T   valor ;                                                     \
    } ResPil##NOMBRE ;                                                  \
                                                                        \
    static inline void NOMBRE##PAgrega(Pila##NOMBRE* p, T valor){       \
        Elmt##NOMBRE* el = malloc(sizeof(Elmt##NOMBRE)) ;               \
        el->dato = valor ;                                              \
        el->sig = p->tope ;                                             \
        p->tope = el ;                                                  \
        p->tam ++ ;                                                     \
    }                                                                   \
                                                                        \
    static inline ResPil##NOMBRE NOMBRE##PExpulsa(Pila##NOMBRE* p){     \
        ResPil##NOMBRE res = { .valido = false } ;                      \
                                                                        \
        if (p->tope) {                                                  \
            Elmt##NOMBRE* el = p->tope ;                                \
            res.valor = el->dato ;                                      \
            res.valido = true ;                                         \
            p->tope = el->sig ;                                         \
            p->tam-- ;                                                  \
            free(el) ;                                                  \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline bool NOMBRE##PEsVacia(Pila##NOMBRE* p){               \
        return p->tope == NULL ;                                        \
    }                                                                   \
                                                                        \
    static inline ResPil##NOMBRE NOMBRE##PMira(Pila##NOMBRE* p){        \
        ResPil##NOMBRE res = { .valido = false } ;                      \
                                                                        \
        if(p->tope){                                                    \
            res.valor = p->tope->dato ;                                 \
            res.valido = true ;                                         \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline void NOMBRE##PVacia(Pila##NOMBRE* p){                 \
        p->tope = NULL ;                                                \
        p->tam = 0 ;                                                    \
    }                                                                   \

#endif