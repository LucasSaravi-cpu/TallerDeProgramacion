/*. Resolver nuevamente los incisos h, j y l del ejercicio 13 desarrollando funciones.*/

#include <stdio.h>
#include <math.h>
void analizarRaices(float , float , float ) ;

int main() {
    float a, b, c;


    printf("Ingrese el coeficiente 'a': ");
    scanf("%f", &a);
    printf("Ingrese el coeficiente 'b': ");
    scanf("%f", &b);
    printf("Ingrese el coeficiente 'c': ");
    scanf("%f", &c);


    analizarRaices(a, b, c);

    return 0;
}


void analizarRaices(float a, float b, float c) {
    float discriminante = b * b - 4 * a * c;

    if (discriminante < 0) {
        printf("La ecuación cuadrática tiene raíces imaginarias.\n");
    } else if (discriminante == 0) {
        printf("La ecuación cuadrática tiene una raíz real (raíz doble).\n");
    } else {
        printf("La ecuación cuadrática tiene dos raíces reales.\n");
    }
}
