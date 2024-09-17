/*
a. Mostrar el valor medio de dos enteros leídos previamente
*/
#include <stdio.h>

int main() {

int num1,num2;
float resultado;

printf("Ingresar el primer numero \n");
scanf("%d",&num1);
printf("Ingresar el segundo numero \n");
scanf("%d",&num2);


// Convertir al menos uno de los operandos a float para evitar la división entera
resultado = (num1+num2)/2.0;

printf("Resultado %5f",resultado);

return 0;
}
