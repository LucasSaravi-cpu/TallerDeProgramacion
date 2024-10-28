/* Escribir una función que permita insertar una nueva persona en el arreglo ya ordenado*/

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

void ordenarPersonasPorNombre(Persona personas[], int n);
void insertarPersonaOrdenada(Persona personas[], int *n, Persona nuevaPersona);

int main() {
    Persona personas[MAX_PERSONAS];
    int n;

     FILE *archivo = fopen("Ejercicio34.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");

    }else{

    n = 0;
    fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura) ;
    while (!feof(archivo)) {
        n++;
        fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura) ;
    }


    fclose(archivo);

    }


     for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Sexo: %c, Edad: %d, Altura: %.2f\n",
               personas[i].nombre, personas[i].sexo, personas[i].edad, personas[i].altura);

  }
    ordenarPersonasPorNombre(personas,n);

    Persona nuevaPersona = {"Loana", 'F', 28, 1.70};

    insertarPersonaOrdenada(personas, &n, nuevaPersona);

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Sexo: %c, Edad: %d, Altura: %.2f\n",
               personas[i].nombre, personas[i].sexo, personas[i].edad, personas[i].altura);
    }


    return 0;
}



void ordenarPersonasPorNombre(Persona personas[], int n) {
    Persona temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(personas[j].nombre, personas[j + 1].nombre) > 0) {
                temp = personas[j];
                personas[j] = personas[j + 1];
                personas[j + 1] = temp;
            }
        }
    }
}

void insertarPersonaOrdenada(Persona personas[], int *n, Persona nuevaPersona) {
    if (*n >= MAX_PERSONAS) {
        printf("No se puede insertar más personas. El arreglo está lleno.\n");
        return;
    }

    int i = *n - 1;


    while (i >= 0 && strcmp(personas[i].nombre, nuevaPersona.nombre) > 0) {
        personas[i + 1] = personas[i];
        i--;
    }

    personas[i + 1] = nuevaPersona;


    (*n)++;
}



