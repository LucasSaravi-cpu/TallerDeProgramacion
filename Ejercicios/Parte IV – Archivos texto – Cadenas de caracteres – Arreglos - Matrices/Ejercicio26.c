/* Sea A un vector de N elementos enteros, escribir funciones que permitan:
a. hallar el promedio de los elementos positivos (función float).
b. hallar el mínimo de los impares (función int)
c. hallar el máximo de las posiciones pares (función void)
d. generar un vector B con los elementos de A que sean mayores a K (K debe leerse*/

#include <stdio.h>
#define MAXELEMENTOS 100

// Funciones
float promedioPositivos(int vector[], int n);
int minimoImpares(int vector[], int n);
void maximoPosicionesPares(int vector[], int n);
void generarVectorB(int vector[], int n, int k, int vectorB[], int *size);

int main() {
    int vector[MAXELEMENTOS];
    int n;
    int k;
    int vectorB[MAXELEMENTOS];
    int size = 0;


    FILE *archivo = fopen("vector.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
       
    }else{

    fscanf(archivo, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%d", &vector[i]);
    }
    fclose(archivo);
    

    printf("Elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");


    float promedio = promedioPositivos(vector, n);
    printf("El promedio de los elementos positivos es: %.2f\n", promedio);

    // Calcular y mostrar el mínimo de los impares
    int minimo = minimoImpares(vector, n);
    if (minimo != -1) {
        printf("El minimo de los impares es: %d\n", minimo);
    } else {
        printf("No hay elementos impares en el vector.\n");
    }


    maximoPosicionesPares(vector, n);


    printf("Ingrese el valor de K: ");
    scanf("%d", &k);
    generarVectorB(vector, n, k, vectorB, &size);


    printf("Elementos mayores a K:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vectorB[i]);
    }
    printf("\n");
    }
    return 0;
}

// Función para hallar el promedio de los elementos positivos
float promedioPositivos(int vector[], int n) {
    int contador = 0;
    float suma = 0.0;

    for (int i = 0; i < n; i++) {
        if (vector[i] > 0) {
            suma += vector[i];
            contador++;
        }
    }

    return (contador > 0) ? suma / contador : 0.0;
}

// Función para hallar el mínimo de los impares
int minimoImpares(int vector[], int n) {
    int minimo = -1;

    for (int i = 0; i < n; i++) {
        if (vector[i] % 2 != 0) {
            if (minimo == -1 || vector[i] < minimo) {
                minimo = vector[i];
            }
        }
    }

    return minimo;
}

// Función para hallar el máximo de las posiciones pares
void maximoPosicionesPares(int vector[], int n) {
    int maximo = -1;

    for (int i = 0; i < n; i += 2) {
        if (maximo == -1 || vector[i] > maximo) {
            maximo = vector[i];
        }
    }

    if (maximo != -1) {
        printf("El maximo de las posiciones pares es: %d\n", maximo);
    } else {
        printf("No hay elementos en posiciones pares.\n");
    }
}

// Función para generar un vector B con elementos mayores a K
void generarVectorB(int vector[], int n, int k, int vectorB[], int *size) {
    *size = 0; // Inicializa el tamaño del vector B

    for (int i = 0; i < n; i++) {
        if (vector[i] > k) {
            vectorB[*size] = vector[i];
            (*size)++;
        }
    }
}
