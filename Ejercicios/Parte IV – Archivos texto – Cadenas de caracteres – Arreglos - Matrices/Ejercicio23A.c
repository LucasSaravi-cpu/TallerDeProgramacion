/*  contar el número de líneas en un archivo de texto.*/

#include <stdio.h>

int main() {
    FILE *archivo;
    char line[256];
    int lines = 0;

    archivo= fopen("archivo.txt", "r");
    if (archivo== NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }


    while (fgets(line, sizeof(line), archivo) != NULL)  {
        lines++;
    }

    fclose(archivo);
    printf("El numero de lineas del archivo es de : %d\n", lines);
    return 0;
}
