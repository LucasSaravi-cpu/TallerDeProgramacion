/*
a) Leer 10 cadenas de caracteres por teclado (pueden tener espacios) y grabarlas en un archivo
de texto CADENAS.TXT (una por línea). Desde el archivo creado, mostrar la cadena más larga. . */


#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para usar el NULL

int main() {
    FILE *archivo;
    char cadena[100];
    char cadenaMasLarga[100];

    strcpy(cadenaMasLarga, "");


    archivo = fopen("CADENAS.TXT", "w"); // "w" solo escritura

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");

    }else{

    for (int i = 0; i < 10; i++) {
        printf("Ingrese una cadena: ");
        scanf("%s", cadena);
        fprintf(archivo, "%s\n", cadena);
    }

     fclose(archivo); // cerramos antes de leer
    }




    archivo = fopen("CADENAS.TXT", "r"); // "r" solo lectura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");

    }else{


    fscanf(archivo,"%s",cadena);

     while ( !feof(archivo)) {
         if (strlen(cadena) > strlen(cadenaMasLarga)) {
             strcpy(cadenaMasLarga, cadena);  }
         fscanf(archivo,"%s",cadena);
     }

      fclose(archivo);
     }







    printf("\nLa cadena más larga es: %s\n", cadenaMasLarga);

    return 0;
}
