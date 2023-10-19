/*
Ej. 17 � Escribe una funci�n llamada esCapicua que tome un entero como par�metro y determine
si es o no capic�a. */
#include <stdio.h>
#include <stdbool.h>

// Funci�n para verificar si un n�mero es capic�a
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

    printf("Ingrese un n�mero entero: ");
    scanf("%d", &numero);

    if (esCapicua(numero)) {
        printf("%d es un n�mero capic�a.\n", numero);
    } else {
        printf("%d no es un n�mero capic�a.\n", numero);
    }

    return 0;
}



