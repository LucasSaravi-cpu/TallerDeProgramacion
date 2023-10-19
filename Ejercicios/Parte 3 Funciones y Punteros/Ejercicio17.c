/*
Ej. 17 – Escribe una función llamada esCapicua que tome un entero como parámetro y determine
si es o no capicúa. */
#include <stdio.h>
#include <stdbool.h>

// Función para verificar si un número es capicúa
bool esCapicua(int numero) {
    int numeroReverso = 0;
    int numeroOriginal = numero;

    while (numero > 0) {
        int digito = numero % 10;
        numeroReverso = numeroReverso * 10 + digito;
        numero /= 10;
    }

    return numeroReverso == numeroOriginal;
}

int main() {
    int numero;

    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    if (esCapicua(numero)) {
        printf("%d es un número capicúa.\n", numero);
    } else {
        printf("%d no es un número capicúa.\n", numero);
    }

    return 0;
}



