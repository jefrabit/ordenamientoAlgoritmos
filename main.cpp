#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// Estructura para almacenar resultado de cada algoritmo
struct Resultado {
    string nombre;
    long long pasos;
    double tiempo;  // en nanosegundos
};

// Función para generar array de números aleatorios
vector<int> generarArray(int n, int minVal, int maxVal) {
    vector<int> arr(n);
    srand(time(NULL) + rand());  // Mejor seed aleatoria
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
    return arr;
}

// Función para imprimir un array
void imprimirArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Función para copiar un array
vector<int> copiarArray(const vector<int>& arr) {
    return vector<int>(arr);
}

// Algoritmo Burbuja
Resultado burbuja(vector<int> arr) {
    Resultado r;
    r.nombre = "Burbuja";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            r.pasos++;  // Contador de comparación
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                r.pasos++;  // Contador de intercambio
            }
        }
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// Algoritmo Selección
Resultado seleccion(vector<int> arr) {
    Resultado r;
    r.nombre = "Seleccion";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            r.pasos++;  // Contador de comparación
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            r.pasos++;  // Contador de intercambio
        }
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// Algoritmo Inserción
Resultado insercion(vector<int> arr) {
    Resultado r;
    r.nombre = "Insercion";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        r.pasos++;  // Contador de comparación
        while (j >= 0 && arr[j] > key) {
            r.pasos++;  // Contador de comparación adicional
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// Algoritmo Shell Sort
Resultado shell(vector<int> arr) {
    Resultado r;
    r.nombre = "Shell";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                r.pasos++;  // Contador de comparación
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            r.pasos++;  // Contador de asignación
        }
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// QuickSort - función auxiliar
int partition(vector<int>& arr, int low, int high, long long& pasos) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        pasos++;  // Contador de comparación
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            pasos++;  // Contador de intercambio
        }
    }
    swap(arr[i + 1], arr[high]);
    pasos++;  // Contador de intercambio
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, long long& pasos) {
    if (low < high) {
        int pi = partition(arr, low, high, pasos);
        quickSortHelper(arr, low, pi - 1, pasos);
        quickSortHelper(arr, pi + 1, high, pasos);
    }
}

// Algoritmo QuickSort
Resultado quickSort(vector<int> arr) {
    Resultado r;
    r.nombre = "QuickSort";
    r.pasos = 0;

    clock_t inicio = clock();

    quickSortHelper(arr, 0, arr.size() - 1, r.pasos);

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// MergeSort - función auxiliar
void merge(vector<int>& arr, int left, int mid, int right, long long& pasos) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        pasos++;  // Contador de comparación
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int>& arr, int left, int right, long long& pasos) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid, pasos);
        mergeSortHelper(arr, mid + 1, right, pasos);
        merge(arr, left, mid, right, pasos);
    }
}

// Algoritmo MergeSort
Resultado mergeSort(vector<int> arr) {
    Resultado r;
    r.nombre = "MergeSort";
    r.pasos = 0;

    clock_t inicio = clock();

    mergeSortHelper(arr, 0, arr.size() - 1, r.pasos);

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// HeapSort - función auxiliar
void heapify(vector<int>& arr, int n, int i, long long& pasos) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        pasos++;  // Contador de comparación
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n) {
        pasos++;  // Contador de comparación
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        pasos++;  // Contador de intercambio
        heapify(arr, n, largest, pasos);
    }
}

// Algoritmo HeapSort
Resultado heapSort(vector<int> arr) {
    Resultado r;
    r.nombre = "HeapSort";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, r.pasos);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        r.pasos++;  // Contador de intercambio
        heapify(arr, i, 0, r.pasos);
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

// Algoritmo Radix Sort
Resultado radixSort(vector<int> arr) {
    Resultado r;
    r.nombre = "RadixSort";
    r.pasos = 0;

    clock_t inicio = clock();
    int n = arr.size();

    // Encontrar el valor máximo
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // Counting sort por cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> output(n);
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
            r.pasos++;  // Contador
        }

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
            r.pasos++;  // Contador de asignación
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    r.tiempo = (double)(clock() - inicio);
    return r;
}

int main() {
    int n, min, max;

    cout << "========================================" << endl;
    cout << "   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Ingrese la cantidad de numeros a generar: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: La cantidad debe ser mayor a 0" << endl;
        return 1;
    }

    cout << "Ingrese el valor minimo del rango: ";
    cin >> min;

    cout << "Ingrese el valor maximo del rango: ";
    cin >> max;

    if (min > max) {
        cout << "Error: El minimo no puede ser mayor que el maximo" << endl;
        return 1;
    }

    cout << endl;

    // Generar array original
    vector<int> arrayOriginal = generarArray(n, min, max);

    cout << "Array generado:" << endl;
    cout << "  ";
    if (n <= 20) {
        imprimirArray(arrayOriginal);
    } else {
        cout << "[Primeros 20 elementos: ";
        for (int i = 0; i < 20; i++) {
            cout << arrayOriginal[i] << (i < 19 ? ", " : "");
        }
        cout << ", ...]" << endl;
    }

    cout << endl;

    // Ejecutar algoritmos y guardar resultados
    vector<Resultado> resultados;

    resultados.push_back(burbuja(copiarArray(arrayOriginal)));
    resultados.push_back(seleccion(copiarArray(arrayOriginal)));
    resultados.push_back(insercion(copiarArray(arrayOriginal)));
    resultados.push_back(shell(copiarArray(arrayOriginal)));
    resultados.push_back(quickSort(copiarArray(arrayOriginal)));
    resultados.push_back(mergeSort(copiarArray(arrayOriginal)));
    resultados.push_back(heapSort(copiarArray(arrayOriginal)));
    resultados.push_back(radixSort(copiarArray(arrayOriginal)));

    cout << "Ejecutando 8 algoritmos de ordenamiento..." << endl;
    cout << endl;

    // Ordenar por tiempo
    for (int i = 0; i < resultados.size() - 1; i++) {
        for (int j = i + 1; j < resultados.size(); j++) {
            if (resultados[i].tiempo > resultados[j].tiempo) {
                swap(resultados[i], resultados[j]);
            }
        }
    }

    cout << "====================================================" << endl;
    cout << "              RESULTADOS (Ordenados por Tiempo)" << endl;
    cout << "====================================================" << endl;
    cout << endl;
    cout << "+------+-----------+------------+---------------+" << endl;
    cout << "| Pos | Algoritmo |   Pasos    | Tiempo (ns)   |" << endl;
    cout << "+------+-----------+------------+---------------+" << endl;

    for (int i = 0; i < resultados.size(); i++) {
        cout << "| " << i + 1 << "        | " << resultados[i].nombre;
        cout << string(15 - resultados[i].nombre.length(), ' ') << "| "
             << resultados[i].pasos << string(12 - to_string(resultados[i].pasos).length(), ' ')
             << "| " << resultados[i].tiempo << "         |" << endl;
    }

    cout << "+------+-----------+------------+---------------+" << endl;

    return 0;
}