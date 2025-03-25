/*
 * Description: This program finds Kaprekar numbers in a given range.
 * Author: Urrutia Alfaro Isaac Arturo
 * License: MIT License
 * Copyright (c) 2024-2025 Urrutia Alfaro Isaac Arturo
 */

#include<stdio.h>
#include <ctype.h>

// Function to convert a float number to an integer
int convierteInt(float num)
{
    int resultado;
    resultado = (int)num;  // Truncates the decimal part
    return resultado;
}

// Function to verify and print Kaprekar numbers in a given range
void verificaNum(int inicio, int fin)
{
    int cuadrado, modulo, divInt, operador=10, numVer=inicio, conta=0;
    
    // Iterate through the range from `inicio` to `fin`
    while(numVer <= fin)
    {

         // We add a condition to avoid multiples of 10
         if (numVer % 10 == 0)
         {
             numVer++;
             continue; // We move on to the next number without verifying the current number
         }

         cuadrado = numVer * numVer; // Square of the current number
         operador=10; // Reset the divisor multiplier
         do
         {
               // Split the squared number into two parts
               divInt = convierteInt(cuadrado)/operador; // Integer division
               modulo = cuadrado % operador; // Remainder

               if(divInt + modulo== numVer) // Check if the sum of the two parts equals the original number
               {
                      printf("\nEl número %i es de Kaprekar",  numVer);
                      conta++;
               } 
               operador*=10; // Increase the divisor multiplier
         }
         while(modulo != cuadrado);  // Continue until all parts are processed
         numVer++; // Move to the next number
    }
      // If no Kaprekar numbers are found
    if(conta == 0)
           printf("\nEn el rango que diste no hay números de Kaprekar");
    
    return ;
}

int main (void)
{
    
    int numInicio, numFin; // Start and end of the range
    char respuesta;  // User's response to continue or not
    
    do
    {
          // Prompt user for the start of the range
          printf("Dame el número de inicio: ");
          scanf("%i", &numInicio);
          fflush(stdin); // Clear the input buffer (if necessary)
          // Alternatively, you can use:
          //while (getchar() != '\n');
          
          // Prompt user for the end of the range
          printf("Dame el número de fin: ");
          scanf("%i", &numFin);
          getchar();
          fflush(stdin);
          // Alternatively, you can use:
          //while (getchar() != '\n');
          
          if(numInicio > numFin)
          {
                while (getchar() != '\n');
                printf("El rango dado no es adecuado");
                printf("\n¿Quieres intentar de nuevo?\nResponde S para hacerlo: ");
                respuesta=getchar();
                respuesta = toupper(respuesta); // Get user's response and convert to uppercase
                // Alternatively, you can use:
                //while (getchar() != '\n');
          }
          else
          {
                verificaNum(numInicio, numFin); // Verify and print Kaprekar numbers in the valid range
                printf("\n\n¿Quieres comparar otros números?\nResponde S para hacerlo: ");
                respuesta=getchar();
                respuesta = toupper(respuesta);  // Get user's response and convert to uppercase
          }
                
    }
    while(respuesta == 'S' ); // Repeat if user responds with 'S'
    
    getchar();
    return 0;
}
