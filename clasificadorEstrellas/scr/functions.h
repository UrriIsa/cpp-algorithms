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