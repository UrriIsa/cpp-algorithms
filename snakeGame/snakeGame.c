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
        gotoxy(i, 23);
        printw("-");
    }
    for (i = 4; i < 25; i++) {
        gotoxy(2, i);
        printw("|");
        gotoxy(90, i);
        printw("|");
    }
    gotoxy(2, 3); printw("+");
    gotoxy(2, 23); printw("+");
    gotoxy(77, 3); printw("+");
    gotoxy(77, 23); printw("+");
}

void Instrucciones (){
    while(true){
        char opcion ;
        clear() ;

        mvprintw(10, 41, "%s", "Instrucciones de Prueba") ;

        
        attron(A_REVERSE);  
        mvprintw(15, 47, "%s", "EXIT");
        attroff(A_REVERSE); 
    
        opcion = getch(); 

        if(opcion == 10){
            return ;
        }
    }   
}

void creditos (){
    while (true) {
        clear();
        int ch ;

        // Mostrar texto
        mvprintw(10, 10, "Texto parpadeante");
        refresh();
        napms(200);  // Espera 200 ms
    
        // Borrar texto
        mvprintw(10, 10, "                   ");  // Borrar texto con espacios
        refresh();
        napms(200);  // Espera 200 ms

        mvprintw(10, 10, "Texto parpadeante");
        refresh();
        napms(200); 
        if (ch != ERR) ch = getch();  // Salir si el usuario presiona Enter
        if (ch == 10) break;
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
        mvprintw(4, 14, "%s", "    _____  _   __ ___     __ __  ______   ______ ___     __  ___ ______") ;
        mvprintw(5, 14, "%s", "   / ___/ / | / //   |   / //_/ / ____/  / ____//   |   /  |/  // ____/") ;
        mvprintw(6, 14, "%s", "   \\__ \\ /  |/ // /| |  / ,<   / __/    / / __ / /| |  / /|_/ // __/   ") ;
        mvprintw(7, 14, "%s", "  ___/ // /|  // ___ | / /| | / /___   / /_/ // ___ | / /  / // /___   ") ;
        mvprintw(8, 14, "%s", " /____//_/ |_//_/  |_|/_/ |_|/_____/   \\____//_/  |_|/_/  /_//_____/   ") ;
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
                    Instrucciones();
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
    textcolor(7);
    gotoxy(3, 1);
    printw("SCORE: %d", score);
    attroff(COLOR_PAIR(7));
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
        if (x == 2 || x == 90 || y == 3 || y == 23 || ColisionCuerpo()) fin = 1;

        Comida();
        Puntaje();
        moverse();

        usleep(1000);
    }

    clear();
    textcolor(2);
    mvprintw(10, 33, "%s", "     ______   _   __   ____ ") ;
    mvprintw(11, 33, "%s", "    / ____/  / | / /  / __ \\") ;
    mvprintw(12, 33, "%s", "   / __/    /  |/ /  / / / /") ;
    mvprintw(13, 33, "%s", "  / /___   / /|  /  / /_/ / ") ;
    mvprintw(14, 33, "%s", " /_____/  /_/ |_/  /_____/  ") ;                 
    
    mvprintw(16, 44, "SCORE: %d", score) ;
    attroff(COLOR_PAIR(2));
    refresh();
    sleep(3);

    endwin();
    return 0;
}


/*
    Revisión [13-04-25]
    Falta el menú del juego, o en dado caso añadir las instrucciónes abajo de la ventana.
    Al final despúes imprimir de manera correcta la puntuación.
    La opción de salir también falta, así como la del ESC para parar el juego.
    ventana de cargando.   
    Quizas ver unos mejores caracteres.
}

*/
