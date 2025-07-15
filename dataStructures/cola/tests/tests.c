/**
 * @file tests.c
 * 
 * @brief [ES] : Pruebas unitarias para la cola genérica definida en cola.h usando MinUnit.
 * @brief [EN] : Unit tests for the generic queue defined in queue.h using MinUnit.
 * 
 * @author: Isaac Urrutia-Alfaro
 * License: MIT License
 * Copyright (c) 2025 Isaac Urrutia-Alfaro
 */
#include "minunit.h"
#include "cola.h"
#include <string.h>

/**
 * [ES] : Declara una cola de enteros con sufijo "Int".
 *        Crea una instancia estática de la cola de enteros para todas las pruebas.
 * [EN] : Declares an integer queue with suffix “Int”.
 *        Creates a static instance of the integer queue for all tests.
 */
COLA_DCLR(int, Int)
static ColaInt cola ;

/**
 * TEST   1
 * [ES] : Verifica que una cola recién inicializada empiece vacía.
 * [EN] : Verifies that a newly initialized queue starts empty.
 */
MU_TEST(testColaEmpiezaVacia) {
    printf("   ") ;
    mu_check(IntCEsVacia(&cola)) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin == NULL) ;
    printf("\tTEST 1: cola empieza vacía\n") ;
}
/**
 * TEST 2 
 * [ES] : Inserta dos valores en la cola (22 y 23).
 *        Comprueba con CMira que tenga un valor (res.valido) y que sea el primero que se insertó.
 *        Finalmente, verifica que la posición de la cola sea correcta.
 * [EN] : Inserts two values in the queue (22 and 23).
 *        Check with CMira that it has a value (res.valid) and that it is the first one inserted.
 *        Finally, check that the queue position is correct.
 */
MU_TEST(testAgregaMira){
    printf("   ") ;
    IntCAgrega(&cola, 22) ;
    IntCAgrega(&cola, 23) ;
    ResColaInt res = IntCMira(&cola) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(22, res.valor) ;
    mu_check(cola.cabeza->dato == 22) ;
    mu_check(cola.fin->dato == 23) ;
    printf("\tTEST 2: agregar elementos y mirar cabeza\n") ;
}
/**
 * TEST 3
 * [ES] : Expulsa un valor, verifica que sea 22 y finalmente checa que la cabeza y el fin sean 23.
 * [EN] : Eject a value, check that it is 22 and finally check that the head and end are 23.
 */
MU_TEST(testElimina) {
    printf("   ") ;
    ResColaInt res = IntCExpulsa(&cola) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(22, res.valor) ;
    mu_check(cola.cabeza->dato == 23) ;
    mu_check(cola.fin->dato == 23) ;
    printf("\tTEST 3: eliminar elemento\n") ;
}
/**
 * TEST 4
 * [ES] : Añade dos valores (24 y 5), vacía la cola y verifica que el tamaño sea cero y la cabeza y final nulos.
 * [EN] : Add two values (24 and 5), empty the tail and verify that the size is zero and the head and end are null.
 */
MU_TEST(testVaciar){
    printf("   ") ;
    IntCAgrega(&cola, 24) ;
    IntCAgrega(&cola, 5) ;
    IntCVaciar(&cola) ;
    mu_assert_int_eq(0, cola.tam) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin == NULL) ;
    printf("\tTEST 5: Vaciar pila\n") ;
}
/**
 * TEST 5
 * [ES] : Con la cola vacía intenta expulsar un elemento, por lo que verifica que res NO sea válido y que la cabeza y final sigan siendo nulos. 
 * [EN] : With the tail empty it tries to eject an element, so check that res is NOT valid and that the head and end are still null.
 */
MU_TEST(testEliminaVacia) {
    printf("   ") ;
    IntCExpulsa(&cola) ;
    ResColaInt res = IntCExpulsa(&cola) ;
    mu_check(!res.valido) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin == NULL) ;
    printf("\tTEST 4: eliminar desde pila vacía\n") ;
}
/**
 * [ES] : Define el conjunto de pruebas que se ejecutarán.
 * [EN] : Defines the set of tests to be executed.
 */
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testColaEmpiezaVacia) ;
    MU_RUN_TEST(testAgregaMira) ;
    MU_RUN_TEST(testElimina) ;
    MU_RUN_TEST(testVaciar) ;
    MU_RUN_TEST(testEliminaVacia) ;
}
/**
 * [ES] : Función principal. Inicializa la cola, ejecuta la suite y muestra informe.  
 * [EN] : Main function. Initializes the queue, runs the suite, and reports results.
 */
int main(){
    cola.cabeza = NULL ;
    MU_RUN_SUITE(test_suite) ;
    MU_REPORT() ;
    return MU_EXIT_CODE ;
    return 0 ;
}