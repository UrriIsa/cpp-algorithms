# Números de Kaprekar (Kaprekar Numbers)

El programa permite al usuario ingresar un rango de números y verifica cada número en el rango para determinar si es un número de Kaprekar. Si encuentra alguno, lo imprime; de lo contrario, notifica que no se encontraron números de Kaprekar en el rango.

The program allows the user to enter a range of numbers and checks each number in the range to determine if it is a Kaprekar number. If it finds one, it prints it; otherwise, it reports that no Kaprekar numbers were found in the range.

---

## Table of Contents

- [Características / Features](#caracteristicas--features)
- [Requisitos / Requirements](#requisitos--requirements)
- [Instalación / Installation](#instalación--installation)
- [Uso / Usage](#uso--usage)
- [Licencia / License](#licencia--license)

---

## Caracteristicas / Features

- Permite encontrar números de Kaprekar dentro de un rango definido por el usuario.
- Valida que los números de entrada sean correctos antes de proceder con la verificación.
- Evita verificar múltiplos de 10, ya que no son considerados números de Kaprekar.
- Presenta los números de Kaprekar encontrados en el rango o notifica si no se encuentran.
- Ofrece la opción de repetir la búsqueda con diferentes rangos.
- Utiliza un enfoque eficiente para dividir el cuadrado del número y comprobar las condiciones de Kaprekar.

***Traduction :***

- Allows finding Kaprekar numbers within a user-defined range.
- Validates that the input numbers are correct before proceeding with the verification.
- Avoid verifying multiples of 10, as they are not considered Kaprekar numbers.
- Displays the Kaprekar numbers found in the range or notifies if they are not found.
- Offers the option to repeat the search with different ranges.
- Uses an efficient approach to divide the square of the number and check for Kaprekar conditions.

---

## Requisitos / Requirements

- Sistema operativo: Cualquier sistema operativo con soporte para compilación de programas en C, como Linux, Windows (con MinGW o Cygwin), macOS, etc.
- Compilador de C: Un compilador de C como GCC (GNU Compiler Collection) o cualquier otro compilador compatible, como Clang (en macOS) o MinGW en Windows.
- Editor de texto o IDE: Un editor de texto (como Visual Studio Code, Sublime Text, Atom) o un entorno de desarrollo integrado (IDE) como Code::Blocks o Dev-C++.

***Traduction :***
- Operating system: Any operating system with support for C program compilation, such as Linux, Windows (with MinGW or Cygwin), macOS, etc.
- C compiler: A C compiler such as GCC (GNU Compiler Collection) or any other compatible compiler, such as Clang (on macOS) or MinGW on Windows.
- Text editor or IDE: A text editor (such as Visual Studio Code, Sublime Text, Atom) or an integrated development environment (IDE) such as Code::Blocks or Dev-C++.

---

## Instalación / Installation
1. Clona este repositorio o descarga el archivo `kaprekar.c`.
2. Asegúrate de tener un compilador de C en tu sistema.
3. Guarda el archivo en el directorio de tu proyecto.

***Traduction :***
1. Clone this repository or download the `kaprekar.c` file.
2. Make sure you have a C compiler on your system.
3. Save the file in your project directory.


---

## Uso / Usage
1. Abra su terminal.
2. Compile su programa :
    ```bash
    gcc -o Kaprekar Kaprekar.c
    ```
3. Ejecute su programa :
   ```bash
    ./Kaprekar
    ```
4. Si todo funcionó correctamente debe de salir :
   ```bash
    Dame el número de inicio:
    ```
5. Interactue escribiendo los rangos de números que quiere considerar.
6. Al momento de querer detener el programa solo vasta dar un caracter diferente a 'S' para salir.

***Traduction :***
1. Open your terminal.
2. Compile your program :
   ````bash
   gcc -o Kaprekar Kaprekar.c
   ````
3. Run your program :
   ````bash
  ./Kaprekar
   ````
4. If everything worked correctly you should exit :
   ````bash
   Dame el número de inicio:
   ````
  Which means "Give me the start number:"
5. Interact by typing the number ranges you want to consider.
6. When you want to stop the program, just type a character other than 'S' to exit.


---

## Licencia / License
Este proyecto está licenciado bajo la Licencia MIT. Consulte el archivo [LICENCIA](LICENCIA) para obtener más información.

***Traduction :***
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
