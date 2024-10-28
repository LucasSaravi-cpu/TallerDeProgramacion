/*   Leer de un archivo de texto FRAC.TXT que contiene dos fracciones por línea: numerador 1,
denominador 1, numerador 2, denominador 2. Para cada línea obtener y mostrar la suma de ambas
fracciones, como número real con tres decimales. Si el resultado es un número entero, mostrarlo
como tal.
Ejemplos: 2 3 1 2 resultado 1.166 ; 4 3 2 3 resultado 2 ; 5 12 1 18 resultado 0.472  */



#include <stdio.h>
#include <stdlib.h>

void sumarFraccionesYMostrarResultado();

int main() {
    sumarFraccionesYMostrarResultado();
    return 0;
}

void sumarFraccionesYMostrarResultado() {
    FILE *archivo;
    archivo = fopen("FRAC.TXT", "r");
     float n1, d1, n2, d2, suma;

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");

    }else{



    while (fscanf(archivo, "%f %f %f %f", &n1, &d1, &n2, &d2) ==4) {
        suma = (n1 / d1) + (n2 / d2);
        if (suma == (int)suma) {
            printf("%.0lf\n", suma);
        } else {
            printf("%.3lf\n", suma);
        }
    }

    fclose(archivo);
    }
}

