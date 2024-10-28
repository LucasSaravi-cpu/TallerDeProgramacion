/*Definir una estructura llamada Persona que tenga los campos nombre, sexo, edad y altura. Definir un arreglo
de estructuras Persona. Escribir un programa que lea los datos de n personas desde un archivo de texto (una
persona por línea) y los almacene en el arreglo. Para luego informar:
a. La altura promedio de las personas.
b. La edad promedio de las personas.
c. Porcentaje de personas con edad mayor al promedio
d. Cantidad de personas en un rango de alturas leído por teclado.
e. Diferencia de altura promedio entre mujeres y varones*/

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

float calcularAlturaPromedio(Persona personas[], int n);
float calcularEdadPromedio(Persona personas[], int n);
float calcularPorcentajeEdadMayorPromedio(Persona personas[], int n, float edadPromedio);
int contarPersonasEnRangoAltura(Persona personas[], int n, float minAltura, float maxAltura);
float diferenciaAlturaPromedioEntreSexos(Persona personas[], int n);

int main() {
    Persona personas[MAX_PERSONAS];
    int n;

     FILE *archivo = fopen("Ejercicio35.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    
    }else{

    n = 0;
    fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura);
    while (!feof(archivo)) {
        n++;
        fscanf(archivo, "%s %c %d %f", personas[n].nombre, &personas[n].sexo, &personas[n].edad, &personas[n].altura);
    }

    fclose(archivo);
    }

    float alturaPromedio = calcularAlturaPromedio(personas, n);
    float edadPromedio = calcularEdadPromedio(personas, n);
    float porcentajeMayorEdad = calcularPorcentajeEdadMayorPromedio(personas, n, edadPromedio);

    printf("Altura promedio: %.2f\n", alturaPromedio);
    printf("Edad promedio: %.2f\n", edadPromedio);
    printf("Porcentaje de personas con edad mayor al promedio: %.2f%%\n", porcentajeMayorEdad);


    float minAltura, maxAltura;
    printf("Ingrese el rango de alturas (min y max): ");
    scanf("%f %f", &minAltura, &maxAltura);

    int personasEnRango = contarPersonasEnRangoAltura(personas, n, minAltura, maxAltura);
    printf("Cantidad de personas en el rango de alturas: %d\n", personasEnRango);


    float diferenciaAltura = diferenciaAlturaPromedioEntreSexos(personas, n);
    printf("Diferencia de altura promedio entre mujeres y varones: %.2f\n", diferenciaAltura);

    return 0;
}



float calcularAlturaPromedio(Persona personas[], int n) {
    float sumaAlturas = 0;
    for (int i = 0; i < n; i++) {
        sumaAlturas += personas[i].altura;
    }
    return sumaAlturas / n;
}

float calcularEdadPromedio(Persona personas[], int n) {
    float sumaEdades = 0;
    for (int i = 0; i < n; i++) {
        sumaEdades += personas[i].edad;
    }
    return sumaEdades / n;
}

float calcularPorcentajeEdadMayorPromedio(Persona personas[], int n, float edadPromedio) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (personas[i].edad > edadPromedio) {
            contador++;
        }
    }
    return ((float)contador / n) * 100;
}

int contarPersonasEnRangoAltura(Persona personas[], int n, float minAltura, float maxAltura) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (personas[i].altura >= minAltura && personas[i].altura <= maxAltura) {
            contador++;
        }
    }
    return contador;
}

float diferenciaAlturaPromedioEntreSexos(Persona personas[], int n) {
    float sumaAlturaMujeres = 0, sumaAlturaHombres = 0;
    int contadorMujeres = 0, contadorHombres = 0;

    for (int i = 0; i < n; i++) {
        if (personas[i].sexo == 'F') {
            sumaAlturaMujeres += personas[i].altura;
            contadorMujeres++;
        } else if (personas[i].sexo == 'M') {
            sumaAlturaHombres += personas[i].altura;
            contadorHombres++;
        }
    }

  float promedioAlturaMujeres;
if (contadorMujeres > 0) {
    promedioAlturaMujeres = sumaAlturaMujeres / contadorMujeres;
} else {
    promedioAlturaMujeres = 0;
}

float promedioAlturaHombres;
if (contadorHombres > 0) {
    promedioAlturaHombres = sumaAlturaHombres / contadorHombres;
} else {
    promedioAlturaHombres = 0;
}

    return promedioAlturaHombres - promedioAlturaMujeres;
}
