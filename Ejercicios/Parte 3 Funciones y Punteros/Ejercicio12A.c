#include <stdio.h>

float calcularPromedioPositivos(int cantidad) {
    int contador = 0;
    float sumador = 0;

    for (int i = 1; i <= cantidad; i++) {
        int numero;
        printf("Ingrese el número %d: ", i);
        scanf("%d", &numero);

        if (numero > 0) {
            contador++;
            sumador += numero;
        }
    }

    if (contador > 0) {
        return sumador / contador;
    } else {
        return 0.0;
    }
}

int main() {
    int cantidad;
    float promedio;

    printf("Ingrese la cantidad de números: ");
    scanf("%d", &cantidad);

    promedio = calcularPromedioPositivos(cantidad);

    printf("El promedio de los números positivos es %.2f\n", promedio);

    return 0;
}






