#include <stdio.h>
#include <ctype.h> // Para la funci�n isupper

int main() {
    int N;


    printf("Ingrese el numero de caracteres a leer: ");
    scanf("%d", &N);

    // Limpiar el buffer de entrada para evitar problemas con fgets
    while (getchar() != '\n');

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


    printf("Cantidad de letras may�sculas: %d\n", conteoMayusculas);

    return 0;
}
