/*Desarrollar un programa correctamente modularizado que solicite por teclado N y los siguientes datos de N
alumnos: Nombre (cadena de 30), NumeroMatricula (entero), Carrera (cadena de 30) y almacene los datos
de los alumnos en un arreglo de structs. Luego, muestre por pantalla a partir de los datos ingresados (con
un alumno por línea) solo aquellos que estudian Ingeniería en Informática.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char nombre[30];
    int matricula;
    char carrera[30];
} Alumno;

int main() {
    int n;
    Alumno alumnos[MAX_N];


    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);


    fflush(stdin);


    for (int i = 0; i < n; i++) {
        printf("Alumno %d:\n", i+1);
        printf("Nombre: ");
        getchar();
        gets(alumnos[i].nombre);
        printf("Matricula: ");
        scanf("%d", &alumnos[i].matricula);
        fflush(stdin);
        printf("Carrera: ");
        scanf("%30[^\n]",alumnos[i].carrera);
    }


    printf("Alumnos de Ingenieria en Informtaica:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(alumnos[i].carrera, "ingenieria en informatica") == 0) {
            printf(" Nombre:%s Matricula: %d, Carrera: %s " , alumnos[i].nombre, alumnos[i].matricula, alumnos[i].carrera);

        }
    }

    return 0;
}
