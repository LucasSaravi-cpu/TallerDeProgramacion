/* buscar una palabra específica (leída desde teclado previamente) en un archivo de texto e indicar
cuántas veces aparece.
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char palabra[100];
    char line[256];
    int count = 0;

    printf("Introduce la palabra a buscar: ");
    scanf("%s", palabra);

    file = fopen("archivo.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while (fscanf(file, "%255s", line) != EOF) {
        if (strcmp(line, palabra) == 0) {
            count++;
        }
    }

    fclose(file);
    printf("La palabra '%s' aparece %d veces.\n", palabra, count);
    return 0;
}
