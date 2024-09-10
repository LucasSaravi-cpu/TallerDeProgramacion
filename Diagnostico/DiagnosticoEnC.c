/*Desarrollar un procedimiento en Pascal que desde un archivo de texto NUMEROS.TXT cargue datos en una
matriz de NxN enteros (N está en la primera línea del archivo, y en la siguiente están los NxN números).


Desarrollar un procedimiento que genere un arreglo A de registros donde cada uno posea los siguientes
campos: fila, columna y valor. En el arreglo estarán sólo los elementos de la matriz y su posición que cumplen
que: el elemento es múltiplo del que se encuentra en la columna anterior y múltiplo del que se encuentra en
la columna siguiente. (no considerar los elementos en la columna 1 ni en la columna N)
Desarrollar una función que, a partir de la matriz generada, obtenga y retorne la cantidad de elementos pares
en la diagonal secundaria.
Escribir el programa principal que invoque a los subprogramas desarrollados y que muestre el vector A. Definir
los tipos y variables que considere necesarios*/

#include <stdio.h>

#define MAX 10

typedef struct {
    int fila;
    int columna;
    int numero;
} TR;

typedef TR TV[MAX];
typedef int TM[MAX][MAX];

void LeeMatriz(TM mat, int *n) {
    FILE *arch = fopen("numeros.txt", "r");
    if (arch == NULL) {
        perror("No se puede abrir el archivo");
        return;
    }

    fscanf(arch, "%d", n);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(arch, "%d", &mat[i][j]);
        }
    }

    fclose(arch);
}

void GeneraArreglo(TM mat, int n, TV *A, int *l) {
    *l = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++) { // Salto la primera columna
            if (mat[i][j - 1] % mat[i][j] == 0 &&
                mat[i][j + 1] % mat[i][j] == 0 &&
                j < n - 1) {
                (*l)++;
                (*A)[*l - 1].numero = mat[i][j];
                (*A)[*l - 1].fila = i;
                (*A)[*l - 1].columna = j;
            }
        }
    }
}

int CantidadDePares(TM mat, int n) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (mat[i][n - i - 1] % 2 == 0) {
            cont++;
        }
    }

    return cont;
}

void EscribeVector(TV A, int l) {
    for (int i = 0; i < l; i++) {
        printf("%4d", A[i].numero);
    }
    printf("\n");
}

int main() {
    TV A;
    TM mat;
    int L, n;

    LeeMatriz(mat, &n);

    printf("La cantidad de pares en la diagonal secundaria es %d\n", CantidadDePares(mat, n));

    GeneraArreglo(mat, n, &A, &L);

    printf("El vector generado es: \n");
    EscribeVector(A, L);

    return 0;
}
