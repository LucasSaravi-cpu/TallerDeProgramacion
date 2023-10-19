/*   Leer un archivo de texto NUMEROS.TXT que contiene un número entero en cada línea y
almacenar los números pares es un vector y los impares en otro ignorando los 0.
Luego regrabar el archivo con los pares primero y los impares después.
NOTA: Suponer que en el archivo hay como máximo 50 elementos  . */



#include <stdio.h>

void leerNumerosYReordenarArchivo() {
    FILE *archivo;
    archivo = fopen("NUMEROS.TXT", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    int pares[50];
    int impares[50];
    int num_pares = 0;
    int num_impares = 0;
    int num;

    while (fscanf(archivo, "%d", &num) != EOF) {
        if (num != 0) {
            if (num % 2 == 0) {
                pares[num_pares++] = num;
            } else {
                impares[num_impares++] = num;
            }
        }
    }

    fclose(archivo);

    archivo = fopen("NUMEROS.TXT", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < num_pares; i++) {
        fprintf(archivo, "%d\n", pares[i]);
    }
    for (int i = 0; i < num_impares; i++) {
        fprintf(archivo, "%d\n", impares[i]);
    }

    fclose(archivo);
}

int main() {
    leerNumerosYReordenarArchivo();
    return 0;
}


