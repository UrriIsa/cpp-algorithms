/**
 * @file functions.h
 * 
 * @brief [ES] : Prototipos y estructuras para clasificar estrellas a partir de datos en CSV.
 * @brief [EN] : Prototypes and structures for classifying stars based on CSV data.
 * 
 * @author Isaac Urrutia-Alfaro
 * License : MIT License
 * Copyright (c) 2024-2025 Isaac Urrutia-Alfaro
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50] ;
    float density ;
    int temperature ;
} Star ; 

char clasificaEstrella(int temperatura);
int processField(const char *line, char *temp, int *arLiIn, int start);
int processLine(const char *line, Star *star);
Star* readStars(const char *file, int *total);

#endif