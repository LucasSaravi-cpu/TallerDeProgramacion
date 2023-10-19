#include <stdio.h>
#include <math.h>

void verificarRaices(double a, double b, double c) {
    double discriminante = b * b - 4 * a * c;

    if (discriminante < 0) {
        printf("La ecuaci�n cuadr�tica tiene ra�ces imaginarias.\n");
    } else if (discriminante == 0) {
        printf("La ecuaci�n cuadr�tica tiene una ra�z real (ra�z doble).\n");
    } else {
        printf("La ecuaci�n cuadr�tica tiene dos ra�ces reales.\n");
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





