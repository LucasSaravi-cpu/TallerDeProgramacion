/*contar el número de palabras en un archivo de texto, considerando que las palabras están separadas
por espacios, tabulaciones o saltos de líneas*/
#include <stdio.h>

int main() {
    FILE *archivo;
    char palabra[100];
    int words = 0;

    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }


    while (fscanf(archivo, "%s", palabra) == 1) {
        words++;
    }

    fclose(archivo);
    printf("El numero de palabras son : %d\n", words);
    return 0;
}

