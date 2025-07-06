#include <stdio.h>
#include "minunit.h"
#include "pila.h"

DCLR_PILA(int, Int)

static IntPila pila;

MU_TEST(test_pila_empieza_vacia) {
    printf("\nTEST 1: pila empieza vacía\n");
    mu_check(Int_esVacio(&pila));
}

MU_TEST(test_agrega_y_mira) {
    printf("\nTEST 2: agregar elemento y mirar tope (push + peek)\n");
    Int_agrega(&pila, 42);
    IntResult res = Int_mira(&pila);
    mu_check(res.valido);
    mu_assert_int_eq(42, res.valor);
}

MU_TEST(test_elimina) {
    printf("\nTEST 3: eliminar elemento (pop) y verificar vacía\n");
    IntResult res = Int_elimina(&pila);
    mu_check(res.valido);
    mu_assert_int_eq(42, res.valor);
    mu_check(Int_esVacio(&pila));
}

MU_TEST(test_elimina_vacia) {
    printf("\nTEST 4: eliminar desde pila vacía\n");
    IntResult res = Int_elimina(&pila);
    mu_check(!res.valido);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_pila_empieza_vacia);
    MU_RUN_TEST(test_agrega_y_mira);
    MU_RUN_TEST(test_elimina);
    MU_RUN_TEST(test_elimina_vacia);
}

int main(void) {
    printf("Iniciando pruebas para pila genérica tipo int\n");
    pila.tope = NULL;
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}


