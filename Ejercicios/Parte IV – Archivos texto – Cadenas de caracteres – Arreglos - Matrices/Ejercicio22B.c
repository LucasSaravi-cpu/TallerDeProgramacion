/*   Leer un archivo de texto NUMEROS.TXT que contiene un número entero en cada línea y
almacenar los números pares es un vector y los impares en otro  . */


#include <stdio.h>

#define MAX_NUMEROS 50

void leerNumerosYReordenar();


int main() {
    leerNumerosYReordenar();
    return 0;
}



void leerNumerosYReordenar() {
    FILE *archivo = fopen("NUMEROS.TXT", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    int pares[MAX_NUMEROS];
    int impares[MAX_NUMEROS];
    int num_pares = 0;
    int num_impares = 0;
    int num;

    while (fscanf(archivo, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            if (num_pares < MAX_NUMEROS) {
                pares[num_pares++] = num;
            }
        } else {
            if (num_impares < MAX_NUMEROS) {
                impares[num_impares++] = num;
            }
        }
    }

    fclose(archivo);


    printf("Números pares:\n");
    for (int i = 0; i < num_pares; i++) {
        printf("%d\n", pares[i]);
    }


    printf("Números impares:\n");
    for (int i = 0; i < num_impares; i++) {
        printf("%d\n", impares[i]);
    }
}
