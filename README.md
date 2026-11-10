# Algoritmos Greedy en C++

Dos problemas resueltos con la estrategia voraz (Greedy):

1. **Mochila fraccional** (`mochila_fraccional.cpp`): se ordenan los objetos por razón valor/peso y se llena la mochila con los de mayor razón primero.
2. **Cobertura de antenas** (`cobertura_antenas.cpp`): se coloca cada antena en la posición de la primera casa sin cobertura + R.

## Cómo ejecutar el proyecto

Se necesita un programa para compilar C++, por ejemplo Code::Blocks o Dev-C++.

1. Descargar los archivos del repositorio.
2. Abrir el archivo `.cpp` que se quiere probar:
- Code::Blocks: menú File > Open.
- Dev-C++: menú Archivo > Abrir.
3. Compilar y ejecutar:
- Code::Blocks: presionar F9 (Build and run).
- Dev-C++: presionar F11 (Compilar y ejecutar).
4. Escribir los datos que pide el programa en la ventana negra.

Si se usa la terminal: `g++ archivo.cpp -o programa` y luego ejecutar `programa`.

## Mochila fraccional

Datos que pide el programa: capacidad máxima, cantidad de objetos, y por cada objeto su nombre, valor y peso.

Ejemplo de entrada:

    50
    3
    A 60 10
    B 100 20
    C 120 30

## Cobertura de antenas

Datos que pide el programa: el valor de R, la cantidad de casas y las posiciones de las casas.

Ejemplo de entrada:

    5
    7
    1 2 7 11 20 21 30

## Complejidad

Ambos algoritmos son O(n log n), porque el ordenamiento es la operación más costosa.