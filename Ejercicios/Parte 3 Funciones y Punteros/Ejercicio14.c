/*  Escribir un programa que funcione como una calculadora que realice operaciones de suma,
resta, multiplicaci�n y divisi�n. Adem�s, permitir elevar un n�mero a una potencia entera ingresada
por el usuario utilizando funciones para cada operaci�n.  */

#include <stdio.h>
#include <math.h>

// Funci�n para realizar la suma
double suma(double a, double b) {
    return a + b;
}

// Funci�n para realizar la resta
double resta(double a, double b) {
    return a - b;
}

// Funci�n para realizar la multiplicaci�n
double multiplicacion(double a, double b) {
    return a * b;
}

// Funci�n para realizar la divisi�n
double division(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Divisi�n por cero no permitida.\n");
        return 0.0;
    }
}

// Funci�n para elevar un n�mero a una potencia entera
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
    printf("3. Multiplicaci�n\n");
    printf("4. Divisi�n\n");
    printf("5. Potenciaci�n\n");
    printf("Seleccione una operaci�n (1-5): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese el primer n�mero: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo n�mero: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", suma(num1, num2));
            break;
        case 2:
            printf("Ingrese el primer n�mero: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo n�mero: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", resta(num1, num2));
            break;
        case 3:
            printf("Ingrese el primer n�mero: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo n�mero: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Ingrese el primer n�mero: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo n�mero: ");
            scanf("%lf", &num2);
            printf("Resultado: %.2lf\n", division(num1, num2));
            break;
        case 5:
            printf("Ingrese el n�mero base: ");
            scanf("%lf", &num1);
            printf("Ingrese el exponente (entero): ");
            scanf("%d", &exponente);
            printf("Resultado: %.2lf\n", potencia(num1, exponente));
            break;
        default:
            printf("Opci�n no v�lida.\n");
            break;
    }

    return 0;
}
