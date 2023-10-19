/* Desarrollar un programa que convierta una temperatura de grados Celsius a Fahrenheit o
viceversa, seg�n la elecci�n del usuario. [NOTA: La conversi�n se realiza mediante la siguiente f�rmula:
�F = �C x 1.8 + 32]    */

#include <stdio.h>

int main() {
    int opcion;
    double temperatura, resultado;

    printf("Conversor de Temperatura\n");
    printf("1. Convertir de Celsius a Fahrenheit\n");
    printf("2. Convertir de Fahrenheit a Celsius\n");
    printf("Seleccione una opci�n (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese la temperatura en grados Celsius: ");
        scanf("%lf", &temperatura);
        resultado = (temperatura * 1.8) + 32;
        printf("%.2lf grados Celsius son equivalentes a %.2lf grados Fahrenheit.\n", temperatura, resultado);
    } else if (opcion == 2) {
        printf("Ingrese la temperatura en grados Fahrenheit: ");
        scanf("%lf", &temperatura);
        resultado = (temperatura - 32) / 1.8;
        printf("%.2lf grados Fahrenheit son equivalentes a %.2lf grados Celsius.\n", temperatura, resultado);
    } else {
        printf("Opci�n no v�lida. Seleccione 1 o 2.\n");
    }

    return 0;
}
