/*  Ej. 22 – Desarrollar programas modularizados para:
a) Leer 10 cadenas de caracteres por teclado (pueden tener espacios) y grabarlas en un archivo
de texto CADENAS.TXT (una por línea). Desde el archivo creado, mostrar la cadena más larga. . */



#include <stdio.h>
#include <string.h>

void leerCadenasYGrabarArchivo() {
    FILE *archivo;
    archivo = fopen("CADENAS.TXT", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    char cadena[100];
    for (int i = 0; i < 10; i++) {
        printf("Ingrese una cadena: ");
        scanf(" %[^\n]s", cadena);
        fprintf(archivo, "%s\n", cadena);
    }

    fclose(archivo);
}

void encontrarCadenaMasLarga() {
    FILE *archivo;
    archivo = fopen("CADENAS.TXT", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    char cadena[100];
    char cadenaMasLarga[100] = "";
    while (fgets(cadena, sizeof(cadena), archivo) != NULL) {
        if (strlen(cadena) > strlen(cadenaMasLarga)) {
            strcpy(cadenaMasLarga, cadena);
        }
    }

    fclose(archivo);

    printf("La cadena más larga es:\n%s", cadenaMasLarga);
}

int main() {
    leerCadenasYGrabarArchivo();
    encontrarCadenaMasLarga();
    return 0;
}


