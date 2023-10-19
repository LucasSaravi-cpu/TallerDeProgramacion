/*  Determinar si una persona es ni�o, adolescente, adulto joven o adulto, seg�n la edad
ingresada por el usuario. Ni�o se es hasta los 11, adolescente hasta los 17 y adulto joven
hasta los 25. [Nota: todas las edades dadas se incluyen en su categor�a]. */



#include <stdio.h>

int main() {
    int edad;


    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    if (edad <= 11) {
        printf("La persona es un ni�o.\n");
    } else if (edad <= 17) {
        printf("La persona es un adolescente.\n");
    } else if (edad <= 25) {
        printf("La persona es un adulto joven.\n");
    } else {
        printf("La persona es un adulto.\n");
    }

    return 0;
}



