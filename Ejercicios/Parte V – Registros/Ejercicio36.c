/*Ordene alfabéticamente el arreglo de Personas (utilizando el método que quiera), y luego muéstrelo.*/

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

int main() {
    Persona personas[MAX_PERSONAS];
    int n;

     FILE *archivo = fopen("Ejercicio34.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
      
    }else{

    n = 0;
    fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura);
    while (!feof(archivo)) {
        n++;
        fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura)
    }

    fclose(archivo);
    }
  ordenarPersonasPorNombre(personas,n);

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Sexo: %c, Edad: %d, Altura: %.2f\n",
               personas[i].nombre, personas[i].sexo, personas[i].edad, personas[i].altura);
    }


    return 0;
}

// Función para ordenar personas por nombre utilizando el método de burbuja
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


