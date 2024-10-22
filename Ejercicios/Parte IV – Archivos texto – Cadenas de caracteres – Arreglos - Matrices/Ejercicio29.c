/*29. Sea A una matriz de NxM elementos reales, escribir funciones que permitan:
a. hallar el promedio de los elementos positivos (función float).
b. hallar el mínimo de las columnas impares (función int)
c. hallar el máximo de las filas pares (función void)
d. generar un archivo de texto que contengas una línea por cada fila de la matriz que tienen todos los
valores pares, colocando en la línea NROFILA SUMPARES

*/



#include <stdio.h>
#define MAXFILAS 100
#define MAXCOLUMNAS 100

float promedioPositivos(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);
int minimoColumnasImpares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);
void maximoFilasPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);
 void generarArchivoPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);

int main() {
    int filas, columnas;
    float matriz[MAXFILAS][MAXCOLUMNAS];
    int opcion;
    int i, j;


    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);


    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nLa matriz ingresada es:\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }


     generarArchivoPares(matriz, filas, columnas);
     printf("El archivo PARES.TXT ha sido generado \n" );


    float promedio = promedioPositivos(matriz, filas, columnas);
    printf("El promedio de los elementos positivos es: %f\n", promedio);


     for (j = 1; j < columnas; j += 2) {  // Iterar solo por columnas impares
          int minimo = minimoColumnasImpares(matriz, filas, j);
          printf("El minimo de la columna %d es: %d\n", j, minimo);
         }


     maximoFilasPares(matriz, filas, columnas);


    return 0;
}

// a) Hallar el promedio de los elementos positivos
float promedioPositivos(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    float suma = 0;
    int contador = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (matriz[i][j] > 0) {
                suma += matriz[i][j];
                contador++;
            }
        }
    }

    return (contador > 0) ? (suma / contador) : 0;
}

// b) Hallar el mínimo de las columnas impares
int minimoColumnasImpares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columna) {
    int i;
    int minimo = (int)matriz[0][columna];  // Asumimos el primer valor como mínimo

    for (i = 1; i < filas; i++) {
        if (matriz[i][columna] < minimo) {
            minimo = (int)matriz[i][columna];
        }
    }

    return minimo;
}

// c) Hallar el máximo de las filas pares
void maximoFilasPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    float maximo;

    for (i = 0; i < filas; i += 2) {  // Iterar solo por las filas pares
        maximo = matriz[i][0];
        for (j = 1; j < columnas; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
        printf("El maximo de la fila %d es: %.2f\n", i, maximo);
    }

}

    // d) genera el archivo pares
    void generarArchivoPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    int todosPares;
    int sumaPares;
    FILE *archivo = fopen("PARES.TXT", "w");

    for (i = 0; i < filas; i++) {
        todosPares = 1;
        sumaPares = 0;

        for (j = 0; j < columnas; j++) {
                sumaPares += (int)matriz[i][j];
            if ((int)matriz[i][j] % 2 != 0) {
                todosPares = 0;
                break;
            }
        }

        if (todosPares) {

            fprintf(archivo,"%s", "numero Fila Suma de todos los Pares\n");
            fprintf(archivo, "%d ", i);
            fprintf(archivo, "%d\n", sumaPares);
        }
    }

    fclose(archivo);
}




