#include <stdio.h>

void contarVocales(int cantidad, int *totalVocales, int *contadorA, int *contadorE, int *contadorI, int *contadorO, int *contadorU) {
    *totalVocales = 0;
    *contadorA = 0;
    *contadorE = 0;
    *contadorI = 0;
    *contadorO = 0;
    *contadorU = 0;

    for (int i = 1; i <= cantidad; i++) {
        char caracter;
        printf("Ingrese el caracter %d: ", i);
        scanf(" %c", &caracter); // Espacio en blanco antes de %c para evitar problemas de búfer.
        fflush(stdin);

        switch (caracter) {
            case 'a':
            case 'A':
                (*totalVocales)++;
                (*contadorA)++;
                break;
            case 'e':
            case 'E':
                (*totalVocales)++;
                (*contadorE)++;
                break;
            case 'i':
            case 'I':
                (*totalVocales)++;
                (*contadorI)++;
                break;
            case 'o':
            case 'O':
                (*totalVocales)++;
                (*contadorO)++;
                break;
            case 'u':
            case 'U':
                (*totalVocales)++;
                (*contadorU)++;
                break;
        }
    }
}

int main() {
    int cantidad, totalVocales, contadorA, contadorE, contadorI, contadorO, contadorU;

    printf("Ingrese la cantidad de caracteres: ");
    scanf("%d", &cantidad);
    fflush(stdin);

    contarVocales(cantidad, &totalVocales, &contadorA, &contadorE, &contadorI, &contadorO, &contadorU);

    if (totalVocales > 0) {
        if (contadorA > contadorE && contadorA > contadorI && contadorA > contadorO && contadorA > contadorU) {
            printf("La 'A' es la vocal que más veces apareció.\n");
        }
    }

    printf("La cantidad de vocales ingresadas es %d.\n", totalVocales);

    return 0;
}




