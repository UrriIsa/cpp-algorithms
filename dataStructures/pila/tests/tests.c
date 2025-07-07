#include "minunit.h"
#include "pila.h"
#include <string.h>

PILA_DCLR(int, Int)
static PilaInt pila ;


MU_TEST(testPilaEmpiezaVacia) {
    printf("   ") ;
    mu_check(IntPEsVacia(&pila)) ;
    printf("\tTEST 1: pila empieza vacía\n") ;
}

MU_TEST(testAgregaMira) {
    printf("   ") ;
    IntPAgrega(&pila, 42) ;
    ResPilInt res = IntPMira(&pila) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(42, res.valor) ;
    printf("\tTEST 2: agregar elemento y mirar tope (push + peek)\n") ;
}

MU_TEST(testElimina) {
    printf("   ") ;
    IntPAgrega(&pila, 2) ;
    ResPilInt res = IntPExpulsa(&pila) ;
    mu_check(res.valido) ;
    mu_assert_int_eq(2, res.valor) ;
    printf("\tTEST 3: eliminar elemento (pop)\n") ;
}

MU_TEST(testEliminaVacia) {
    printf("   ") ;
    IntPExpulsa(&pila) ;
    ResPilInt res = IntPExpulsa(&pila) ;
    mu_check(!res.valido) ;
    printf("\tTEST 4: eliminar desde pila vacía\n") ;
}
MU_TEST(testVaciar){
    printf("   ") ;
    IntPAgrega(&pila, 1) ;
    IntPAgrega(&pila, 2) ;
    IntPAgrega(&pila, 3) ;
    IntPVacia(&pila) ;
    mu_assert_int_eq(0, pila.tam) ;
    printf("\tTEST 5: Vaciar pila\n") ;

}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testPilaEmpiezaVacia) ;
    MU_RUN_TEST(testAgregaMira) ;
    MU_RUN_TEST(testElimina) ;
    MU_RUN_TEST(testEliminaVacia) ;
    MU_RUN_TEST(testVaciar) ;
}

int main(void) {
    pila.tope = NULL ;
    MU_RUN_SUITE(test_suite) ;
    MU_REPORT() ;
    return MU_EXIT_CODE ;
}


