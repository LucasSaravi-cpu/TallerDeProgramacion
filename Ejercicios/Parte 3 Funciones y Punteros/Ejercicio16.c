/*
Ej. 16 � Escribe una funci�n llamada esPalindromo que tome una cadena como par�metro y
determine si es un pal�ndroma (se lee igual de izquierda a derecha que de derecha a izquierda).
Utiliza esta funci�n para verificar si una palabra ingresada por el usuario lo es o no.   */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Funci�n para verificar si una cadena es un pal�ndromo
bool esPalindromo(const char *cadena) {
    int izquierda = 0;
    int derecha = strlen(cadena) - 1;

    while (izquierda < derecha) {
        if (cadena[izquierda] != cadena[derecha]) {
            return false;
        }
        izquierda++;
        derecha--;
    }

    return true;
}

int main() {
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    if (esPalindromo(palabra)) {
        printf("%s es un pal�ndromo.\n", palabra);
    } else {
        printf("%s no es un pal�ndromo.\n", palabra);
    }

    return 0;
}
