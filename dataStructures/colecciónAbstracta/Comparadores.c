#include "Comparadores.h"
#include <string.h> // Para strcmp

/**
 * Vamos a utilizar los siguientes valores :
 *    -1 el primero es menor que el segundo
 *    0 como que ambos son iguales.
 *    1 el primero es mayor que el segundo
 */

int intCompare(const void *a, const void *b){
    int ai = *(const int *) a ;
    int bi = *(const int *) b ;

    return (ai > bi) - (ai < bi) ;
}

// Función para comparar dobles
int doubleCompare(const void *a, const void *b){

}

// Función para comparar cadenas de caracteres
int stringCompare(const void *a, const void *b){

}

// Función para comparar booleanos
int booleanCompare(const void *a, const void *b){

}

int intCompare(const void *a, const void *b) {
    int ai = *(const int *)a;
    int bi = *(const int *)b;
    return (ai > bi) - (ai < bi);
}

int doubleCompare(const void *a, const void *b) {
    double da = *(const double *)a;
    double db = *(const double *)b;
    // Si son iguales, retornamos 0; de lo contrario, retornamos 1 o -1.
    if(da == db) return 0;
    return (da > db) ? 1 : -1;
}

int stringCompare(const void *a, const void *b) {
    const char *sa = *(const char **)a;
    const char *sb = *(const char **)b;
    return strcmp(sa, sb);
}