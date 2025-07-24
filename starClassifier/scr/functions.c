/**
 * @file functions.c
 *
 * @brief [ES]: Implementación de las funciones para el procesamiento de datos de estrellas.
 * @brief [EN]: Implementation of functions for processing star data.
 *
 * @author Isaac Urrutia-Alfaro
 * License : MIT License
 * @copyright Copyright (c) 2024–2025 Isaac Urrutia-Alfaro
 */
#include "functions.h"

/**
 * @brief [ES]: Clasifica una estrella según su temperatura.
 * @brief [EN]: Classifies a star based on its temperature.
 *
 * @param temperatura
 *   [ES]: Temperatura de la estrella en Kelvin.
 *   [EN]: Star’s temperature in Kelvin.
 *
 * @return
 *   [ES]: Letra de la clase espectral (O, B, A, F, G, K, M).
 *   [EN]: Spectral class letter (O, B, A, F, G, K, M).
 */
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

/**
 * @brief [ES]: Extrae un campo de texto de una línea CSV.
 * @brief [EN]: Extracts a text field from a CSV line.
 *
 * @param line
 *   [ES]: Cadena completa de la línea a procesar.
 *   [EN]: Full string of the line to process.
 * @param temp
 *   [ES]: Buffer de destino donde se copia el texto del campo.
 *   [EN]: Destination buffer to copy the field’s text.
 * @param arLiIn
 *   [ES]: Puntero a la posición de lectura; se actualiza tras extraer el campo.
 *   [EN]: Pointer to the read position; updated after extracting the field.
 * @param start
 *   [ES]: Índice inicial en la línea desde donde comenzar la lectura.
 *   [EN]: Starting index in the line from which to begin reading.
 *
 * @return
 *   [ES]: 0 si la extracción fue exitosa.
 *   [EN]: 0 if extraction succeeded.
 */
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

/**
 * @brief [ES]: Procesa una línea CSV completa y llena una estructura Star.
 * @brief [EN]: Processes an entire CSV line and fills a Star struct.
 *
 * @param line
 *   [ES]: Cadena con los campos separados por comas (name, density, temperature).
 *   [EN]: Comma-separated string (name, density, temperature).
 * @param star
 *   [ES]: Puntero a la estructura Star donde se almacenarán los datos.
 *   [EN]: Pointer to the Star struct where data will be stored.
 *
 * @return
 *   [ES]: 0 si la línea se procesó correctamente; 1 en caso de error.
 *   [EN]: 0 on successful processing; 1 on error.
 */
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
/**
 * @brief [ES]: Lee un archivo CSV de estrellas y devuelve un arreglo dinámico.
 * @brief [EN]: Reads a CSV of stars and returns a dynamically-allocated array.
 *
 * @param file
 *   [ES]: Ruta al archivo CSV de entrada.
 *   [EN]: Path to the input CSV file.
 * @param total
 *   [ES]: Puntero donde se devolverá la cantidad de estrellas leídas.
 *   [EN]: Pointer where the number of stars read will be returned.
 *
 * @return
 *   [ES]: Puntero al arreglo de Star; NULL si ocurre un error.
 *   [EN]: Pointer to the Star array; NULL on error.
 */
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