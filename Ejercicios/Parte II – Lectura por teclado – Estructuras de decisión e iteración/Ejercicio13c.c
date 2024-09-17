/*
c. Mostrar la tabla de multiplicar de un número dado por el usuario

*/
#include <stdio.h>
#define n 11

int main() {

int numero;
float resultado;


printf("Ingresar el numero a multiplicar  \n");
scanf("%d",&numero);

for (int i =1 ; i<n ; i++){

    printf("%d x %d = %f \n",numero,i, resultado=numero*i);

}


return 0;
}
