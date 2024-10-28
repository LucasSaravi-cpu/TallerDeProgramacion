/* Escribir una función llamada esPalindromo que tome una cadena como parámetro y determine si es un
palíndroma (se lee igual de izquierda a derecha que de derecha a izquierda). Utiliza esta función para
verificar si una palabra ingresada por el usuario lo es o no.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esPalindromo( char* );

int main() {
    char palabra[100];
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    if (esPalindromo(palabra)) {
        printf("La palabra es un palindromo\n");
    } else {
        printf("La palabra no es un palindromo\n");
    }

    return 0;
}

int esPalindromo( char* str) {
    int izquierda = 0, derecha = strlen(str) - 1;
    while (izquierda < derecha) {
        if (tolower(str[izquierda]) != tolower(str[derecha])) {
            return 0;
        }
        izquierda++;
        derecha--;
    }
    return 1;
}
