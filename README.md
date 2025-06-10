# Análisis y Comparación de Algoritmos de Ordenamiento 📊

Este repositorio contiene implementaciones de diversos algoritmos de ordenamiento y un generador de archivos de prueba para evaluar su rendimiento.

## 🛠️ Compilación y Ejecución

#### Programa Principal (`main`)

Compila y ejecuta los algoritmos de ordenamiento sobre archivos de entrada.

**Compilación:**
Para compilar el programa únicamente es necesario ejecutar el siguiente comando:
```bash
make
```
Este generará un ejecutable _main_ con el cual se podrán realizar las pruebas.

**Ejecución:**
```bash
./main <archivo_a_leer> <A> [tamaño_de_cada_arreglo]
```
<archivo_a_leer>: Ruta del archivo con los datos de entrada

<A>: Algoritmo a utilizar:
0) HeapSort
1) QuickSort
2) Sort (STL)
3) RandomizedQuickSort
4) MergeInsertionSort (Tim Sort)
5) MergeSort
6) InsertionSort

[tamaño_de_cada_arreglo] (opcional): Tamaño de cada arreglo a ordenar (si no se coloca nada, el programa considerará el archivo completo como un solo arreglo, mientras que al colocar un número (ej: 10), el programa ordenará en subarreglos del valor que se coloque hasta que se acabe el programa). 

#### Ejemplos:
- Ejecutar el archivo main con entrada el archivo _example.bin_, probando el sort de la STL y considerando que cada arreglo es de tamaño 10000.
```bash
./main example.bin 2 10000
```
- Ejecutar el archivo main con entrada el archivo _example.bin_, probando HeapSort y considerando que el archivo completo es un solo arreglo.
```bash
./main example.bin 0
```

#### Generador de archivos con valores binarios para testear main (`randomNumbersGeneratorBinary`)
**Compilación:**

```bash
g++ randomNumbersGeneratorBinary.cpp -o c
```

**Ejecución:**
```bash
./c <A> <cantidad_de_arreglos> <tamaño_de_cada_arreglo> <rango_de_números> <archivo_a_guardar>
```
<A>: Tipo de distribución:
0) Aleatorios
1) Ordenados ascendente
2) Ordenados descendente
3) Todos iguales
4) Mitad ordenada, mitad random
5) Mitad random, mitad ordenada

<cantidad_de_arreglos>: Número de arreglos a generar
<tamaño_de_cada_arreglo>: Tamaño de cada arreglo generado 
<rango_de_números>: Rango de valores para los números generados
<archivo_a_guardar>: Nombre del archivo de salida

 (notar que lo que hace cantidad_de_arreglos es multiplicar el tamaño de cada arreglo por la cantidad de arreglos que se quieren generar en el archivo)
#### Ejemplos:
- Generar 50 arreglos aleatorios de 200 elementos con valores entre 0-4999 en el archivo example.bin 
```bash
./c 0 50 200 5000 example.bin
```
- Generar 5 arreglos con mitad ordenada/mitad random de 500 elementos (valores 0-1999):
```bash
./c 4 5 500 2000 example.bin
```


## Contribuyentes ✨
* [Juan Felipe Raysz Muñoz](https://github.com/Sephir0ath)
* [Francisca Isidora Núñez Larenas](https://github.com/sshiro0)
* [Oliver Isaías Peñailillo Sanzana](https://github.com/pyrrss)
