#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief  Declara los tipos y funciones de una pila para almacenar objetos de tipo T.
 *
 * Esta macro genera:
 *   - ElmtNOMBRE: nodo o elemento interno de la pila.
 *   - PilaNOMBRE: estructura de la pila (tope y tamaño).
 *   - ResPilNOMBRE: resultado de operaciones peek/pop con campo @c valido y @c valor.
 *   - NOMBRE##PAgrega: inserta un nuevo elemento (push).
 *   - NOMBRE##PExpulsa: extrae y libera el elemento del tope (pop).
 *   - NOMBRE##PEsVacia: comprueba si la pila está vacía.
 *   - NOMBRE##PMira: mira el elemento en el tope sin extraerlo (peek).
 *   - NOMBRE##PVacia: elimina todos los elementos, deja la pila vacía.
 *
 * @note La pila debe inicializarse manualmente antes de usar:
 *       @code{.c}
 *         PilaNOMBRE pila = { .tope = NULL, .tam = 0 };
 *       @endcode
 *
 * @param T       Tipo de los elementos que guardará la pila (int, float, struct …).
 * @param NOMBRE  Prefijo para los tipos y funciones (por ejemplo: “Int”, “Flt”, “MiTipo”).
 *
 * @example
 *   // Declara una pila de enteros con sufijo “Int”
 *   PILA_DCLR(int, Int)
 *
 *   int main(void) {
 *     PilaInt pila = { .tope = NULL, .tam = 0 };
 *     IntPAgrega(&pila, 42);
 *     ResPilInt r = IntPMira(&pila);
 *     if (r.valido) printf("Tope = %d\n", r.valor);
 *     IntPVacia(&pila);
 *     return 0;
 *   }
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
    static inline void NOMBRE##PVaciar(Pila##NOMBRE* p){                 \
        p->tope = NULL ;                                                \
        p->tam = 0 ;                                                    \
    }                                                                   \

#endif