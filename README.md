# SimplestJson

## EN
This small project is the result of my vast knowledge about C++ and is the first step to start making my own developments and upload them to Github so I can share them with anyone. I've decided to make a small library in C++ to manage JSON, allowing to create a JSON object, read it from a text string, or a file and print it by console or in a file too.

I have to mention that I'm a computer scientist with little work and programming experience, so my code may contain errors, bad practices and even be less efficient than it should be, but I think that's inevitable, so I ask for patience and, if you want to add some constructive criticism or some improvement, it would be of great help.

I also mention the library on which this project is based, *boost*, an open-source library with a lot of features that facilitate many tasks in C++. This project uses a small part of the library, namely the boost::any object and the boost::trim and boost::trim_copy functionalities to facilitate the handling of strings. I thank the boost community for all their work, which allows other programmers like me to make their projects easier.

## ES
Este pequeño proyecto es el resultado de mis vastos conocimientos sobre C++ y es el primer paso para comenzar a hacer desarrollos propios y subirlos a Github para poder compartirlos con quien lo desee. He decidido realizar una pequeña librería en C++ para el manejo de JSON, permitiendo crear un objeto JSON, leerlo desde una cadena de texto, o un archivo e imprimirlo por consola o en un archivo también.

He de mencionar que soy un informático con poca experiencia laboral y en la programación, por lo que mi código puede contener errores, malas prácticas e incluso ser menos eficiente de lo que debería, pero creo que eso es inevitable, por eso pido paciencia y, si deseas añadir alguna crítica constructiva o alguna mejora, sería de gran ayuda.

También menciono a la librería sobre la que se basa este proyecto, *boost*, una librería open-source con una gran cantidad de funcionalidades que facilitan muchas tareas en C++. Este proyecto utiliza una pequeña parte de la librería, concretamente el objeto boost::any y las funcionalidades boost::trim y boost::trim_copy para facilitar el manejo de cadenas de caracteres. Agradezco a la comunidad de boost todo su trabajo, que permite que otros programadores como yo puedan realizar más fácilmente sus proyectos.

## To be considered
* I have made this project with WSL (Windows Subsystem for Linux), using a Kali distribution, so I check compiles in a Linux system over GCC (GNU Compiler Collection).

* Minimum C++ standard for this library is C++11

* Boost libraries version used is 1.72.0

## How to use library
There are two forms to use this library:

1. **Compile library and add to project**\
You can compile library in a **.o** file and add to project:
```
# First, compile library
g++ -c -I/path/to/project/include/folder -o json.o json.cpp

# Then, add library to your program
g++ -I/path/to/project/include/folder -L/path/to/library/folder -l:json.o -o your_program your_program.cpp
```

2. **Add all files to your project**\
Also, you can compile always library with the rest of your code:
```
g++ -I/path/to/project/include/folder -o your_program your_program.cpp json.cpp
```

## Test examples
In examples folder, you can see some examples of library usage, with 4 examples:

1. **Object definition**\
In *object-definition-example.cpp* you can see how define a JSON object with this library programatically.

2. **File dumping**\
In *file-dump-example.cpp* you can see how export a JSON object to a file.

3. **Data accessing**\
In *data-accessing-example.cpp* you can see how to get a single value from a JSON object.

4. **Easy data accessing**
In *easy-data-accessing-example.cpp* you can see hoy to get a single value from a JSON object using a selector string.

If you want to test this examples, you can compile library and each example using Makefile. Static library will be compiled into empty *lib* folder and each example will be sompiled into empty *bin* folder. When all files have been compiles, simply execute it with *./bin/{name of example}* from project folder.