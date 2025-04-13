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
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void gotoxy(int x, int y) {
    move(y, x);
    refresh();
}

void textcolor(int color) {
    attron(COLOR_PAIR(color));
}

void Pintar() {
    int i;
    for (i = 2; i < 78; i++) {
        gotoxy(i, 3);
        printw("-");
        gotoxy(i, 23);
        printw("-");
    }
    for (i = 4; i < 23; i++) {
        gotoxy(2, i);
        printw("|");
        gotoxy(77, i);
        printw("|");
    }
    gotoxy(2, 3); printw("+");
    gotoxy(2, 23); printw("+");
    gotoxy(77, 3); printw("+");
    gotoxy(77, 23); printw("+");
}

void Move() {
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
            if (velocidad > 50) velocidad -= 10;
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
        if (x == 2 || x == 77 || y == 3 || y == 23 || ColisionCuerpo()) fin = 1;

        Comida();
        Puntaje();
        Move();

        usleep(100000);
    }

    clear();
    gotoxy(30, 10);
    textcolor(2);
    printw("GAME OVER! SCORE: %d", score);
    attroff(COLOR_PAIR(2));
    refresh();
    sleep(3);

    endwin();
    return 0;
}



