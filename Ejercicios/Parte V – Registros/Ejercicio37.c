/* Escribir una función que permita modificar la altura y el peso de una persona cuyo nombre se ingresa por
teclado, si es que se encuentra en el arreglo, sino informarlo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONAS 100


typedef struct {
    char nombre[50];
    char sexo;
    int edad;
    float altura;
} Persona;


void modificarAlturaYPeso(Persona personas[], int n);

int main() {
    Persona personas[MAX_PERSONAS];
    int n;

     FILE *archivo = fopen("Ejercicio34.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
       return 1;
    }

    n = 0;
    while (fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura) != EOF) {
        n++;
    }

     for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Sexo: %c, Edad: %d, Altura: %.2f\n",
               personas[i].nombre, personas[i].sexo, personas[i].edad, personas[i].altura);
    }

    fclose(archivo);

    modificarAlturaYPeso(personas,n);

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Sexo: %c, Edad: %d, Altura: %.2f\n",
               personas[i].nombre, personas[i].sexo, personas[i].edad, personas[i].altura);
    }


    return 0;
}




void modificarAlturaYPeso(Persona personas[], int n) {
    char nombreBuscado[50];
    int encontrado = 0;
    int i = 0;

    printf("Ingrese el nombre de la persona que desea modificar: ");
    scanf("%s", nombreBuscado);

    while (i < n && !encontrado) {
        if (strcmp(personas[i].nombre, nombreBuscado) == 0) {

            printf("Persona encontrada: %s\n", personas[i].nombre);
            printf("Ingrese la nueva altura: ");
            scanf("%f", &personas[i].altura);
            encontrado = 1;
        } else {
            i++;
        }
    }

    if (!encontrado) {
        printf("Persona no encontrada.\n");
    }
}


