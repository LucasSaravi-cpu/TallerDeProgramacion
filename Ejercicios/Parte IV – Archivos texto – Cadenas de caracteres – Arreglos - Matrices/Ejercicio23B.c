/*contar el número de palabras en un archivo de texto, considerando que las palabras están separadas
por espacios, tabulaciones o saltos de líneas*/
#include <stdio.h>

int main() {
    FILE *file;
    char palabra[100];
    int words = 0;

    file = fopen("archivo.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Usar scanf para leer palabras del archivo
    while (fscanf(file, "%99s", palabra) == 1) {
        words++;
    }

    fclose(file);
    printf("El numero de palabras son : %d\n", words);
    return 0;
}
