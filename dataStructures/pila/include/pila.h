/**
 * @file pila.n
 * 
 * @brief [ES] : Macro genérica para crear pilas de tipo T.
 * @brief [EN] : Generic macro to create stacks of type T.
 * 
 * @author : Isaac Urrutia-Alfaro
 * License : MIT License
 * Copyright (c) 2025 Isaac Urrutia-Alfaro
 * 
 * @details [ES]
 *   Esta macro genera :
 *     - ElmtNOMBRE : elemento (nodo) interno.
 *     - PilaNOMBRE : estructura (tope, tamaño).
 *     - ResPilNOMBRE : tipo de resultado para operaciones de peek y pop.
 *     - NOMBRE##PAgrega : inserta (push).
 *     - NOMBRE##PExpulsa : extrae (pop).
 *     - NOMBRE##PEsVacia : comprueba vacío.
 *     - NOMBRE##PMira : mira sin extraer.
 *     - NOMBRE##PVacia : vacía la pila.
 *
 * @details [EN]
 *   This macro generates :
 *     - ElmtNOMBRE : internal element (node).
 *     - PilaNOMBRE : stack structure (top, size).
 *     - ResPilNOMBRE : result of peek/pop.
 *     - NOMBRE##PAgrega : push.
 *     - NOMBRE##PExpulsa : pop.
 *     - NOMBRE##PEsVacia : is_empty.
 *     - NOMBRE##PMira : peek.
 *     - NOMBRE##PVacia : clear.
 *
 * @param T
 *  [ES] Tipo de los elementos.
 *  [EN] Type of the elements.
 * @param NOMBRE
 *  [ES] Prefijo para tipos y funciones.
 *  [EN] Prefix for types and functions.
 */

#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
    static inline void NOMBRE##PVaciar(Pila##NOMBRE* p){                 \
        p->tope = NULL ;                                                \
        p->tam = 0 ;                                                    \
    }                                                                   \

#endif // PILA_H