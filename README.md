# Comparador de Algoritmos de Ordenamiento

Proyecto para comparar diferentes algoritmos de ordenamiento midiendo la cantidad de pasos y el tiempo de ejecución en nanosegundos.

## Algoritmos Incluidos

1. **Burbuja (Bubble Sort)** - Algoritmo simple que compara elementos adyacentes
2. **Selección (Selection Sort)** - Encuentra el mínimo en cada iteración
3. **Inserción (Insertion Sort)** - Inserta elementos en su posición correcta
4. **Shell (Shell Sort)** - Variación de inserción con gaps decrecientes
5. **QuickSort** - Algoritmo dividir y conquistar basado en pivotes
6. **MergeSort** - Algoritmo dividir y conquistar con fusión
7. **HeapSort** - Usa estructura de heap binario
8. **RadixSort** - Ordenamiento por dígitos

## Compilar

```bash
g++ main.cpp -o programa
```

## Ejecutar

```bash
./programa
```

El programa pedirà:
- Cantidad de números a generar
- Valor mínimo del rango
- Valor máximo del rango

## Ejemplo de Ejecución 1

```
========================================
   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
========================================
  Algoritmos: Burbuja, Seleccion, Insercion
              Shell, QuickSort, MergeSort
              HeapSort, RadixSort
========================================

Ingrese la cantidad de numeros a generar: 100
Ingrese el valor minimo del rango: 1
Ingrese el valor maximo del rango: 1000

Array generado (100 elementos):
  [421, 610, 173, 249, 138, 817, 786, 10, 256, 219, 195, 460, 702, 717, 877, ... ,13]

Ejecutando 8 algoritmos de ordenamiento...

====================================================
              RESULTADOS (Ordenados por Tiempo)
====================================================

+------+-----------+------------+---------------+
| Pos | Algoritmo |   Pasos    | Tiempo (ns)   |
+------+-----------+------------+---------------+
| 1        | Shell          | 860         | 8         |
| 2        | QuickSort      | 1071        | 8         |
| 3        | RadixSort      | 800         | 8         |
| 4        | Insercion      | 2668        | 11         |
| 5        | HeapSort       | 1601        | 12         |
| 6        | Seleccion      | 5042        | 19         |
| 7        | MergeSort      | 545         | 29         |
| 8        | Burbuja        | 7519        | 46         |
+------+-----------+------------+---------------+

Nota: Los tiempos están en nanosegundos (ns)
      1 segundo = 1,000,000,000 nanosegundos
```

## Ejemplo de Ejecución 2

```
========================================
   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
========================================
  Algoritmos: Burbuja, Seleccion, Insercion
              Shell, QuickSort, MergeSort
              HeapSort, RadixSort
========================================

Ingrese la cantidad de numeros a generar: 50
Ingrese el valor minimo del rango: 100
Ingrese el valor maximo del rango: 500

Array generado (50 elementos):
  [429, 235, 150, 441, 260, 387, 109, 322, 241, 477, 436, 276, 469, 251, 251, ... ,236]

Ejecutando 8 algoritmos de ordenamiento...

====================================================
              RESULTADOS (Ordenados por Tiempo)
====================================================

+------+-----------+------------+---------------+
| Pos | Algoritmo |   Pasos    | Tiempo (ns)   |
+------+-----------+------------+---------------+
| 1        | Insercion      | 687         | 5         |
| 2        | Shell          | 346         | 5         |
| 3        | QuickSort      | 447         | 5         |
| 4        | RadixSort      | 300         | 6         |
| 5        | HeapSort       | 665         | 7         |
| 6        | Seleccion      | 1270        | 8         |
| 7        | Burbuja        | 1863        | 17         |
| 8        | MergeSort      | 228         | 20         |
+------+-----------+------------+---------------+

Nota: Los tiempos están en nanosegundos (ns)
      1 segundo = 1,000,000,000 nanosegundos
```

## Notas

- Los resultados se ordenan de menor a mayor según el tiempo de ejecución
- Los pasos incluyen tanto comparaciones como intercambios/asignaciones
- Los tiempos pueden variar según el hardware y la carga del sistema
- Se usa la función `clock()` de C++ para medir el tiempo en nanosegundos