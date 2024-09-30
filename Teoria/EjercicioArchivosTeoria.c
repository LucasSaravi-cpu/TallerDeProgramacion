/*
Dado un archivo de texto TEMPSEPT.TXT que contiene en una cada línea: DIA, TMAX y TMIN (las
temperaturas máximas y mínimas de septiembre de este año indicando a que día corresponden), se
pide: hallar y mostrar la cantidad de días en los que la amplitud térmica no superó los X grados (leer X
previamente). */


#include <stdio.h>

int main() {
    FILE *file;
    int dia, count = 0;
    float tmax, tmin, x, amplitud;


    printf("Ingrese el valor de X (amplitud térmica máxima permitida): ");
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


    printf("Cantidad de días con amplitud térmica no superior a %.2f grados: %d\n", x, count);

    return 0;
}
