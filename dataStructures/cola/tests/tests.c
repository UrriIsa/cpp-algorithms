/**
 * @file test_pila.c
 * Pruebas unitarias para la pila genérica definida en pila.h usando MinUnit.
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

MU_TEST(testColaEmpiezaVacia) {
    printf("   ") ;
    mu_check(IntCEsVacia(&cola)) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin    == NULL) ;
    printf("\tTEST 1: cola empieza vacía\n") ;
}

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

MU_TEST(testElimina) {
    printf("   ") ;
    ResColaInt res = IntCExpulsa(&cola) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(22, res.valor) ;
    mu_check(cola.cabeza->dato == 23) ;
    mu_check(cola.fin->dato == 23) ;
    printf("\tTEST 3: eliminar elemento\n") ;
}

MU_TEST(testVaciar){
    printf("   ") ;
    IntCAgrega(&cola, 24) ;
    IntCAgrega(&cola, 5) ;
    IntCVaciar(&cola) ;
    mu_assert_int_eq(0, cola.tam) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin    == NULL) ;
    printf("\tTEST 5: Vaciar pila\n") ;
}

MU_TEST(testEliminaVacia) {
    printf("   ") ;
    IntCExpulsa(&cola) ;
    ResColaInt res = IntCExpulsa(&cola) ;
    mu_check(!res.valido) ;
    mu_check(cola.cabeza == NULL) ;
    mu_check(cola.fin    == NULL) ;
    printf("\tTEST 4: eliminar desde pila vacía\n") ;
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testColaEmpiezaVacia) ;
    MU_RUN_TEST(testAgregaMira) ;
    MU_RUN_TEST(testElimina) ;
    MU_RUN_TEST(testVaciar) ;
    MU_RUN_TEST(testEliminaVacia) ;
}


int main(){
    cola.cabeza = NULL ;
    MU_RUN_SUITE(test_suite) ;
    MU_REPORT() ;
    return MU_EXIT_CODE ;
    return 0 ;
}