/*. Resolver nuevamente los incisos h, j y l del ejercicio 13 desarrollando funciones.*/

#include<stdio.h>
#define PI 3.14159265358979323846
float radianes(float , float, float );


float main() {

    float grados, minutos,segundos;
    float resultado;
    printf("Ingrese los grados ");
    scanf("%f",&grados);
    printf("Ingrese los minutos ");
    scanf("%f",&minutos);
    printf("Ingrese los segundos ");
    scanf("%f",&segundos);
     resultado=radianes(grados,minutos,segundos);
    printf("radianes %f",resultado);
    return 0;
    }


float radianes(float grados,float minutos,float segundos){

float gra,graSeg,graMin;

graMin=minutos/60;
graSeg=segundos/3600;

gra=grados+graMin+graSeg;

return  gra * PI / 180;
}
