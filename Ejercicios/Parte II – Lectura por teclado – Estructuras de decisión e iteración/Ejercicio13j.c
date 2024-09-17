/*Leer a, b y c coeficientes de una ecuación cuadrática (ax2+bx+c). Determinar si tiene raíces
reales o imaginarias (b2-4ac < 0).  */



#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discriminante;

    // Solicitar al usuario que ingrese los coeficientes a, b y c
    printf("Ingrese el coeficiente 'a': ");
    scanf("%lf", &a);
    printf("Ingrese el coeficiente 'b': ");
    scanf("%lf", &b);
    printf("Ingrese el coeficiente 'c': ");
    scanf("%lf", &c);

    // Calcular el discriminante
    discriminante = b * b - 4 * a * c;

    // Verificar si el discriminante es negativo
    if (discriminante < 0) {
        printf("La ecuación cuadrática tiene raíces imaginarias.\n");
    } else if (discriminante == 0) {
        printf("La ecuación cuadrática tiene una raíz real (raíz doble).\n");
    } else {
        printf("La ecuación cuadrática tiene dos raíces reales.\n");
    }

    return 0;
}
