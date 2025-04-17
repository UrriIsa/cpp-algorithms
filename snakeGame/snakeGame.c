#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRIBA    'w'
#define IZQUIERDA 'a'
#define DERECHA   'd'
#define ABAJO     's'
#define ESC       27

int cuerpo[200][2], color = 2;
int n = 0, tam = 4; // `n` inicia en 0, y `tam` es el tamaño inicial del cuerpo
int x = 10, y = 12, dir = 3, xc = 30, yc = 15; // Posición inicial y dirección
int velocidad = 150, score = 0, fin = 0;

// Inicializar ncurses
void IniciarPantalla() {
    initscr(); // Inicializa la pantalla para usar ncurses.
    noecho(); // Evita que las teclas presionadas se muestren en la terminal.
    curs_set(FALSE); // Oculta el cursor.
    keypad(stdscr, TRUE); // Permite el uso de teclas especiales como flechas.
    start_color(); // Activa colores en la terminal.
    
    //Define combinaciones de colores (texto y fondo).
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}   

void gotoxy(int x, int y) { //implementación de gotoxy() ; para este juego
    move(y, x);
    refresh();
}

void textcolor(int color) {
    attron(COLOR_PAIR(color));
}

void Pintar() { //sirve para imprimir el fondo.
    int i;
    for (i = 2; i < 90; i++) {
        gotoxy(i, 3);
        printw("-");
        gotoxy(i, 25);
        printw("-");
    }
    for (i = 4; i < 25; i++) {
        gotoxy(2, i);
        printw("|");
        gotoxy(90, i);
        printw("|");
    }
    //Esquinas izquierdas
    gotoxy(2, 3); printw("+");
    gotoxy(2, 25); printw("+");
    //Esquinas derechas
    gotoxy(90, 3); printw("+");
    gotoxy(90, 25); printw("+");

}

void instrucciones (){
    while(true){
        char opcion ;
        clear() ;
        textcolor(5);
        attron(A_BOLD) ;
        
        mvprintw(3, 18, "%s", "_  _  _  ____  ___  ____  _  _  ____  ___  _  ____  _  _  ____ ") ;
        mvprintw(4, 18, "%s", "|  |\\ |  [__    |   |__/  |  |  |      |   |  |  |  |\\ |  [__  ") ;
        mvprintw(5, 18, "%s", "|  | \\|  ___]   |   |  \\  |__|  |___   |   |  |__|  | \\|  ___] ") ;
                                                                          

        attroff(COLOR_PAIR(5));
        
        textcolor(4);
        mvprintw(8, 27, "%s","Move the snake so that it eats the most food.") ;
        mvprintw(10, 23, "%s","You will lose when you hit the wall or your own body.") ;
        mvprintw(12, 41, "%s","W - Move up") ;
        mvprintw(14, 41, "%s","S - Move down") ;
        mvprintw(16, 41, "%s","A - Move left") ;
        mvprintw(18, 41, "%s","D - Move right") ;
        mvprintw(20, 36, "%s","ENTER - Select options") ;
        attroff(COLOR_PAIR(4)) ; 

        attron(A_REVERSE) ;  
        mvprintw(24, 45, "%s", "EXIT") ;
        attroff(A_REVERSE | COLOR_PAIR(7)) ; 
    
        opcion = getch(); 

        if(opcion == 10){
            return ;
        }
    }   
}

