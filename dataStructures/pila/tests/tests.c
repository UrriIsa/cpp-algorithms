/**
 * @file tests.c
 * 
 * @brief [ES] : Pruebas unitarias para la pila genérica definida en pila.h usando MinUnit.
 * @brief [EN] : Unit tests for the generic stack defined in stack.h using MinUnit.
 * 
 * @author: Isaac Urrutia-Alfaro
 * License: MIT License
 * Copyright (c) 2025 Isaac Urrutia-Alfaro
 */
#include "minunit.h"
#include "pila.h"
#include <string.h>

/**
 * [ES] : Declara una pila de enteros con sufijo "Int".
 *        Crea una instancia estática de la pila de enteros para todas las pruebas.
 * [EN] : Declares an integer stack with suffix “Int”.
 *        Creates a static instance of the integer stack for all tests.
 */
PILA_DCLR(int, Int)
static PilaInt pila ;

/**
 * TEST   1
 * [ES] : Verifica que una pila recién inicializada empiece vacía.
 * [EN] : Verifies that a newly initialized stack starts empty.
 */
MU_TEST(testPilaEmpiezaVacia) {
    printf("   ") ;
    mu_check(IntPEsVacia(&pila)) ;
    printf("\tTEST 1: pila empieza vacía\n") ;
}
/**
 * TEST 2 
 * [ES] : Push + Peek. Inserta un valor en la pila (42).
 *        Comprueba con Peek verifica que tenga un valor (res.valido) y que sea el que se insertó.
 * [EN] : Push + Peek. Inserts a value in the stack (42).
 *        Checks with Peek verifies that it has a value (res.valid) and that it is the one inserted.
 */
MU_TEST(testAgregaMira) {
    printf("   ") ;
    IntPAgrega(&pila, 42) ;
    ResPilInt res = IntPMira(&pila) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(42, res.valor) ;
    printf("\tTEST 2: agregar elemento y mirar tope (push + peek)\n") ;
}
/**
 * TEST 3
 * [ES] : Inserta 2, luego extrae y verifica que sea válido y que el valor extraído sea 2.
 * [EN] : Insert 2, then extract and verify that it is valid and that the extracted value is 2.
 */
MU_TEST(testElimina) {
    printf("   ") ;
    IntPAgrega(&pila, 2) ;
    ResPilInt res = IntPExpulsa(&pila) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(2, res.valor) ;
    printf("\tTEST 3: eliminar elemento (pop)\n") ;
}
/**
 * TEST 4
 * [ES] : Pop desde pila vacía. Vacía la pila e intenta hacer pop desde pila vacía,
 *        debe de dar res.valido == false.
 * [EN] : Pop from empty stack. Clear the stack and try to pop from empty stack,
 *        should give res.valid == false.
 */
MU_TEST(testEliminaVacia) {
    printf("   ") ;
    IntPExpulsa(&pila) ;
    ResPilInt res = IntPExpulsa(&pila) ;
    mu_check(!res.valido) ;
    printf("\tTEST 4: eliminar desde pila vacía\n") ;
}
/**
 * TEST 5
 * [ES] : Vaciar pila. Inserta tres valores y luego vacía la pila.
 *        El tamaño de la pila debe quedar en 0.
 * [EN] : Clear stack. Insert three values and then empty the stack.
 *        The stack size must be set to 0.
 */
MU_TEST(testVaciar){
    printf("   ") ;
    IntPAgrega(&pila, 1) ;
    IntPAgrega(&pila, 2) ;
    IntPAgrega(&pila, 3) ;
    IntPVaciar(&pila) ;
    mu_assert_int_eq(0, pila.tam) ;
    printf("\tTEST 5: Vaciar pila\n") ;

}
/**
 * [ES] : Define el conjunto de pruebas que se ejecutarán.
 * [EN] : Defines the set of tests to be executed.
 */
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testPilaEmpiezaVacia) ;
    MU_RUN_TEST(testAgregaMira) ;
    MU_RUN_TEST(testElimina) ;
    MU_RUN_TEST(testEliminaVacia) ;
    MU_RUN_TEST(testVaciar) ;
}
/**
 * [ES] : Función principal. Inicializa la pila, ejecuta la suite y muestra informe.  
 * [EN] : Main function. Initializes the stack, runs the suite, and reports results.
 */
int main() {
    pila.tope = NULL ;
    MU_RUN_SUITE(test_suite) ;
    MU_REPORT() ;
    return MU_EXIT_CODE ;
}


