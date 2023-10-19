/*  Escribir un programa que funcione como una calculadora que realice operaciones de suma,
resta, multiplicación y división. Además, permitir elevar un número a una potencia entera ingresada
por el usuario utilizando funciones para cada operación.  */

#include <stdio.h>
#include <math.h>

// Función para realizar la suma
double suma(double a, double b) {
    return a + b;
}

// Función para realizar la resta
double resta(double a, double b) {
    return a - b;
}

// Función para realizar la multiplicación
double multiplicacion(double a, double b) {
    return a * b;
}

// Función para realizar la división
double division(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero no permitida.\n");
        return 0.0;
    }
}

// Función para elevar un número a una potencia entera
double potencia(double base, int exponente) {
    return pow(base, exponente);
}

int main() {
    int opcion;
    double num1, num2;
    int exponente;

    printf("Calculadora:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Potenciación\n");
    printf("Seleccione una operación (1-5): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese el primer número: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo número: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", suma(num1, num2));
            break;
        case 2:
            printf("Ingrese el primer número: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo número: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", resta(num1, num2));
            break;
        case 3:
            printf("Ingrese el primer número: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo número: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Ingrese el primer número: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo número: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", division(num1, num2));
            break;
        case 5:
            printf("Ingrese el número base: ");
            scanf("%lf", &num1);
            printf("Ingrese el exponente (entero): ");
            scanf("%d", &exponente);
            printf("Resultado: %.2lf\n", potencia(num1, exponente));
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
