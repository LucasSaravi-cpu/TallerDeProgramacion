
/* buscar una palabra específica (leída desde teclado previamente) en un archivo de texto e indicar
cuántas veces aparece.
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char palabra[100];
    char line[256];
    int count = 0;

    printf("Introduce la palabra a buscar: ");
    scanf("%s", palabra);

    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");

    } else{

    while (fscanf(archivo, "%s", line) ==1) {
        if (strcmp(line, palabra) == 0) {
            count++;
        }
    }

    fclose(archivo);

    }
    printf("La palabra '%s' aparece %d veces.\n", palabra, count);
    return 0;
}

