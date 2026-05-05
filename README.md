# Comparador de Algoritmos de Ordenamiento

Proyecto para comparar diferentes algoritmos de ordenamiento midiendo la cantidad de pasos y el tiempo de ejecución en milisegundos.

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

El programa pedirá:
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
  [47, 237, 574, 114, 777, 737, 583, 7, 93, 951, 285, 378, 126, 48, 692, 248, 788, 661, 803, 822, 516, 4, 338, 730, 836, 934, 19, 663, 66, 484, 595, 112, 73, 168, 578, 849, 256, 160, 856, 349, 110, 492, 726, 588, 540, 417, 835, 327, 430, 638, 148, 945, 993, 837, 27, 828, 770, 397, 842, 836, 233, 788, 299, 305, 307, 876, 505, 563, 35, 712, 263, 145, 204, 988, 84, 743, 756, 918, 421, 537, 907, 568, 834, 899, 404, 212, 79, 526, 608, 920, 361, 192, 60, 659, 496, 366, 887, 353, 280, 921]

Ejecutando 8 algoritmos de ordenamiento...

====================================================
              RESULTADOS (Ordenados por Tiempo)
====================================================

+------+-----------+------------+---------------+
| Pos | Algoritmo |   Pasos    | Tiempo (ms)   |
+------+-----------+------------+---------------+
| 1        | RadixSort      | 600         | 0.011         |
| 2        | QuickSort      | 1143        | 0.015         |
| 3        | Shell          | 928         | 0.017         |
| 4        | Insercion      | 2883        | 0.022         |
| 5        | HeapSort       | 1593        | 0.024         |
| 6        | Seleccion      | 5045        | 0.033         |
| 7        | MergeSort      | 534         | 0.051         |
| 8        | Burbuja        | 7731        | 0.091         |
+------+-----------+------------+---------------+

Nota: Los tiempos están en milisegundos (ms)

Ejecucion completada exitosamente!
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
Ingrese el valor minimo del rango: 10
Ingrese el valor maximo del rango: 500

Array generado (50 elementos):
  [287, 156, 452, 98, 234, 321, 487, 175, 63, 289, 410, 52, 398, 267, 143, 376, 91, 228, 319, 456, 104, 381, 67, 293, 165, 438, 82, 351, 199, 422, 115, 274, 359, 148, 465, 77, 212, 326, 89, 397, 251, 184, 443, 131, 308, 395, 58, 237, 169, 484, 96]

Ejecutando 8 algoritmos de ordenamiento...

====================================================
              RESULTADOS (Ordenados por Tiempo)
====================================================

+------+-----------+------------+---------------+
| Pos | Algoritmo |   Pasos    | Tiempo (ms)   |
+------+-----------+------------+---------------+
| 1        | QuickSort      | 284         | 0.004         |
| 2        | RadixSort      | 350         | 0.006         |
| 3        | Shell          | 328         | 0.007         |
| 4        | HeapSort       | 635         | 0.009         |
| 5        | Insercion      | 687         | 0.011         |
| 6        | Seleccion      | 1270        | 0.018         |
| 7        | MergeSort      | 226         | 0.023         |
| 8        | Burbuja        | 1893        | 0.029         |
+------+-----------+------------+---------------+

Nota: Los tiempos están en milisegundos (ms)

Ejecucion completada exitosamente!
```

## Notas

- Los resultados se ordenan de menor a mayor según el tiempo de ejecución
- Los pasos incluyen tanto comparaciones como intercambios/asignaciones
- Los tiempos pueden variar según el hardware y la carga del sistema
- Se usa la función `clock()` de C++ para medir el tiempo en milisegundos