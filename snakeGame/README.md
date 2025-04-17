## Juego de la Serpiente (Snake Game)

Este programa es el videojuego de la serpiente (snake game) que se puede encontrar en Google. Como te puedes dar cuenta hay dos archivos, uno llamado 'Snake.c' y otro 'snakeGame.c', el primero fue 
desarrollado en un dispositivio con Windows utilizando las librerías conio.h y windows.h ; el segundo fue desarrollado con un dispositivo con Linux (Fedora) y utiliza las librerías ncurses.h y unistd.h.

El motivo de tener dos archivos es mostrar dos versiones parecidas pero realizadas de manera diferente y en distintas etapas. El que se titula 'Snake.c' fue la versión más actual de 
un proyecto de conio que se realizó en mi primer año de Estudio Técnico Especializado en Computación (ETEC), existe una versión mucho más trabajada pero no pude encontrarla. Por otro lado, 
el llamado 'snakeGame.c' se realizó en mi primer semestre de la licenciatura en Ciencias de la Computación como parte de la práctica extra que me gusta hacer además de mis tareas.

***Traduction***

This program is the snake game that can be found in Google. As you can see there are two files, one called 'Snake.c' and the other 'snakeGame.c', the first one was 
developed on a Windows device using the conio.h and windows.h libraries; the second one was developed on a Linux device (Fedora) and uses the ncurses.h and unistd.h libraries.

The reason for having two files is to show two similar versions but made in different ways and at different stages. The one titled 'Snake.c' was the most current version of 
a conio project that was done in my first year of Technical Study Specialized in Computing (ETEC), there is a much more worked version but I could not find it. On the other hand, 
the so called 'snakeGame.c' was made in my first semester of my Computer Science degree as part of the extra practice that I like to do in addition to my homework.

---

## Table of Contents

- [Características / Features](#caracteristicas--features)
- [Requisitos / Requirements](#requisitos--requirements)
- [Instalación / Installation](#instalación--installation)
- [Uso / Usage](#uso--usage)
- [Licencia / License](#licencia--license)

---

## Caracteristicas / Features

 - Control fluido de la serpiente: Movimiento en las cuatro direcciones con las teclas de flecha.
 - Generación aleatoria de comida: La comida aparece en posiciones aleatorias del tablero.
 - Crecimiento progresivo: Cada vez que la serpiente come, aumenta su longitud.
 - Detección de colisiones: El juego termina si la serpiente choca contra sí misma o contra los bordes del tablero.
 - Sistema de puntuación: Se lleva un conteo de la puntuación basada en la cantidad de comida recogida.
 - Controles accesibles: Se juega completamente con el teclado.
 - Diseño ligero y compatible: Funciona en múltiples plataformas sin requerir instalación compleja.

***Traduction :***

 - Fluid control of the snake: Movement in all four directions with the arrow keys.
 - Random food generation: Food appears at random positions on the board.
 - Progressive growth: Each time the snake eats, it increases in length.
 - Collision detection: The game ends if the snake collides against itself or against the edges of the board.
 - Scoring system: A score count is kept based on the amount of food collected.
 - Accessible controls: Played entirely with the keyboard.
 - Lightweight and compatible design: Works on multiple platforms without requiring complex installation.



---

## Requisitos / Requirements

Los requerimientos para 'snakeGame.c' son :

- Sistema operativo: Cualquier sistema operativo tipo Linux con soporte para compilación de programas en C (se pueden utilizar otros pero hay pasos extras a considerar).
- Librería: `ncurses`
- Terminal compatible con `ncurses`
- Compilador de C: Un compilador de C como GCC (GNU Compiler Collection) o cualquier otro compilador compatible.
- Editor de texto o IDE: Un editor de texto (como Visual Studio Code, Sublime Text, Atom) o un entorno de desarrollo integrado (IDE).

Los requerimientos para 'Snake.c' son :
 
 - Sistema operativo: Un sistema de tipo Windows.
 - Librería: `conio`
 - Compilador de C: Un compilador de C que sea compatible con conio.
 - Editor de texto o IDE: se recomienda Dev-C++.

***Traduction :***

The requirements for ‘snakeGame.c’ are :

- Operating system: Any Linux-like operating system with support for compiling C programs (others can be used but there are extra steps to consider).
- Library: `ncurses`
- Terminal compatible with `ncurses`
- C compiler: A C compiler such as GCC (GNU Compiler Collection) or any other compatible compiler.
- Text editor or IDE: A text editor (such as Visual Studio Code, Sublime Text, Atom) or an integrated development environment (IDE).

The requirements for ‘Snake.c’ are :
 
 - Operating system: A Windows-like system.
 - Library: `conio`
 - C compiler: A C compiler that is compatible with conio.
 - Text editor or IDE: Dev-C++ is recommended.


---

## Instalación / Installation
1. Clona este repositorio.
2. Asegúrate de completar los requerimientos necesarios para el archivo que quieras.
3. Instala las dependencias.

***Traduction :***

1. Clone this repository.
2. Be sure to complete the necessary requirements for the file you want.
3. Install the dependencies.



---

## Uso / Usage
1. Abra su terminal
2. Muévase dentro de la carpeta.
3. Compile su programa, con GCC es :
    ```bash
    gcc -o snakeGame  snakeGame.c -lncurses
    ```
4. Ejecute su programa :
   ```bash
    ./snakeGame
    ```
5. Si todo funcionó correctamente debe de salir la pantalla de inicio.
6. Para jugar solo presione ENTER inmediatamente.
7. Si quiere investigar los demás apartados muevase presionando W o S y presionando enter para entrar a cada apartado.

***Traduction :***

1. Open your terminal
2. Move into the folder.
3. Compile your program, with GCC it is :
   ```bash
    gcc -o snakeGame  snakeGame.c -lncurses
    ```
4. Run your program :
   ```bash
    ./snakeGame
    ```
5. If everything worked correctly you should get the startup screen.
6. To play just press ENTER immediately.
7. If you want to investigate the other sections move by pressing W or S and press enter to enter each section.


---

## Licencia / License
Este proyecto está licenciado bajo la Licencia MIT. Consulte el archivo [LICENCIA](LICENCIA) para obtener más información.

***Traduction :***
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

