/*Ingresar tres letras y escribirlas ordenadas alfab�ticamente. Resolver este problema de dos
formas diferentes. (Utilizando estructuras de decisi�n independientes y estructuras de
decisi�n anidadas). */

//Usando estructuras de decisi�n independientes:

#include <stdio.h>

int main() {
    char letra1, letra2, letra3;

    printf("Ingrese la primera letra: ");
    scanf(" %c", &letra1);
    printf("Ingrese la segunda letra: ");
    scanf(" %c", &letra2);
    printf("Ingrese la tercera letra: ");
    scanf(" %c", &letra3);

    // Estructuras de decisi�n independientes para ordenar alfab�ticamente
    if (letra1 <= letra2 && letra1 <= letra3) {
        printf("%c ", letra1);
        if (letra2 <= letra3) {
            printf("%c %c\n", letra2, letra3);
        } else {
            printf("%c %c\n", letra3, letra2);
        }
    } else if (letra2 <= letra1 && letra2 <= letra3) {
        printf("%c ", letra2);
        if (letra1 <= letra3) {
            printf("%c %c\n", letra1, letra3);
        } else {
            printf("%c %c\n", letra3, letra1);
        }
    } else {
        printf("%c ", letra3);
        if (letra1 <= letra2) {
            printf("%c %c\n", letra1, letra2);
        } else {
            printf("%c %c\n", letra2, letra1);
        }
    }

    return 0;
}

//Usando estructuras de decisi�n anidadas:

/*#include <stdio.h>

int main() {
    char letra1, letra2, letra3;

    printf("Ingrese la primera letra: ");
    scanf(" %c", &letra1);
    printf("Ingrese la segunda letra: ");
    scanf(" %c", &letra2);
    printf("Ingrese la tercera letra: ");
    scanf(" %c", &letra3);

    // Estructuras de decisi�n anidadas para ordenar alfab�ticamente
    if (letra1 <= letra2) {
        if (letra2 <= letra3) {
            printf("%c %c %c\n", letra1, letra2, letra3);
        } else if (letra1 <= letra3) {
            printf("%c %c %c\n", letra1, letra3, letra2);
        } else {
            printf("%c %c %c\n", letra3, letra1, letra2);
        }
    } else {
        if (letra1 <= letra3) {
            printf("%c %c %c\n", letra2, letra1, letra3);
        } else if (letra2 <= letra3) {
            printf("%c %c %c\n", letra2, letra3, letra1);
        } else {
            printf("%c %c %c\n", letra3, letra2, letra1);
        }
    }

    return 0;
}*/
