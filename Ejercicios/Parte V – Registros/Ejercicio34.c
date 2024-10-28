/* Modificar el ejercicio anterior para que los datos sean tomados desde un archivo de texto.
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
    FILE *archivo;
    Alumno alumnos[MAX_N];
    int n = 0;


    archivo = fopen("ejercicio34.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
     
    }else{
     fscanf(archivo, "%29[^\n]\n%d\n%29[^\n]\n", alumnos[n].nombre, &alumnos[n].matricula, alumnos[n].carrera);
    while (!feof(archivo) ) {
        n++;
        fscanf(archivo, "%29[^\n]\n%d\n%29[^\n]\n", alumnos[n].nombre, &alumnos[n].matricula, alumnos[n].carrera);
    }


    fclose(archivo);
    }

    printf("Alumnos de Ingenieria en Informatica:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(alumnos[i].carrera, "ingenieria en informatica") == 0) {
            printf("Nombre: %s, Matricula: %d, Carrera: %s\n", alumnos[i].nombre, alumnos[i].matricula, alumnos[i].carrera);
        }
    }

    return 0;
}
