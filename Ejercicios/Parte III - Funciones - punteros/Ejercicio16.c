/*Desarrollar un programa con al menos una función que convierta una temperatura de grados Celsius a
Fahrenheit o viceversa, según la elección del usuario. [NOTA: La conversión se realiza mediante la siguiente
fórmula: ºF = ºC x 1.8 + 32.*/


#include <stdio.h>


float celsiusAFahrenheit(float ) ;

float fahrenheitACelsius(float );

int main() {
    int opcion;
    float temperatura, resultado;

    printf("Conversor de Temperatura\n");
    printf("1. Convertir de Celsius a Fahrenheit\n");
    printf("2. Convertir de Fahrenheit a Celsius\n");
    printf("Seleccione una opcion (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese la temperatura en grados Celsius: ");
        scanf("%f", &temperatura);
        resultado = celsiusAFahrenheit(temperatura);
        printf("%.2f grados Celsius son equivalentes a %.2f grados Fahrenheit.\n", temperatura, resultado);
    } else if (opcion == 2) {
        printf("Ingrese la temperatura en grados Fahrenheit: ");
        scanf("%f", &temperatura);
        resultado = fahrenheitACelsius(temperatura);
        printf("%.2f grados Fahrenheit son equivalentes a %.2f grados Celsius.\n", temperatura, resultado);
    } else {
        printf("Opción no valida. Seleccione 1 o 2.\n");
    }

    return 0;
}


float celsiusAFahrenheit(float c) {
    return (c * 1.8) + 32;
}


float fahrenheitACelsius(float f) {
    return (f - 32) / 1.8;
}
