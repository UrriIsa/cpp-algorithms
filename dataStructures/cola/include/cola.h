#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


#define COLA_DCLR(T, NOMBRE)                                            \
                                                                        \
    typedef struct Elmt##NOMBRE{                                        \
        T dato ;                                                        \
        struct Elmt##NOMBRE* ant ;                                      \
    } Elmt##NOMBRE ;                                                    \
                                                                        \
    typedef struct{                                                     \
        Elmt##NOMBRE* cabeza ;                                          \
        Elmt##NOMBRE* fin ;                                             \
        int tam ;                                                       \
    } Cola##NOMBRE ;                                                    \
                                                                        \
    typedef struct {                                                    \
        bool valido ;                                                   \
        T   valor ;                                                     \
    } ResCola##NOMBRE ;                                                 \
                                                                        \
    static inline ResCola##NOMBRE NOMBRE##CMira(Cola##NOMBRE* c){       \
        ResCola##NOMBRE res = { .valido = false } ;                     \
                                                                        \
        if(c->cabeza){                                                  \
            res.valor = c->cabeza->dato ;                               \
            res.valido = true ;                                         \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline ResCola##NOMBRE NOMBRE##CExpulsa(Cola##NOMBRE* c){    \
        ResCola##NOMBRE res = { .valido = false } ;                      \
                                                                        \
        if (c->cabeza) {                                                \
            Elmt##NOMBRE* el = c->cabeza ;                              \
            res.valor = el->dato ;                                      \
            res.valido = true ;                                         \
            c->cabeza = el->ant ;                                       \
            c->tam-- ;                                                  \
            if (c->cabeza == NULL)                                         \
            c->fin = NULL;                                             \
            free(el);                                                      \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline void NOMBRE##CAgrega(Cola##NOMBRE* c, T valor) {         \
        Elmt##NOMBRE* el = malloc(sizeof(Elmt##NOMBRE));                   \
        el->dato = valor;                                                  \
        el->ant = NULL;                                                    \
        if (c->fin)                                                       \
            c->fin->ant = el;                                              \
        else                                                               \
            c->cabeza = el;                                                \
        c->fin = el;                                                       \
        c->tam++;                                                          \
    }                                                                      \
                                                                        \
    static inline void NOMBRE##CVaciar(Cola##NOMBRE* c) {                  \
        while (c->cabeza) {                                                \
            Elmt##NOMBRE* tmp = c->cabeza;                                 \
            c->cabeza = c->cabeza->ant;                                    \
            free(tmp);                                                     \
        }                                                                  \
        c->fin = NULL;                                                     \
        c->tam = 0;                                                        \
    }                                                                      \
                                                                        \
    static inline bool NOMBRE##CEsVacia(Cola##NOMBRE* c){               \
        return c->cabeza == NULL ;                                         \
    }                                                                   \

#endif