/*Corte de Control de Primer Nivel – Matriz y Matriz de Strings

Una biblioteca posee un archivo de texto con información correspondiente a los préstamos de libros realizados por distintos socios.

Cada registro del archivo contiene los siguientes datos:

Número de socio (valores entre 1 y 50, puede repetirse).
Código de libro (valores entre 1000 y 1099).
Cantidad de días del préstamo (entero positivo).
Género del libro (string).
Multa generada (número real).

Ejemplo del archivo:

1 1000 5 Terror 100.5
1 1002 3 Romance 0
1 1005 8 Ciencia 50
2 1001 10 Historia 200
2 1003 2 Terror 0
Se solicita
A)

Desarrollar una única función que realice las siguientes tareas:

1) Generar un archivo binario

El archivo binario deberá contener registros de tipo struct con la siguiente información:

Número de socio.
Total de días de préstamo.
Promedio de multas generadas.

El archivo binario deberá generarse únicamente para aquellos socios que hayan solicitado más de 5 libros.

2) Construir una matriz ML de 50x100

Cada posición de la matriz deberá contener:

'P' si el socio solicitó ese libro.
'N' si no lo solicitó.
3) Construir una matriz de strings llamada generoLibro

La matriz deberá almacenar el género correspondiente a cada libro.

Declaración sugerida:

char generoLibro[100][20];
Luego, utilizando las matrices creadas:
B)

Desarrollar una función que retorne un valor entero y reciba como parámetros:

La matriz ML
La matriz generoLibro
Un número de socio ingresado por teclado

La función deberá indicar si dicho socio posee todos los libros del género "Terror".

C)

Desarrollar una única función que determine:

El libro más solicitado entre los socios.
El libro menos solicitado entre los socios.
D)

Realizar el main completo, incluyendo:

Declaración de matrices.
Llamado a funciones.
Ingreso de datos por teclado.
Visualización de resultados.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOCIOS 50
#define MAX_LIBROS 100

typedef struct{
    int socio;
    int totalDias;
    float promedioMulta;
} regBin;

void procesarArchivo(char ML[][MAX_LIBROS], char generoLibro[][20]);
int tieneTodosTerror(char ML[][MAX_LIBROS], char generoLibro[][20], int socio);
void libroMaxMin(char ML[][MAX_LIBROS], int *libroMax, int *libroMin);

int main(){

    char ML[MAX_SOCIOS][MAX_LIBROS];
    char generoLibro[MAX_LIBROS][20];

    int socio;
    int libroMax, libroMin;

    procesarArchivo(ML, generoLibro);

    printf("Ingrese numero de socio: ");
    scanf("%d", &socio);

    if(tieneTodosTerror(ML, generoLibro, socio)){
        printf("El socio tiene todos los libros de Terror\n");
    } else {
        printf("El socio NO tiene todos los libros de Terror\n");
    }

    libroMaxMin(ML, &libroMax, &libroMin);

    printf("Libro mas pedido: %d\n", libroMax);
    printf("Libro menos pedido: %d\n", libroMin);

    return 0;
}

void procesarArchivo(char ML[][MAX_LIBROS], char generoLibro[][20]){

    FILE *txt = fopen("final2.txt", "r");
    FILE *bin = fopen("socios.dat", "wb");

    int socio, codLibro, dias;
    float multa;
    char genero[20];

    regBin reg;



    for(int i=0; i<MAX_SOCIOS; i++){
        for(int j=0; j<MAX_LIBROS; j++){
            ML[i][j] = 'N';
        }
    }


    for(int i=0; i<MAX_LIBROS; i++){
        strcpy(generoLibro[i], "");
    }

    if(txt == NULL || bin == NULL){

        printf("Error al abrir archivos\n");

    } else {

        fscanf(txt, "%d %d %d %s %f",&socio,&codLibro,&dias,genero,&multa);

        while(!feof(txt)){

            int socioActual = socio;

            int totalDias = 0;
            float sumaMultas = 0;

            int cantLibros = 0;

            while(!feof(txt) && socio == socioActual){

                int i = socio - 1;
                int j = codLibro - 1000;

                ML[i][j] = 'P';

                strcpy(generoLibro[j], genero);

                totalDias += dias;
                sumaMultas += multa;

                cantLibros++;

                fscanf(txt, "%d %d %d %s %f",&socio,&codLibro,&dias,genero,&multa);
            }

            if(cantLibros > 5){


                reg.socio = socioActual;
                reg.totalDias = totalDias;
                reg.promedioMulta = sumaMultas / cantLibros;

                fwrite(&reg, sizeof(regBin), 1, bin);
            }
        }

        fclose(txt);
        fclose(bin);
    }
}

int tieneTodosTerror(char ML[][MAX_LIBROS], char generoLibro[][20], int socio){

    int resultado = 1;

    if(socio < 1 || socio > MAX_SOCIOS){

        resultado = 0;

    } else {

        int i = socio - 1;

        for(int j=0; j<MAX_LIBROS && resultado == 1; j++){

            if(strcmp(generoLibro[j], "Terror") == 0){

                if(ML[i][j] != 'P'){
                    resultado = 0;
                }
            }
        }
    }

    return resultado;
}

void libroMaxMin(char ML[][MAX_LIBROS], int *libroMax, int *libroMin){

    int max = -1;
    int min = 9999;

    for(int j=0; j<MAX_LIBROS; j++){

        int contador = 0;

        for(int i=0; i<MAX_SOCIOS; i++){

            if(ML[i][j] == 'P'){
                contador++;
            }
        }

        if(contador > max){

            max = contador;
            *libroMax = j + 1000;
        }

        if(contador < min && contador > 0){

            min = contador;
            *libroMin = j + 1000;
        }
    }
}
