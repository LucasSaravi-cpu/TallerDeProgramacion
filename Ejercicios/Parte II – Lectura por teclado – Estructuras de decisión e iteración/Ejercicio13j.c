/*Leer a, b y c coeficientes de una ecuaci�n cuadr�tica (ax2+bx+c). Determinar si tiene ra�ces
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
        printf("La ecuaci�n cuadr�tica tiene ra�ces imaginarias.\n");
    } else if (discriminante == 0) {
        printf("La ecuaci�n cuadr�tica tiene una ra�z real (ra�z doble).\n");
    } else {
        printf("La ecuaci�n cuadr�tica tiene dos ra�ces reales.\n");
    }

    return 0;
}
