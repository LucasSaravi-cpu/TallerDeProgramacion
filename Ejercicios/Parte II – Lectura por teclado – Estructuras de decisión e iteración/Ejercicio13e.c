/*Ingresar N números enteros y calcular y mostrar el promedio de los positivos. */
#include<stdio.h>

int main() {

  int numero,n,contador=0;
  float promedio,sumador=0;

  printf("Ingrese la cantida de numeros");

  scanf("%d",&n);

  for (int i=1 ;i <=n;i++){

        printf("Ingrese el numero");
        scanf("%d",&numero);

    if (numero>0){
        contador++;
        sumador=sumador+numero;
        }
  }

    if (contador!=0) {
    promedio=sumador/contador ;
    printf("el promedio de los numeros positivo es %f",promedio);

    }
    else{
        printf("No se encontraron numeros positivos ");
    }

return 0 ;
}
