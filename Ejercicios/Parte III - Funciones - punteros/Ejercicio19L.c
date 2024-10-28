/*. Resolver nuevamente los incisos h, j y l del ejercicio 13 desarrollando funciones.*/
#include <stdio.h>
void clasificarEdad(int , int *, int *, int *, int *);
void categoriaMasNumerosa(int , int , int , int);

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
       
    }else{

    for (int i = 0; i < n; i++) {
        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &edad);
        clasificarEdad(edad, &cantidadNino, &cantidadAdolescente, &cantidadJoven, &cantidadAdulto);
    }

    printf("\nCantidad de niños: %d\n", cantidadNino);
    printf("Cantidad de adolescentes: %d\n", cantidadAdolescente);
    printf("Cantidad de adultos jóvenes: %d\n", cantidadJoven);
    printf("Cantidad de adultos: %d\n", cantidadAdulto);

    categoriaMasNumerosa(cantidadNino, cantidadAdolescente, cantidadJoven, cantidadAdulto);
    }
    return 0;
}


void clasificarEdad(int edad, int *cantidadNino, int *cantidadAdolescente, int *cantidadJoven, int *cantidadAdulto) {
    if (edad <= 11) {
        printf("La persona es un niño.\n");
        (*cantidadNino)++;
    } else if (edad <= 17) {
        printf("La persona es un adolescente.\n");
        (*cantidadAdolescente)++;
    } else if (edad <= 25) {
        printf("La persona es un adulto joven.\n");
        (*cantidadJoven)++;
    } else {
        printf("La persona es un adulto.\n");
        (*cantidadAdulto)++;
    }
}


void categoriaMasNumerosa(int cantidadNino, int cantidadAdolescente, int cantidadJoven, int cantidadAdulto) {
    if (cantidadNino >= cantidadAdolescente && cantidadNino >= cantidadJoven && cantidadNino >= cantidadAdulto) {
        printf("La categoría más numerosa es 'niño'.\n");
    } else if (cantidadAdolescente >= cantidadJoven && cantidadAdolescente >= cantidadAdulto) {
        printf("La categoría más numerosa es 'adolescente'.\n");
    } else if (cantidadJoven >= cantidadAdulto) {
        printf("La categoría más numerosa es 'adulto joven'.\n");
    } else {
        printf("La categoría más numerosa es 'adulto'.\n");
    }
}
