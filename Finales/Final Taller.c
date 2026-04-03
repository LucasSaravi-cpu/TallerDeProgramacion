/*
Final taller de programacion 2025 (Corte de control de primer nivel ) 

Una distribuidora posee un archivo de texto con información correspondiente a las ventas de productos realizadas por distintos distribuidores.
Cada registro del archivo contiene los siguientes datos:

Número de distribuidor (valores entre 1 y 80, puede repetirse).

Código de producto (valores entre 100 y 299).

Stock (entero positivo).

Precio (número real).

A partir de este archivo de texto se solicita realizar las siguientes tareas: 

A) Hacer una sola funcion que genere un archivo binario cuyos registros sean de tipo struct y contengan la siguiente información:

Número de distribuidor.

Cantidad de unidades

Promedio del precio de los productos.

El archivo binario deberá generarse únicamente para aquellos distribuidores que posean más de 10 productos

Ademas Construir una matriz MS de 80x200 donde cada posición de la matriz deberá contener:

'S' si el distribuidor posee ese producto.

'N' si no lo posee.

Luego desde la matriz creada MS :

B) Desarrollar una función que retorne un valor entero, que reciba como parámetro un número de distribuidor ingresado por teclado e indique si dicho distribuidor posee todos los productos de cotillón.

Se considera que los productos de cotillón son aquellos que cumplen con las siguientes condiciones:

Código de producto entre 100 y 200 inclusive.

Código de producto par.

C) Desarrollar una única función que determine:

El producto  que más se repite entre los distribuidores.( max)

El producto de menos se repite entre los distribuidores. ( min )

D) Realizar el main completo
*/




#include <stdio.h>
#include <stdlib.h>

#define MAX_DIST 80
#define MAX_PROD 200

typedef struct {
    int distribuidor;
    int cantidadUnidades;
    float promedioPrecio;
} regBin;


void procesarArchivo(char MS[][MAX_PROD]);
void productosMaxMin(char MS[][MAX_PROD], int *prodMax, int *prodMin);
int tieneCotillonCompleto(char MS[][MAX_PROD], int distribuidor);


int main(){

    char MS[MAX_DIST][MAX_PROD];

    int distribuidor;
    int prodMax, prodMin;

    procesarArchivo(MS);

    printf("Ingrese distribuidor: ");
    scanf("%d", &distribuidor);

    if(tieneCotillonCompleto(MS, distribuidor)){
        printf("Tiene todos los productos de cotillon\n");
    } else {
        printf("No tiene todos los productos de cotillon\n");
    }

    productosMaxMin(MS, &prodMax, &prodMin);

    printf("Producto mas distribuido: %d\n", prodMax);
    printf("Producto menos distribuido: %d\n", prodMin);

    return 0;
}

void procesarArchivo(char MS[][MAX_PROD]){

    FILE *txt = fopen("ventas.txt", "r");
    FILE *bin = fopen("salida.dat", "wb");

    int dist, cod, stock;
    float precio;

    // Inicializar matriz
    for(int i=0;i<MAX_DIST;i++)
        for(int j=0;j<MAX_PROD;j++)
            MS[i][j] = 'N';

    if(txt == NULL || bin == NULL){
        printf("Error al abrir archivos\n");

    } else {


    fscanf(txt, "%d %d %d %f", &dist, &cod, &stock, &precio);

    while(!feof(txt)){

        int distActual = dist;

        int totalUnidades = 0;
        float sumaPrecios = 0;
        int cantProductos = 0;


        while(!feof(txt) && dist == distActual){



            int i = dist - 1;
            int j = cod - 100;

            MS[i][j] = 'S';

            totalUnidades += stock;
            sumaPrecios += precio;
            cantProductos++;


            fscanf(txt, "%d %d %d %f", &dist, &cod, &stock, &precio);

        }


        if(cantProductos > 10){

            regBin reg;

            reg.distribuidor = distActual;
            reg.cantidadUnidades = totalUnidades;
            reg.promedioPrecio = sumaPrecios / cantProductos;

            fwrite(&reg, sizeof(regBin), 1, bin);
        }
    }

    fclose(txt);
    fclose(bin);

    }
}




void productosMaxMin(char MS[][MAX_PROD], int *prodMax, int *prodMin){

    int max = -1;
    int min = 9999;

    for(int j=0; j<MAX_PROD; j++){

        int contador = 0;

        for(int i=0; i<MAX_DIST; i++){
            if(MS[i][j] == 'S'){
                contador++;
            }
        }

        if(contador > max){
            max = contador;
            *prodMax = j + 100;
        }

        if(contador < min && contador > 0){
            min = contador;
            *prodMin = j + 100;
        }
    }
}

int tieneCotillonCompleto(char MS[][MAX_PROD], int distribuidor){

    int resultado = 1; 

    if(distribuidor < 1 || distribuidor > MAX_DIST){
        resultado = 0;
    } else {

        int i = distribuidor - 1;

        for(int cod = 100; cod <= 200 && resultado == 1; cod++){

            if(cod % 2 == 0){

                int j = cod - 100;

                if(MS[i][j] != 'S'){
                    resultado = 0;
                }
            }
        }
    }

    return resultado;
}