void creditos (){
    while(true){
        char opcion ;
        clear() ;
        textcolor(5);
        attron(A_BOLD) ;
        mvprintw(3, 32, "%s", "____  ____  ____  ___   _  ___  ____ ") ;
        mvprintw(4, 32, "%s", "|     |__/  |___  |  \\  |   |   [__  ") ;
        mvprintw(5, 32, "%s", "|___  |  \\  |___  |__/  |   |   ___] ") ;
        attroff(COLOR_PAIR(5));

                                                
        textcolor(4);
        mvprintw(8, 36, "%s","This game was developed by :") ;
        attroff(COLOR_PAIR(4));
        
        textcolor(4);
        attron(A_REVERSE) ; 
        mvprintw(10, 43, "%s"," Isaac Urrutia ") ;
        attroff(A_REVERSE | COLOR_PAIR(4)) ;

        textcolor(4);
        mvprintw(12, 40, "%s","License: MIT License") ;
        mvprintw(14, 42, "%s","GitHub : UrriIsa") ;
        attroff(COLOR_PAIR(4)) ; 

        attron(A_REVERSE) ;  
        mvprintw(23, 47, "%s", "EXIT") ;
        attroff(A_REVERSE | COLOR_PAIR(4)) ; 
    
        opcion = getch(); 

        if(opcion == 10){
            return ;
        }
    }    
}


void Menu() {
    char opcion  ;
    int seleccion = 0 ;
    char *opciones[] = { "Play", "Instructions", "Credits", "Exit" } ;
    int numOpciones = 4 ;

    while(true){
        clear() ;

        textcolor(1);
        attron(A_BOLD) ;
        mvprintw(4, 15, "%s", "    _____  _   __ ___     __ __  ______   ______ ___     __  ___ ______") ;
        mvprintw(5, 15, "%s", "   / ___/ / | / //   |   / //_/ / ____/  / ____//   |   /  |/  // ____/") ;
        mvprintw(6, 15, "%s", "   \\__ \\ /  |/ // /| |  / ,<   / __/    / / __ / /| |  / /|_/ // __/   ") ;
        mvprintw(7, 15, "%s", "  ___/ // /|  // ___ | / /| | / /___   / /_/ // ___ | / /  / // /___   ") ;
        mvprintw(8, 15, "%s", " /____//_/ |_//_/  |_|/_/ |_|/_____/   \\____//_/  |_|/_/  /_//_____/   ") ;
        attroff(COLOR_PAIR(1));                                                        

        mvprintw(25, 43, "%s", "(use W or S)") ;

        for(int i = 0 ; i < numOpciones ; i++ ){
            textcolor(4);
            if(i == seleccion){

                attron(A_REVERSE) ; // Resalta la opción seleccionada, no cierro mi A_BOLD para que al presionar teclas el titulo cambie
            }
            if(i == 0 || i == 3){
                //y, x
                mvprintw(12 + (i*2), 47, "%s", opciones[i]);
            
            }else if(i == 2){
                mvprintw(12 + (i*2), 45, "%s", opciones[i]);
            }
            else{
                mvprintw(12 + (i*2), 43, "%s", opciones[i]);
            }
            attroff(A_REVERSE | COLOR_PAIR(4));
        }

        opcion = getch();

        switch (opcion){
            case 'w' :
                seleccion = ((seleccion - 1) + numOpciones) % numOpciones;
                break;
            case 's' :
                seleccion = (seleccion + 1) % numOpciones;
                break ;
            case 10: // Enter para seleccionar
                if (seleccion == 0) {
                    return; // Iniciar el juego
                } else if(seleccion == 1){
                    instrucciones();
                }else if(seleccion == 2){
                    creditos() ;
                }else if (seleccion == 3) {
                    endwin();
                    exit(0); // Salir del programa
                }
                break;
            default:
                break;
        }
    }

}


void moverse() {
    timeout(velocidad);
    int ch = getch();
    if (ch != ERR) {
        if (ch == ARRIBA && dir != 2) dir = 1;
        if (ch == ABAJO && dir != 1) dir = 2;
        if (ch == DERECHA && dir != 4) dir = 3;
        if (ch == IZQUIERDA && dir != 3) dir = 4;
    }
}

void Puntaje() {
    textcolor(3);
    gotoxy(3, 1);
    printw("SCORE: %d", score);
    attroff(COLOR_PAIR(3));
    refresh();
}

