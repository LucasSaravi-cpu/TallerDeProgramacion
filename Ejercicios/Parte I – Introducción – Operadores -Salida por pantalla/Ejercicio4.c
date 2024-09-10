/*
Sean las siguientes declaraciones de variables e inicializaciones. Completar el cuadro con la salida en cada
caso, agregar salto de línea, tabulaciones o espacios que considere para que la visualización de los resultados
sea legible

int A = 34, B =1234, C = -3;
char ch1 =’A’;
float F = 22.47;

printf("A=%d", A);
printf("A=%5d",A);
printf("A=%4d",A);
printf("A=%-5d",A);
printf("A=%-4d",A);
printf("A=%05d",A);
printf("A=%-05d",A);
printf("A=%+d”, A);
printf("B=%3d",B);

printf("F=%f",F);
printf("F=%7.2f",F);
printf("F=%07.2f",F);
printf("F=%-7.2f",F);
printf("F=%7.1f",F);
printf("%c",ch1);
printf("%3c",ch1);
printf("C=%-3c",ch1);
printf("%s","ELEFANTE");




*/

#include<stdio.h>
int main() {

int A=34,B=1234 , C=-3;
float F=22.47;
char ch1='A';

printf("A=%d \n", A);
printf("A=%5d \n",A);
printf("A=%4d\n",A);
printf("A=%-5d\n",A);
printf("A=%-4d\n",A);
printf("A=%05d\n",A);
printf("A=%-05d\n",A);
printf("A=%+d\n", A);
printf("B=%3d\n",B);
printf("F=%f\n",F);
printf("F=%7.2f\n",F);
printf("F=%07.2f\n",F);
printf("F=%-7.2f\n",F);
printf("F=%7.1f\n",F);
printf("%c\n",ch1);
printf("%3c\n",ch1);
printf("C=%-3c\n",ch1);
printf("%s\n","ELEFANTE");



return 0 ;


}
