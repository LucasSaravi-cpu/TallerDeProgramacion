/*LEER N CARATERES Y HALLAR Y ESCRIBIR LA CANTIDAD DE LETRAS MAYUSCUCLAS INGRESADAS*/
#include <stdio.h>
#include <ctype.h> // Para la función isupper

int main() {
    int N;


    printf("Ingrese el numero de caracteres a leer: ");
    scanf("%d", &N);

   fflush(stdio);

    char caracteres[N];


    printf("Ingrese %d caracteres:\n", N);
    for (int i = 0; i < N; i++) {
        caracteres[i] = getchar();
    }


    int conteoMayusculas = 0;
    for (int i = 0; i < N; i++) {
        if (isupper(caracteres[i])) {
            conteoMayusculas++;
        }
    }


    printf("Cantidad de letras mayúsculas: %d\n", conteoMayusculas);

    return 0;
}
