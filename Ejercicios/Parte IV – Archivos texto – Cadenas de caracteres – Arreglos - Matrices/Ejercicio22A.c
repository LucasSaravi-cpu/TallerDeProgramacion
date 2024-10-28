/*
a) Leer 10 cadenas de caracteres por teclado (pueden tener espacios) y grabarlas en un archivo
de texto CADENAS.TXT (una por línea). Desde el archivo creado, mostrar la cadena más larga. . */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

    FILE *archivo;
    archivo = fopen("CADENAS.TXT", "w+");

    char cadena[100];
    char cadenaMasLarga[100] ;


    strcpy(cadenaMasLarga,"");
    for (int i = 0; i < 10; i++) {
        printf("Ingrese una cadena: ");
        scanf("%s", cadena);
        fprintf(archivo, "%s\n", cadena);
    }

 rewind(archivo);


   if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");

    }else{

  fscanf(archivo,"%s",cadena);
     while ( !feof(archivo)) {
        if (strlen(cadena) > strlen(cadenaMasLarga)) {
            strcpy(cadenaMasLarga, cadena);
        }

         fscanf(archivo,"%s",cadena);
     }

       fclose(archivo);
    }




 printf("La cadena más larga es: %s\n", cadenaMasLarga);

return 0;
}
