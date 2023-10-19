#include <stdio.h>
#include <string.h>

void contarCaracteres(char *cadena) {
    printf("La cadena de caracteres ingresada es: %s\n", cadena);
    printf("La cantidad de caracteres en la cadena es: %lu\n", strlen(cadena));
}

int main() {
    char caracteres[100];
    printf("Ingrese los caracteres que desee, para terminar presione Enter: \n");
    gets(caracteres); // lee la cadena de caracteres
    contarCaracteres(caracteres); // llamada a la función
    return 0;
}









