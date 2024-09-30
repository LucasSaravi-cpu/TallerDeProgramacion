/*  Escribir un programa que lea N y un vector N elementos desde un archivo de texto DATOS.TXT, y luego
mediante un men� repetitivo invoque a la funci�n correspondiente (desarrolladas en el ejercicio anterior)
mostrando el resultado.*/
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
    int opcion;

    // Leer el n�mero de elementos y los elementos del archivo
    FILE *archivo = fopen("DATOS.TXT", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    fscanf(archivo, "%d", &n); // Leer el tama�o del vector
    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%d", &vector[i]); // Leer los elementos del vector
    }
    fclose(archivo); // Cerrar el archivo

    // Mostrar los elementos le�dos
    printf("Elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    // Men� repetitivo
    do {
        printf("\nMenu:\n");
        printf("1) Hallar el promedio de los elementos positivos.\n");
        printf("2) Hallar el minimo de los impares.\n");
        printf("3) Hallar el maximo de las posiciones pares.\n");
        printf("4) Generar un vector B con los elementos mayores a K.\n");
        printf("5) Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float promedio = promedioPositivos(vector, n);
                printf("El promedio de los elementos positivos es: %.2f\n", promedio);
                break;
            }
            case 2: {
                int minimo = minimoImpares(vector, n);
                if (minimo != -1) {
                    printf("El minimo de los impares es: %d\n", minimo);
                } else {
                    printf("No hay elementos impares en el vector.\n");
                }
                break;
            }
            case 3: {
                maximoPosicionesPares(vector, n);
                break;
            }
            case 4: {
                printf("Ingrese el valor de K: ");
                scanf("%d", &k);
                generarVectorB(vector, n, k, vectorB, &size);
                printf("Elementos mayores a K:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", vectorB[i]);
                }
                printf("\n");
                break;
            }
            case 5: {
                printf("Saliendo del programa...\n");
                break;
            }
            default: {
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
            }
        }
    } while (opcion != 5);

    return 0;
}

// Funci�n para hallar el promedio de los elementos positivos
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

// Funci�n para hallar el m�nimo de los impares
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

// Funci�n para hallar el m�ximo de las posiciones pares
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

// Funci�n para generar un vector B con elementos mayores a K
void generarVectorB(int vector[], int n, int k, int vectorB[], int *size) {
    *size = 0; // Inicializa el tama�o del vector B

    for (int i = 0; i < n; i++) {
        if (vector[i] > k) {
            vectorB[*size] = vector[i];
            (*size)++;
        }
    }
}
