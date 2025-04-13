#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
//------------------------------------------------------------------------------
#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80
#define ESC       27
//------------------------------------------------------------------------------
int cuerpo[200][2],color=2;
int n=1, x=10, y=12,fin=0;
int tam=4, dir=3;
int xc=30,yc=15;
char tecla;
int velocidad=150, h=1;
int score=0;
char menuop;
//------------------------------------------------------------------------------
void Inicio()
{
    int conty,contx;
    textcolor(1); // o 7
    /*for(conty=4; conty=22; conty++) //de 3,4 a 3,22 y 76,4 y 76,22 es para un fondo 
        for(contx=3; contx=76; contx++)
        {
            gotoxy(contx,conty);
            printf("%c",177);
        }
        // 176 poco, 177 medio, 178 mucho
    //si funciona ponerle en la del menú 2 y en la game over*/
    textcolor(15);
    gotoxy(34,6);
    printf("SNAKE");
    gotoxy(32,10);
    printf("JUGAR  A");
    gotoxy(30,12);
    printf("OPCIONES  E");
    gotoxy(31,14);
    printf("SALIR  X :");
    menuop=getch();
    if(menuop!='x' || menuop!='X')
        fin=1;
    system("CLS");
    return ;
}
void Pintar()
{
   int i;
   for( i=2; i<78; i++)//linea hori
   {
      gotoxy(i,3);
      printf("%c",205);
      gotoxy(i,23);
      printf("%c",205);
   }
   for( i=4;i<23;i++)//linea ver
   {
      gotoxy(2,i);
      printf("%c",186);
      gotoxy(77,i);
      printf("%c",186);
   }
   gotoxy(2,3);//esquinas
   printf("%c",201);
   gotoxy(2,23);
   printf("%c",200);
   gotoxy(77,3);
   printf("%c",187);
   gotoxy(77,23);
   printf("%c",188);
   return ;
}
void Opciones()
{
    textcolor(15);
    gotoxy(35,4);
    printf("OPCIONES");
    gotoxy(19,6);
    printf("Moverse hacia ariba      w");
    gotoxy(19,8);
    printf("Moverse hacia abajo      s");
    gotoxy(19,10);
    printf("Moverse hacia la derecha      a");
    gotoxy(19,12);
    printf("Moverse hacia la isquierza      d");
    gotoxy(19,14);
    printf("Pausar el juego      ESC");
    gotoxy(19,16);
    printf("Para despausar presiona cualquier tecla");
    gotoxy(19,18);
    printf("PULSA A PARA JUGAR");
    gotoxy(19,20);
    printf("PULSA X PARA SALIR:");
    menuop=getch();
    if(menuop!='x' || menuop!='X')
        fin=1;
    system("CLS");
}
void Cargando()
{
     system("CLS");
     return ;
}
void GuardaPos()
{
   cuerpo[n][0]=x;
   cuerpo[n][1]=y;
   n++;
   if(n==tam)
      n=1;
   return ;
}
int PintCuerp()
{
   int i;
   for(i=1; i<tam; i++)
   {
      gotoxy(cuerpo[i][0],cuerpo[i][1]);
      textcolor(color);
      cprintf("*");
   }
   return i;
}
void BorraCuer()
{
      gotoxy(cuerpo[n][0],cuerpo[n][1]);
      printf(" ");
      gotoxy(cuerpo[n+1][0],cuerpo[n+1][1]);
      printf(" ");
      gotoxy(cuerpo[n-1][0],cuerpo[n-1][1]);
      printf(" ");
      gotoxy(cuerpo[n+1][0],cuerpo[n][1]);
      printf(" ");
      gotoxy(cuerpo[n-1][0],cuerpo[n][1]);
      printf(" ");
      //hacer otra para que borre definitivamente
      return ;
}
void Move()
{
     if(kbhit())
      {
         tecla=getch();
         if(tecla=='w')
            if(dir !=2)
                dir=1;
         if(tecla=='s')
            if(dir !=1)
                dir=2;
         if(tecla=='d')
            if(dir !=4)
                dir=3;
         if(tecla=='a')
            if(dir !=3)
                dir=4; 
      }
      return ;
}
void Velocidad()
{
     if(score==h*20)
     {
          velocidad-=3;
          h++;
     }
     return ;
}
void Comida()
{
   if(x==xc && y==yc)
   {
      Beep(1568,200);
      xc=(rand()%73+4);
      yc=(rand()%19+4);
      gotoxy(xc,yc);
      textcolor(12);
      cprintf("%c",4);
      tam++;
      score=score + 10;
      if(score==50 && tam==9)
          color=3; 
      if(score==100 && tam==14)
          color=5;
      if(score==150 && tam==19)
          color=7;
      if(score==200 && tam==24)
          color=10;
      if(score==250 && tam==29)
          color=11;
      if(score==300 && tam==34)
          color=13;
      if(score==350 && tam==39)
          color=12;
      if(score==350 && tam==39)
          color=14;
      Velocidad();
   }
   return ;
}
int Finjuego(int x, int y)
{
     int op, j;
     if(y==3||y==23||x==2||x==77)
        op=1;
     else
        op=0;
     for( j=tam-1; j>0; j--)
     {
         if(cuerpo[j][0]==x && cuerpo[j][1]==y)
             op=1;
     }
     return op;
}
void Puntaje()
{
     gotoxy(3,2);
     textcolor(15);
     printf("SCORE: %i",score);
     return ;
}
void GameOver()
{
     int xgo, ygo;
     system("CLS");
     Pintar();
     gotoxy(32,8);printf(" TOTAL PUNTOS :%i",score);
     gotoxy(33,13);printf("!..GAME OVER..!");
     Beep(587,500);
     Beep(659,500);
     Beep(698,500);
     Beep(784,500);
     gotoxy(32,17);printf(" VOLVER A JUGAR A");
     gotoxy(36,19);printf(" SALIR X :");
     menuop=getch();
     if(menuop!='x' || menuop!='X')
        fin=1;
     system("CLS");
     return ;
}
int main()
{
   int c,r,i;
//----------------------------------------------------------------------------------  
   Pintar();
   Inicio();
   if(menuop=='E'|| menuop=='e')
   {
           Pintar();
           Opciones();   
   }
    while(menuop!='x' || menuop!='X' && fin!=1)
   {
           //Cargando();
//----------------------------------------------------------------------------------
           Pintar();
           gotoxy(xc,yc);
           textcolor(12);
           printf("%c",4);
           fin=0;
            while(tecla!= ESC && fin==0)
            {
                Comida();
               BorraCuer();
               GuardaPos();
               i=PintCuerp();
               Move();
               if(dir==1)
                   y--;
               if(dir==2)
                   y++;
               if(dir==3)
                   x++;
               if(dir==4)
                   x--;
               fin= Finjuego(x, y);
               
               Puntaje();
               Velocidad();
               Sleep(velocidad);
           }
//----------------------------------------------------------------------------------------
           if(fin==1)
               GameOver();
           if(menuop!='x' || menuop!='X')
           {
               x=10;
               y=12;
               tam=4;
               dir=3;
               n=1;
               xc=30;
               yc=15;
               velocidad=150;
               h=1;
               score=0;
               color=2;
               fin=0;
               Pintar();
               Inicio();
               if(menuop=='E'|| menuop=='e')
               {
                   Pintar();
                   Opciones();   
               }
           }
   }

   return 0;
}
