# Clasificador de Estrellas (Star Classifier)

El programa permite al usuario clasificar estrellas mediante los valores de sus temperaturas. Esto se logra leyendo los datos desde un archivo con terminación .csv. Imprime el nombre, su clasificación (definida por una letra), densidad y el valor numérico de su temperatura. 
Nota : todos los valores de las estrellas que están contenidos en el documento .csv se imprimen con colores, puede que no funcione para todos los sistemas operativos.

***Traduction :***

The program allows the user to classify stars by their temperature values. This is accomplished by reading the data from a .csv file. It prints the name, its classification (defined by a letter), density and the numerical value of its temperature. 
Note : all star values contained in the .csv document are printed with colors, it may not work for all operating systems.


---

## Table of Contents

- [Características / Features](#caracteristicas--features)
- [Requisitos / Requirements](#requisitos--requirements)
- [Instalación / Installation](#instalación--installation)
- [Uso / Usage](#uso--usage)
- [Licencia / License](#licencia--license)

---

## Caracteristicas / Features

- Permite clasificar estrellas en base a su temperatura.
- Valida que se pueda leer el archivo .csv, en caso de no poder se avisará desde el inicio.
- Evita errores al momento de leer cada uno de los datos, en caso de no poder imprime que hubo un error.
- Presenta todos y cada uno de los datos en terminal.
- Utiliza un enfoque eficiente para crear structuras para cada estrella y sus caracteristicas.

***Traduction :***

- Allows to classify stars based on their temperature.
- Validates that the .csv file can be read, in case of not being able to it will be warned from the beginning.
- Avoids errors at the moment of reading each one of the data, in case of not being able it prints that there was an error.
- It presents each and every one of the data in terminal.
- It uses an efficient approach to create structures for each star and its characteristics.

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
1. Clona este repositorio.
2. Asegúrate de tener un compilador de C en tu sistema.
3. Asegúrate de tener un lector de archivos .csv.

***Traduction :***
1. Clone this repository.
2. Make sure you have a C compiler on your system.
3. Make sure you have a .csv file reader.

---

## Uso / Usage
1. Abra su terminal.
2. Muévase dentro de la carpeta scr.
3. Compile su programa, con GCC es :
    ```bash
    gcc -o main  main.c functions.c functions.h 
    ```
4. Ejecute su programa :
   ```bash
    ./main
    ```
5. Si todo funcionó correctamente debe de salir la clasificación y caracteristicas de todas las estrellas dentro del archivo .csv.
6. Si algo salió mal con el .csv se imprimirá :
   ```bash
    Error al arbir archivo 
    No se pudieron leer las estrellas.
    ```
7. Si algo salió mal con la lectura de los datos se imprimirá en qué falló.
8. Puede interactuar añadiendo o eliminando registros dentro del archivo .csv.
9. Si se realiza un cambio dentro del archivo .csv, para ver si no hubo errores compile y ejecute nuevamente.

***Traduction :***
1. Open your terminal.
2. Move into the scr folder.
3. Compile your program, with GCC is :
   ```bash
    gcc -o main  main.c functions.c functions.h 
    ```
4. Run your program :
   ```bash
    ./main
    ```
5. If everything worked correctly it should output the rating and characteristics of all the stars in the .csv file.
6. If something went wrong with the .csv file it will print :
     ````bash
     Error al arbir archivo 
     No se pudieron leer las estrellas.
     ````
    That means :  Error while loading file. Could not read stars.
7. If something went wrong with the reading of the data it will print what went wrong.
8. You can interact by adding or deleting records within the .csv file.
9. If a change is made within the .csv file, to see if there were no errors compile and run it again.



---

## Licencia / License
Este proyecto está licenciado bajo la Licencia MIT. Consulte el archivo [LICENCIA](LICENCIA) para obtener más información.

***Traduction :***
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
