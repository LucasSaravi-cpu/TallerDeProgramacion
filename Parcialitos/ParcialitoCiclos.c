/*Escribir un programa en c que permite al usuario ingresar la altura de un triangulo y un caracter . La altura debera ser un valor impar entre 3 y 10 .y debera ser validada  Luego
y utilizando ciclos , mostrar por pantalla el triangulo dibujandolo con el cracter ingresado comenzando con 1 e incrementado de a 2

      *
     ***
    *****
   *******
  **********
*/


#include <stdio.h>

int main() {
    int altura;
    char caracter;


    do {
        printf("Ingrese la altura del triangulo (impar entre 3 y 10): ");
        scanf("%d", &altura);
    } while (altura < 3 || altura > 10 || altura % 2 == 0);

    fflush(stdin);
    printf("Ingrese el carácter para dibujar el triangulo: ");
    scanf(" %c", &caracter);


    int espacios = altura / 2;
    for (int i = 1; i <= altura; i += 2) {

        for (int j = 0; j < espacios; j++) {
            printf(" ");
        }

        for (int k = 0; k < i; k++) {
            printf("%c", caracter);
        }

        printf("\n");
        espacios--;
    }

    return 0;
}
