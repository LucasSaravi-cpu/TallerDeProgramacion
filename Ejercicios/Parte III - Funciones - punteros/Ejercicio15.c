/*Escribir un programa que funcione como una calculadora que realice operaciones de suma, resta,
multiplicación y división. Además, permitir elevar un número a una potencia entera ingresada por el usuario
utilizando funciones para cada operación.*/


#include <stdio.h>
#include <math.h>

float suma(float , float );
float resta(float , float );
float multiplicacion(float , float );
float division(float , float ) ;
float potencia(float , int );


int main() {
    int opcion;
    float num1, num2;
    int exponente;

    printf("Calculadora:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Potenciacion\n");
    printf("Seleccione una operacion (1-5): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            printf("Resultado: %.2f\n", suma(num1, num2));
            break;
        case 2:
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            printf("Resultado: %.2f\n", resta(num1, num2));
            break;
        case 3:
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            printf("Resultado: %.2f\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            printf("Resultado: %.2f\n", division(num1, num2));
            break;
        case 5:
            printf("Ingrese el numero base: ");
            scanf("%f", &num1);
            printf("Ingrese el exponente (entero): ");
            scanf("%d", &exponente);
            printf("Resultado: %.2f\n", potencia(num1, exponente));
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }

    return 0;
}


float suma(float a, float b) {
    return a + b;
}


float resta(float a, float b) {
    return a - b;
}


float multiplicacion(float a, float b) {
    return a * b;
}


float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division por cero no permitida.\n");
        return 0.0f;
    }
}


float potencia(float base, int exponente) {
    return powf(base, exponente);
}
