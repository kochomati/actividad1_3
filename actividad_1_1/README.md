# Actividad 1.1 #
> Funciones Iterativas, Recursivas y su análisis de Complejidad

### Tareas ###

Realiza una aplicación en C++ en forma individual,  que calculé la sumatora de 1 hasta n y llame a tres funciones:

1. sumaAlterativa -
    descripción: Calcule la sumatoria de 1 hasta n con un metodo iterativo;
    entrada: Un entero positivo (n);
    salida: La sumatoria de 1 hasta n;
    precondición: n es un entero positivo;
    postcondición: nada;
    
2. sumaRecursiva - 
    descripción: Calcule la sumatoria de 1 hasta n con un metodo recursivo;
    entrada: Un entero positivo (n);
    salida: La sumatoria de 1 hasta n;
    precondición: n es un entero positivo;
    postcondición: nada;

3. sumaDirecta - 
    descripción: Calcule la sumatoria de 1 hasta n con un metodo directo;
    entrada: Un entero positivo (n);
    salida: La sumatoria de 1 hasta n;
    precondición: n es un entero positivo;
    postcondición: nada;

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

La aplicación leerá un número ```k```, que es la cantidad de enteros positivos de los cuales se calculará las sumatoria por los tres métodos y posteriormente vendrán los ```k``` números enteros positivos (n), y por cada número se desplegará la sumatoria con el siguiente formato:

    suma_Iterativa suma_Recursiva suma_Directa

Ejemplo de Entrada:
```
3
4
1
5
```
Ejemplo de Salida:
```
10 10 10
1 1 1
15 15 15
```

Lista de 4 casos de prueba para cada una de las funcionalidades.

### Subcompetencias Evaluadas ###
> SICT0301B - Evalúa los componentes que integran una problemática de acuerdo a principios y procesos computacionales.

> SICT0302B - Toma decisiones en la solución de problemas en condiciones de incertidumbre y diferentes niveles de complejidad con base metodologías de investigación y de cómputo.

> SICT0303B - Implementa acciones científicas e ingenieriles o procesos computacionales que cumplen con el tipo de solución requerida.

> SEG0702A - Tecnologías de Vanguardia. Evalúa diversas tecnologías con apertura a la búsqueda e implementación de alternativas relevantes en la transformación de la práctica profesional.

### Estuctura de Archivos ###
- main.cpp
- .gitignore
- README.md
- reflexion
    - actividad1_1.pdf

### Compilación y Ejecución ###
* Descargar repositorio
* Realizar compilación: macOS + Linux
```
$ ~ clang++ main.cpp -o sumas
```
* Realizar compilación: Windows
```
$ ~ g++ main.cpp -o sumas
```
* Correr archivo compilado 
```
$ ~ ./sumas
```