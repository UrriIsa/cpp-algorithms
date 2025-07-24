/**
 * @file cola.n
 * 
 * @brief [ES] Macro genérica para crear colas de tipo T.
 * @brief [EN] Generic macro to create queues of type T.
 * 
 * @author: Isaac Urrutia-Alfaro
 * License: MIT License
 * Copyright (c) 2025 Isaac Urrutia-Alfaro
 * 
 * @details [ES]
 *   Esta macro genera:
 *     - ElmtNOMBRE : elemento (nodo) interno.
 *     - ColaNOMBRE : estructura de la cola (cabeza, fin, tamaño).
 *     - ResColaNOMBRE : tipo de resultado para operaciones de añadir y extraer.
 *     - NOMBRE##CAgrega : añade.
 *     - NOMBRE##CExpulsa : extrae.
 *     - NOMBRE##CEsVacia : comprueba vacío.
 *     - NOMBRE##CMira : mira sin extraer.
 *     - NOMBRE##CVaciar : vacía la pila.
 *
 * @details [EN]
 *   This macro generates :
 *     - ElmtNOMBRE : internal element (node).
 *     - ColaNOMBRE : queue structure (head, tail, size).
 *     - ResColaNOMBRE : result of enqueue/dequeue.
 *     - NOMBRE##CAgrega : enqueue.
 *     - NOMBRE##CExpulsa : dequeue.
 *     - NOMBRE##CEsVacia : is_empty.
 *     - NOMBRE##CMira : peek.
 *     - NOMBRE##CVaciar : clear.
 *
 * @param T
 *  [ES] : Tipo de los elementos.
 *  [EN] : Type of the elements.
 * @param NOMBRE
 *  [ES] : Prefijo para tipos y funciones.
 *  [EN] : Prefix for types and functions.
 */

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
        ResCola##NOMBRE res = { .valido = false } ;                     \
                                                                        \
        if (c->cabeza) {                                                \
            Elmt##NOMBRE* el = c->cabeza ;                              \
            res.valor = el->dato ;                                      \
            res.valido = true ;                                         \
            c->cabeza = el->ant ;                                       \
            c->tam-- ;                                                  \
            if (c->cabeza == NULL)                                      \
            c->fin = NULL;                                              \
            free(el);                                                   \
        }                                                               \
                                                                        \
        return res ;                                                    \
    }                                                                   \
                                                                        \
    static inline void NOMBRE##CAgrega(Cola##NOMBRE* c, T valor) {      \
        Elmt##NOMBRE* el = malloc(sizeof(Elmt##NOMBRE));                \
        el->dato = valor;                                               \
        el->ant = NULL;                                                 \
        if (c->fin)                                                     \
            c->fin->ant = el;                                           \
        else                                                            \
            c->cabeza = el;                                             \
        c->fin = el;                                                    \
        c->tam++;                                                       \
    }                                                                   \
                                                                        \
    static inline void NOMBRE##CVaciar(Cola##NOMBRE* c) {               \
        while (c->cabeza) {                                             \
            Elmt##NOMBRE* tmp = c->cabeza;                              \
            c->cabeza = c->cabeza->ant;                                 \
            free(tmp);                                                  \
        }                                                               \
        c->fin = NULL;                                                  \
        c->tam = 0;                                                     \
    }                                                                   \
                                                                        \
    static inline bool NOMBRE##CEsVacia(Cola##NOMBRE* c){               \
        return c->cabeza == NULL ;                                      \
    }                                                                   \

#endif