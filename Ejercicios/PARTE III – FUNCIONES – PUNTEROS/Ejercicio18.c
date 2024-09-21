/*Escribir una función llamada esCapicua que tome un entero como parámetro y determine si es o no capicúa*/

#include <stdio.h>

int esCapicua(int) ;

int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (esCapicua(numero)) {
        printf("El numero es capicua\n");
    } else {
        printf("El numero no es capicua\n");
    }

    return 0;
}

int esCapicua(int num) {
    int original = num, invertido = 0;

    while (num > 0) {
        invertido = invertido * 10 + (num % 10);
        num /= 10;
    }
    return original == invertido;
}
