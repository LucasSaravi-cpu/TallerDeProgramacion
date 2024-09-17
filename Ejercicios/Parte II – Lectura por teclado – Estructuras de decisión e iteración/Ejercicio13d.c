/*Mostrar los primeros 10 números de la secuencia de Fibonacc*/
#include <stdio.h>

int main() {
    int n = 10;

   int a = 0, b = 1, c;

    printf("Los primeros %d numeros de la secuencia de Fibonacci son:\n", n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", a);
        } else if (i == 1) {
            printf(", %d", b);
        } else {
            c = a + b;
            printf(", %d", c);
            a = b;
            b = c;
        }
    }

    printf("\n");

    return 0;
}
