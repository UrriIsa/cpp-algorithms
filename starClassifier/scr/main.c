#include "functions.h"

int main (){
    const char *fileCSV = "../data/starData.csv" ;
    int totSt = 0 ;

    Star *stars = readStars(fileCSV, &totSt) ;
    
    if (stars) {
        for (int i = 0; i < totSt; i++) {
            printf("La estrella \033[35m%s\033[0m es de tipo \033[32m%c\033[0m y sus datos son : \n\t-Densidad : \033[31m%0.2f\033[0m\n\t-Temperatura : \033[31m%d\033[0m\n", 
                    stars[i].name, clasificaEstrella(stars[i].temperature), stars[i].density, stars[i].temperature) ;

            /*  
                Puede que no funciones por los colores, entonces se pondría : 
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