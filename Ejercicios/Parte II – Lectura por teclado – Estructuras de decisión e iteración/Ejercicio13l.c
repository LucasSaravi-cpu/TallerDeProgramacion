#include <stdio.h>

int main() {
    int edad, n;
    int cantidadNino = 0;
    int cantidadAdolescente = 0;
    int cantidadJoven = 0;
    int cantidadAdulto = 0;


    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &n);


    if (n <= 0) {
        printf("La cantidad de personas debe ser mayor que 0.\n");
        return 1;
    }


    for (int i = 0; i < n; i++) {
        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &edad);

        if (edad <= 11) {
            printf("La persona es un ni�o.\n");
            cantidadNino++;
        } else if (edad <= 17) {
            printf("La persona es un adolescente.\n");
            cantidadAdolescente++;
        } else if (edad <= 25) {
            printf("La persona es un adulto joven.\n");
            cantidadJoven++;
        } else {
            printf("La persona es un adulto.\n");
            cantidadAdulto++;
        }
    }


    printf("\nCantidad de ni�os: %d\n", cantidadNino);
    printf("Cantidad de adolescentes: %d\n", cantidadAdolescente);
    printf("Cantidad de adultos j�venes: %d\n", cantidadJoven);
    printf("Cantidad de adultos: %d\n", cantidadAdulto);


    if (cantidadNino >= cantidadAdolescente && cantidadNino >= cantidadJoven && cantidadNino >= cantidadAdulto) {
        printf("La categor�a m�s numerosa es 'ni�o'.\n");
    } else if (cantidadAdolescente >= cantidadJoven && cantidadAdolescente >= cantidadAdulto) {
        printf("La categor�a m�s numerosa es 'adolescente'.\n");
    } else if (cantidadJoven >= cantidadAdulto) {
        printf("La categor�a m�s numerosa es 'adulto joven'.\n");
    } else {
        printf("La categor�a m�s numerosa es 'adulto'.\n");
    }

    return 0;
}

