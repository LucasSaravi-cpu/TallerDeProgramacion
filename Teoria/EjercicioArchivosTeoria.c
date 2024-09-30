/*
Dado un archivo de texto TEMPSEPT.TXT que contiene en una cada l�nea: DIA, TMAX y TMIN (las
temperaturas m�ximas y m�nimas de septiembre de este a�o indicando a que d�a corresponden), se
pide: hallar y mostrar la cantidad de d�as en los que la amplitud t�rmica no super� los X grados (leer X
previamente). */


#include <stdio.h>

int main() {
    FILE *file;
    int dia, count = 0;
    float tmax, tmin, x, amplitud;


    printf("Ingrese el valor de X (amplitud t�rmica m�xima permitida): ");
    scanf("%f", &x);

    file = fopen("TEMPSEPT.TXT", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }


    while (fscanf(file, "%d %f %f", &dia, &tmax, &tmin) == 3) {
        amplitud = tmax - tmin;


        if (amplitud <= x) {
            count++;
        }
    }


    fclose(file);


    printf("Cantidad de d�as con amplitud t�rmica no superior a %.2f grados: %d\n", x, count);

    return 0;
}
