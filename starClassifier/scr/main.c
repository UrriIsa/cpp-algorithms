/**
 * @file main.c
 * 
 * @brief [ES] : Clasifica estrellas por medio de datos proporcionados por un archivo csv.
 * @brief [EN] : Classify stars by means of data provided by a csv file.
 * 
 * @author: Isaac Urrutia-Alfaro
 * License: MIT License
 * Copyright (c) 2024-2025 Isaac Urrutia-Alfaro
 */

#include "functions.h"

/**
 * @brief [ES]: Función principal que lee datos de estrellas desde un archivo CSV, muestra sus características
 *               y libera la memoria asignada.
 * @brief [EN]: Main function that reads star data from a CSV file, displays their properties,
 *               and frees allocated memory.
 */
int main (){
    const char *fileCSV = "../data/starData.csv" ;
    int totSt = 0 ;

    Star *stars = readStars(fileCSV, &totSt) ;
    
    if (stars) {
        for (int i = 0; i < totSt; i++) {
            printf("La estrella \033[35m%s\033[0m es de tipo \033[32m%c\033[0m y sus datos son : \n\t-Densidad : \033[31m%0.2f\033[0m\n\t-Temperatura : \033[31m%d\033[0m\n", 
                    stars[i].name, clasificaEstrella(stars[i].temperature), stars[i].density, stars[i].temperature) ;

            /*  
                [ES] : Puede que no funcione por los colores, entonces se pondría :
                [EN] : It may not work because of the colors, then it would be set :  
                       printf("La estrella %s es de tipo %c y sus datos son : \n\t-Densidad : %0.2f\n\t-Temperatura : %d\n", 
                       stars[i].name, clasificaEstrella(stars[i].temperature), stars[i].density, stars[i].temperature) ;
            */
        }

        free(stars) ; // Liberar la memoria después de usarla
    }else{
        printf("No se pudieron leer las estrellas.\n") ;
        return 1 ;
    }
    return 0 ;
}