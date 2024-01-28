// PruebaOMP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 13

void imprimeArreglo(float* d);

int main() {
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    // Inicializar los arreglos
    for (i = 0; i < N; i++) {
        a[i] = i * 23;         // Cada elemento de 'a' es i multiplicado por 10
        b[i] = (i + 13) * 4.1;  // Cada elemento de 'b' es (i + 3) multiplicado por 3.7
    }

    int pedazos = chunk;

    // Suma en paralelo usando OpenMP
#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i]; // Cada elemento de 'c' es la suma de los elementos correspondientes de 'a' y 'b'
    }

    // Imprimir los primeros 'mostrar' elementos de cada arreglo
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: ";
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: ";
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: ";
    imprimeArreglo(c);

    return 0;
}

// Función para imprimir los primeros 'mostrar' elementos de un arreglo
void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}
