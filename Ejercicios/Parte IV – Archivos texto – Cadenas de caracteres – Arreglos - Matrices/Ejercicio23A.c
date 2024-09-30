/*  contar el número de líneas en un archivo de texto.*/

#include <stdio.h>

int main() {
    FILE *file;
    char line[256];
    int lines = 0;

    file = fopen("archivo.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }


    while (fscanf(file, "%255[^\n]\n", line) == 1) {
        lines++;
    }

    fclose(file);
    printf("El numero de lineas del archivo es de : %d\n", lines);
    return 0;
}
