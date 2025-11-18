/*El sector taller de una empresa de transporte tiene la informacion del año 2024 de mantenimiento
y reparacion realizadas sobre sus unidades en un archivo de texto  llamado TALLER2024.TXT
Cada linea del archivo contiene los siguientes elementos : unidad ( entero entre 1 y 80 ) , mes (entero  entre 1 y 12 )
importe ( costo del mantenimiento o reparacion ) , tipo ( 'M' mantenimiento y 'R'  reparacion )


El archivo no esta ordenado bajo ningun criterio .  Una misma unidad podria tener mas de un mantenimiento y/o reparacion
en el mismo mes.

Se pide desarrollar en c subprogramas correctamente parametrizados para resolver .

a) A partir del archivo , generar una matriz costos de 80x12 donde cada elemento represente el costo total de mantenimiento
y reparaciones para la unidad y mes correspondientes.

b) A partir de la matriz generada en a) crear el archivo binario MAYORCOSTO.DAT solo para las unidades cuyo costo total anual supere
$500.000. Cada elemento del archivo sera un registro con los siguientes campos : Unidad , costoAnual
( El archivo debe generar ordenado por unidad de forma descendente )

c) Este inciso debe resolverse con una funcion int . A partir de la matriz armada en a) Hallar y devoler el mes de mayor gasto total para la empresa considerando
solo los camiones ( son los que tienen un numero entre 12 y 30 )

d) Escribir el main.c con la invocacion a los subprogramas desarrolladoss .

*/

#include <stdio.h>
#include <stdlib.h> // Uso de NULL
#define MaxFila 80
#define MaxColumna 12

typedef struct {

int unidad;
float CostoAnual;

} rgmayorcosto;



int MesMayorGasto( float Matriz[][MaxColumna]);
void GeneraMatrizCosto( float Matriz[][MaxColumna]);
void GeneraArchivoBinario( float Matriz[][MaxColumna]);

int main()
{
    float matriz[MaxFila][MaxColumna] = {0}; // Inicializo la matriz en 0

    GeneraMatrizCosto(matriz);
    GeneraArhivoBinario(matriz);

    printf("El mes con mayor gasto total es %d \n",MesMayorGasto(matriz));


    return 0;
}




void GeneraMatrizCosto( float Matriz[][MaxColumna]){

FILE*ArchivoTaller = fopen ("TALLER2024.TXT","r"); // solo lectura
int unidad;
int mes;
float importe;
char tipo;


if (ArchivoTaller ==NULL) {

    printf("El archivo no se pudo abrir");

}else {

    while (fscanf(ArchivoTaller,"%d %d %f %c",&unidad,&mes,&importe, &tipo ) ==4 )
          Matriz [unidad-1][mes-1]+=importe; // Ya que la matriz empieza en 0 y no existe un mes 0 o unidad 0

}

fclose(ArchivoTaller);

}


void GeneraArhivoBinario (float Matriz[][MaxColumna]){

FILE*ArchivoMayorCosto= fopen ("MAYORCOSTO.DAT","wb");
float CostoTotal;
rgmayorcosto vec[MaxFila];
int cant = 0;

if (ArchivoMayorCosto ==NULL) {

    printf("El archivo no se pudo crear ");

}else {
   
    for(int i=0; i<MaxFila; i++){
        CostoTotal = 0;

        for(int j=0; j<MaxColumna; j++){
            CostoTotal += Matriz[i][j];
        }

        if(CostoTotal > 500000){
            vec[cant].unidad = i + 1;    
            vec[cant].CostoAnual = CostoTotal;
            cant++;
        }
    }

    // Ordenar DESCENDENTE por unidad (burbuja simple)
    for(int i=0; i<cant-1; i++){
        for(int j=i+1; j<cant; j++){
            if(vec[i].unidad < vec[j].unidad){
                rgmayorcosto aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    // Grabar al archivo ya ordenado
    for(int i=0; i<cant; i++){
        fwrite(&vec[i], sizeof(rgmayorcosto), 1, ArchivoMayorCosto);
    }

}

fclose(ArchivoMayorCosto);

}


int MesMayorGasto (float Matriz [][MaxColumna]){

int mesmax ;
float max=0;
float mesCostoTotal;


for ( int mes =0 ; mes<MaxColumna ; mes++){

    mesCostoTotal= 0 ;

    for ( int unidad =0 ; unidad <MaxFila; unidad++ ){

        if ( unidad >=11 && unidad<=29 )
           mesCostoTotal += Matriz[unidad][mes];

    }

    if (max < mesCostoTotal){
       mesmax = mes;
       max= mesCostoTotal;

    }

}

return mesmax+1;

}