void Comida() {
    if (x == xc && y == yc) {
        score += 10;
        xc = (rand() % 73) + 4;
        yc = (rand() % 19) + 4;
        gotoxy(xc, yc);
        textcolor(2);
        printw("*");
        attroff(COLOR_PAIR(2));
        tam++; // Incrementa el tamaño de la serpiente

        if (score % 50 == 0) {
            color = (color % 7) + 1;
            if (velocidad > 50) velocidad -= 20;
        }
    }
}

// Función para actualizar las posiciones del cuerpo
void ActualizarCuerpo() {
    for (int i = tam - 1; i > 0; i--) {
        cuerpo[i][0] = cuerpo[i - 1][0];
        cuerpo[i][1] = cuerpo[i - 1][1];
    }
    cuerpo[0][0] = x;
    cuerpo[0][1] = y;
}

// Función para verificar colisión con el cuerpo
int ColisionCuerpo() {
    for (int i = 1; i < tam; i++) { // Comenzar desde el segundo segmento del cuerpo
        if (cuerpo[i][0] == x && cuerpo[i][1] == y) {
            return 1; // Colisión detectada
        }
    }
    return 0; // No hay colisión
}

int main() {
    IniciarPantalla();

    Menu() ;
    clear() ;


    Pintar();
    gotoxy(xc, yc);
    textcolor(2);
    printw("*");
    attroff(COLOR_PAIR(2));
    fin = 0;

    while (!fin) {
        if (dir == 1) y--;         // Arriba
        else if (dir == 2) y++;    // Abajo
        else if (dir == 3) x++;    // Derecha
        else if (dir == 4) x--;    // Izquierda

        ActualizarCuerpo(); // Actualiza las posiciones del cuerpo

        // Dibuja el cuerpo
        for (int i = 0; i < tam; i++) {
            gotoxy(cuerpo[i][0], cuerpo[i][1]);
            textcolor(color);
            printw("O");
        }
        attroff(COLOR_PAIR(color));

        // Borra la cola
        gotoxy(cuerpo[tam - 1][0], cuerpo[tam - 1][1]);
        printw(" ");

        // Verificar colisiones
        if (x == 2 || x == 90 || y == 3 || y == 25 || ColisionCuerpo()) fin = 1;

        Comida();
        Puntaje();
        moverse();

        usleep(1000);
    }

    clear();
    textcolor(2);  
    mvprintw(6, 19, "%s", "    ,.   (   .      )       .          .      \"    .      \"") ;
    mvprintw(7, 19, "%s", "    (\"     )  )'     ,'      )  . (`     '`   )  . (`     '`") ;
    mvprintw(8, 19, "%s", "  .; )  ' (( (\" )    ;(,    ((  (  ;)  \"  )\"  ((  (  ;)  \" \"") ;
    mvprintw(9, 19, "%s", "  _\"., ,._'_.,)_(..,( . )__' )_') (. _..( '..  _' )_') (. _..'") ;
    mvprintw(10, 19, "%s", "    ______ ___     __  ___ ______   ____  _    __ ______ ____ ") ;
    mvprintw(11, 19, "%s", "   / ____//   |   /  |/  // ____/  / __ \\| |  / // ____// __ \\") ;
    mvprintw(12, 19, "%s", "  / / __ / /| |  / /|_/ // __/    / / / /| | / // __/  / /_/ /") ;
    mvprintw(13, 19, "%s", " / /_/ // ___ | / /  / // /___   / /_/ / | |/ // /___ / _, _/ ") ;
    mvprintw(14, 19, "%s", " \\____//_/  |_|/_/  /_//_____/   \\____/  |___//_____//_/ |_|  ") ;
    mvprintw(16, 45, "SCORE: %d", score) ;
    attroff(COLOR_PAIR(2));
    refresh();
    sleep(3);

    endwin();
    return 0;
}


/*
    Revisión [16-04-25]
     del ESC para parar el juego.
    ventana de cargando.   
    
}

*/
