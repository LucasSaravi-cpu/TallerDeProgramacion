#include <stdio.h>
#include <math.h>

void verificarRaices(double a, double b, double c) {
    double discriminante = b * b - 4 * a * c;

    if (discriminante < 0) {
        printf("La ecuación cuadrática tiene raíces imaginarias.\n");
    } else if (discriminante == 0) {
        printf("La ecuación cuadrática tiene una raíz real (raíz doble).\n");
    } else {
        printf("La ecuación cuadrática tiene dos raíces reales.\n");
    }
}

int main() {
    double a, b, c;

    printf("Ingrese el coeficiente 'a': ");
    scanf("%lf", &a);
    printf("Ingrese el coeficiente 'b': ");
    scanf("%lf", &b);
    printf("Ingrese el coeficiente 'c': ");
    scanf("%lf", &c);

    verificarRaices(a, b, c);

    return 0;
}





