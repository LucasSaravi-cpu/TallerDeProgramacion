#include <stdio.h>
//Usando estructuras de decisión independientes:
void ordenarTresLetras(char *letra1, char *letra2, char *letra3) {
    if (*letra1 > *letra2) {
        char temp = *letra1;
        *letra1 = *letra2;
        *letra2 = temp;
    }
    if (*letra2 > *letra3) {
        char temp = *letra2;
        *letra2 = *letra3;
        *letra3 = temp;
    }
    if (*letra1 > *letra2) {
        char temp = *letra1;
        *letra1 = *letra2;
        *letra2 = temp;
    }
}

int main() {
    char letra1, letra2, letra3;

    printf("Ingrese la primera letra: ");
    scanf(" %c", &letra1);
    printf("Ingrese la segunda letra: ");
    scanf(" %c", &letra2);
    printf("Ingrese la tercera letra: ");
    scanf(" %c", &letra3);

    ordenarTresLetras(&letra1, &letra2, &letra3);

    printf("Letras ordenadas alfabéticamente: %c %c %c\n", letra1, letra2, letra3);

    return 0;
}

//Usando estructuras de decisión anidadas:
/*#include <stdio.h>

void ordenarTresLetras(char *letra1, char *letra2, char *letra3) {
    if (*letra1 > *letra2) {
        char temp = *letra1;
        *letra1 = *letra2;
        *letra2 = temp;
    }
    if (*letra2 > *letra3) {
        char temp = *letra2;
        *letra2 = *letra3;
        *letra3 = temp;
    }
    if (*letra1 > *letra2) {
        char temp = *letra1;
        *letra1 = *letra2;
        *letra2 = temp;
    }
}

int main() {
    char letra1, letra2, letra3;

    printf("Ingrese la primera letra: ");
    scanf(" %c", &letra1);
    printf("Ingrese la segunda letra: ");
    scanf(" %c", &letra2);
    printf("Ingrese la tercera letra: ");
    scanf(" %c", &letra3);

    ordenarTresLetras(&letra1, &letra2, &letra3);

    printf("Letras ordenadas alfabéticamente: %c %c %c\n", letra1, letra2, letra3);

    return 0;
}*/

