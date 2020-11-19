# Actividad 2.1 #
> Algoritmos de Búsqueda y Ordenamiento

### Tareas ###

Diseña e implementa en forma individual, siguiendo la especificación de la interfaz para un ADT que represente una estructura de datos lineal:

Dependiendo del ADT de estructura de datos lineal deberán implementar las operaciones CRUD (Create, Read (buscar), Update, Delete) elementos en la estructura de datos. Algunas operaciones no aplican para ciertas estructura de datos.

1. create - 
    descripción: Ordene en forma ascendente los datos con el método de Intercambio;
    entrada: Un vector<int> con los n numeros;
    salida: nada;
    precondición: El vector<int> debe contener los n números;
    postcondición: El vector<int> contendrá los datos ya ordenados;
    
2. read - 
    descripción: Ordene en forma ascendentelos datos con el método de Burbuja;
    entrada: Un vector<int> con los n numeros;
    salida: Nada;
    precondición: El vector<int> debe contener los n números;
    postcondición: El vector<int> contendrá los datos ya ordenados;

3. update - 
    descripción: Ordene en forma ascendente los datos con el método de Merge;
    entrada: Un vector<int> con los n numeros;
    salida: nada;
    precondición: El vector<int> debe contener los n números;
    postcondición: El vector<int> contendrá los datos ya ordenados;

4. delete - 
    descripción: Buscar con la busqueda secuencial un dato entero dentro del vector.;
    entrada: El vector <int> del espacio de búsqueda y el dato entero que se desea buscar.;
    salida: El índice donde se encuentra el dato o -1 en caso de que no se localice;
    precondición: El vector<int> debe contener los n números;
    postcondición: Ninguna;

La aplicación deberá leer los n datos ordenarlos, decir la cantidad de comparaciones de cada uno de los tres métodos, posteriormente deberá leer las q consultas de datos, diciendo la posición donde se encuentra el dato en el arreglo ordenado (-1 en caso de que no se encuentre) y la cantidad de comparaciones que hizo tanto por la búsqueda secuencial como por la búsqueda binaria.

Entrada:

Primero vendrá una línea con la n (número de datos) seguido de las n lineas con los datos numéricos, posteriormente vendrá una línea con la q, y posteriormente vendrá los q números que se desean consultar.

Salida:

En una línea vendrán la cantidad de comparaciones que arrojó el ordenamiento de intercambio, el ordenamiento de burbuja y el ordenamiento de MergeSort, separados por un espacio.

Después vendrán q lineas (una por cada consulta) con el formato de posición, cantidad de comparaciones por búsqueda secuencial y cantidad de comparaciones por búsqueda binaria.

Ejemplo de Entrada:
```
8
10
4
8
12
20
15
54
18
4
20
54
100
12
```
Ejemplo de Salida:
```
28 18 14
6 7 3
7 8 4
-1 8 4
3 4 1
```

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

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
    - actividad1_2.pdf

### Compilación y Ejecución ###
* Descargar repositorio
* Realizar compilación: macOS + Linux
```
$ ~ clang++ main.cpp -o busqueda
```
* Realizar compilación: Windows
```
$ ~ g++ main.cpp -o busqueda
```
* Correr archivo compilado 
```
$ ~ ./busqueda
```