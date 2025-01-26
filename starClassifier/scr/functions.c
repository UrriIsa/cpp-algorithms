#include "functions.h"

char clasificaEstrella(int temperatura){
    if (temperatura < 3500) {
        return 'M';
    } else if (temperatura < 5000) {
        return 'K';
    } else if (temperatura < 6000) {
        return 'G';
    } else if (temperatura < 7500) {
        return 'F';
    } else if (temperatura < 10000) {
        return 'A';
    } else if (temperatura < 30000) {
        return 'B';
    } else {
        return 'O';
    }
}

int processField(const char *line, char *temp, int *arLiIn, int start){
    int l = start , t = 0 ;
    while(line[l] != ',' && line[l] != '\0' && line[l] != '\n'){ //esto es para que siga checando caracteres hasta que vea una coma (cambio de columna), final o salto de línea
        if(t < sizeof(temp) - 1){ //que no sobrepase el tamaño de mi array temp
            temp[t] = line[l] ;
            t++ ;
        }
        l++ ;
    }
    temp[t] = '\0' ; //cierro el arreglo
    *arLiIn = l+1; //actualizo el valor de dónde va a leer el array.
    return 0;
}

int processLine(const char *line, Star *star){
    int arLiIn = 0 ;
    char temp[150]; 

    int verName = processField(line, temp, &arLiIn, 0); //proceso la línea para que actualice temp con la primera columna
    if(verName == 0){
        strncpy(star->name, temp, sizeof(star->name) - 1) ;
        star -> name [sizeof(star -> name) - 1] = '\0' ;
    }else{
        printf("Error al procesar el nombre \n") ;
        return 1;
    }

    int verDen = processField(line, temp, &arLiIn, arLiIn) ; //proceso la línea para que actualice temp con la segunda columna
    if(verDen == 0){
        star -> density = atof(temp) ; //atof que se guarda en star que apunta a density, como pasé la localidad de star no puedo acceder directo a density
    }else{
        printf("Error al procesar la densidad \n") ;
        return 1;
    }
 
    int verTemp = processField(line, temp, &arLiIn, arLiIn);//proceso la línea para que actualice temp con la tercera columna
    if(verTemp == 0){
        star -> temperature = atoi(temp);
    }else{
        printf("Error al procesar la temperatura \n") ;
        return 1;
    }


    return 0;
}

Star* readStars(const char *file, int *total){
    FILE *fp = fopen(file, "r");
    if(!fp){
        printf("Error al arbir archivo \n") ; //su no se abre el archivo
        return NULL ;
    }
    char header[150];
    fgets(header, sizeof(header), fp); //solo para limpiar los encabezados

    Star *stars = NULL ;
    *total = 0 ;
    char line[150] ;
    //inicializo stars (se convertirá en matriz), total de estrellas y linea que utilizare para leer las filas

    while(fgets(line, sizeof(line), fp)){ //mientras lea la linea en line del archivo fp, con un tamaño de line

        if(strlen(line) <= 1){ //que no tengan nada
            continue ;
        }

        Star *temp = realloc(stars, sizeof(Star) * (*total + 1)) ; //actualizo la memoria conforme voy leyendo estrellas, en variable temporal acerca de stars de tamaño (tamaño de star por el total de estrellas)

        if(!temp){ //si no puede el realloc
            printf("No se pudo redimensionar el arreglo") ;
            free (stars) ;
            fclose(fp) ;
            return NULL ;
        }

        stars = temp; //sí se pudo el realloc y aparto la memoria de temp en stars (ya es un vector)

        int verProcLin = processLine(line, &stars[*total]) ; //proceso las líneas para guardar en la posición de total (de 0 a la última)

        if(verProcLin != 0){ //si no pude procesar la linea
            printf("Error al procesar la línea: %s \n", line) ; 
            free(stars) ;
            fclose(fp) ;
            return NULL ;
        }
        (*total) ++ ;
    }
    fclose(fp);
    return stars;
    
}