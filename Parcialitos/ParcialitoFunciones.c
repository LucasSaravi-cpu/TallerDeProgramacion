/*Escribir un programa que permita al usuario ingresar los altos y largos de un rectangulo . Ambos valores deben ser reales
positivos y mayores a 5 ( validar) Luego mostrar el valor de la diagonal que debe hallarse mediante una funcion float ) . usar sqrt() math.h*/
#include <stdio.h>
#include <math.h>

float calcularDiagonal(float , float );
int main() {
    float alto, largo;


    do {
        printf("Ingrese el alto del rectángulo (debe ser un número real positivo mayor a 5): ");
        scanf("%f", &alto);
        if (alto <= 5) {
            printf("El alto debe ser mayor a 5. Intente nuevamente.\n");
        }
    } while (alto <= 5);


    do {
        printf("Ingrese el largo del rectángulo (debe ser un número real positivo mayor a 5): ");
        scanf("%f", &largo);
        if (largo <= 5) {
            printf("El largo debe ser mayor a 5. Intente nuevamente.\n");
        }
    } while (largo <= 5);


    float diagonal = calcularDiagonal(alto, largo);
    printf("La diagonal del rectángulo es: %.2f\n", diagonal);

    return 0;
}


float calcularDiagonal(float alto, float largo) {
    return sqrt((alto * alto) + (largo * largo));
}
