#include "Comparadores.h"
#include <string.h> // Para strcmp

/**
 * Vamos a utilizar los siguientes valores :
 *    -1 el segundo es mayor que el primero
 *    0 como que ambos son iguales.
 *    1 el primero es mayor que el segundo
 */

int intCompare(const void *a, const void *b){
    int aInt = *(const int *) a ;
    int bInt = *(const int *) b ;

    if(aInt == bInt) return 0 ;
    return (aInt > bInt) ? 1 : -1;

}
//ESTE SIRVE PARA LAS MATRICES
//ESTO SOLO COMPARA EL PRIMER ELEMENTO
int intCompareRow(const void *a, const void *b) {
    const int *rowA = *(const int **)a; // Puntero a la primera fila
    const int *rowB = *(const int **)b; // Puntero a la segunda fila

    // Compara el primer elemento de cada fila
    if (rowA[0] == rowB[0]) {
        return 0;
    } else if (rowA[0] < rowB[0]) {
        return -1;
    } else {
        return 1;
    }
    
}

// Función para comparar dobles
int doubleCompare(const void *a, const void *b){
    double aDouble = *(const double *) a ;
    double bDouble = *(const double *) b ;

    if(aDouble == bDouble) return 0;
    return (aDouble > bDouble) ? 1 : -1;
}

// Función para comparar cadenas de caracteres
int stringCompare(const void *a, const void *b){
    const char *aString = *(const char **)a;
    const char *bString = *(const char **)b;
    return strcmp(aString, bString);
}

// Función para comparar booleanos
int booleanCompare(const void *a, const void *b){

}

