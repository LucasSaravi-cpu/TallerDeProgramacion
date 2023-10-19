/*  Para N personas se registró el peso y la altura, calcular sus índices de masa corporal y
determinar e informar el porcentaje de los que tienen un índice normal (18 <= ICM <= 21).
Implementar y utilizar función IMC correctamente parametrizada que devuelva verdadero si el índice
es normal y falso en caso contrario   */


#include <stdio.h>
#include <stdbool.h>

// Función para calcular el IMC y determinar si es normal
bool calcularIMC(double peso, double altura) {
    double imc = peso / (altura * altura);
    return (imc >= 18.0 && imc <= 21.0);
}

int main() {
    int n;
    printf("Ingrese el número de personas: ");
    scanf("%d", &n);

    int personasNormales = 0;

    for (int i = 1; i <= n; i++) {
        double peso, altura;
        printf("Ingrese el peso (en kg) de la persona %d: ", i);
        scanf("%lf", &peso);
        printf("Ingrese la altura (en metros) de la persona %d: ", i);
        scanf("%lf", &altura);

        if (calcularIMC(peso, altura)) {
            personasNormales++;
        }
    }

    double porcentajeNormal = (double)personasNormales / n * 100.0;

    printf("El porcentaje de personas con un IMC normal es: %.2lf%%\n", porcentajeNormal);

    return 0;
}
