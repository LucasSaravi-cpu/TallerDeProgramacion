#include <stdio.h>
#include <math.h>

int main() {
    int num;
    int digito;


    printf("Introduce un numero entero: ");
    scanf("%d", &num);


    if (num == 0) {
        digito = 1;
    } else {
        if (num < 0) {
            num = -num;
        }


        digito = (int)log10(num) + 1;
    }

    // Mostrar el número de dígitos
    printf("El numero tiene %d digitos \n", digito);

    return 0;
}
