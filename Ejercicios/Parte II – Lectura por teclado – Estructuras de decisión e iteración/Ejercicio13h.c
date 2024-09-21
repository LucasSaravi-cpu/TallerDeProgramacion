/*Leer 3 valores correspondientes un ángulo en grados, minutos y segundos y obtener y
mostrar el valor equivalente en radianes*/


#include <stdio.h>

int main(){
float grados,min,seg,resultado;
printf("Ingrese los grados, minutos y segundos de un angulo, asi lo pasamos a radianes \n");
scanf(" %f %f %f",&grados,&min,&seg);
resultado = (grados + min/60.0 + seg/3600.0)/180.0;
printf("En radianes ese angulo es %2.4f pi",resultado);
 return 0;
}
