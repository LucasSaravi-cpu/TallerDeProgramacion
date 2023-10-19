/*   Leer de un archivo de texto FRAC.TXT que contiene dos fracciones por l�nea: n1, d1, n2, d2.
Para cada l�nea obtener y mostrar la suma de ambas fracciones, como n�mero real con tres
decimales. Si el resultado es un n�mero entero, mostrarlo como tal.
Ejemplos:  2 3 1 2  resultado 1.166   ; 4 3 2 3  resultado  2    ; 5 12 1 18 resultado 0.472  */



#include <stdio.h>

void sumarFraccionesYMostrarResultado() {
    FILE *archivo;
    archivo = fopen("FRAC.TXT", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    double n1, d1, n2, d2, suma;

    while (fscanf(archivo, "%lf %lf %lf %lf", &n1, &d1, &n2, &d2) != EOF) {
        suma = (n1 / d1) + (n2 / d2);
        if (suma == (int)suma) {
            printf("%.0lf\n", suma);
        } else {
            printf("%.3lf\n", suma);
        }
    }

    fclose(archivo);
}

int main() {
    sumarFraccionesYMostrarResultado();
    return 0;
}

