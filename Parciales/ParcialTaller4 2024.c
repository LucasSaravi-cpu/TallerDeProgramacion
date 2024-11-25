/* Una administracion de consorcios ha almacenado un archivo de texto empresas.txt , la informacion correspondiente a las expensas y pagos realizados por aca departamento durante un año ( el archivo
no esta ordenado por ningun criterio ) . Cada linea en el archivo contiene los sigueitnes campos

Departamento : un numero entre 1 y 50
mes : un numero entre 1 y 12 ;
importe un valor real correspondiente al monto de expensas o pago
Tipo es un caracter : E indica que el importe representa el valor de la expensa del mes
                      P indica que el importe representa un pago realizado

(La suma de pagos en un mes para un departamento nunca es superior al valor de la expensa del mes )

Como ejemplo se muestran las siguientes lineas con sus significados :

3 4 60000 E Significa qe el departamento 3 en el mes de abril el valor de la expensa es de 60000
5 4 80000 E Significa qe el departamento 5 en el mes de abril el valor de la expensa es de 80000
2 4 60000 E Significa qe el departamento 2 en el mes de abril el valor de la expensa es de 60000
2 4 40000 P Significa qe el departamento 2 en el mes de abril realizo un pago de 40000
2 4 20000 P Significa qe el departamento 2 en el mes de abril realizo un pago de 20000
5 4 55000 P Significa qe el departamento 5 en el mes de abril realizo un pago de 55000

Para este ejemplo en abril , el departamento 2 no toene deudas , el 3 debe 60000 y el 5 debe 25000

Desarrollar subprogramas para

a) A partir de un archivo de texto , armar un matriz ue contenga la situacion ( deuda en $ ) de cada departamento en cada mes

tomando como base la estructura general en el iniso a)

b) generar un archivo binario deudores.dat en el que se guarde para los departamentos que adeudan expesas la deuda total de cada uno , esto es , en cada registro : Departamento y deuda acumulada ( >0)

c) informar el mes en que se adeuda mas dineroa la administracion  . Para este punto se debe desarrollar una funcion float correctamente parammetrizada que devuelva el total adeudado al consorcio para un mes dado

Escribir el main.c con la informacio na los subprogramas desarrollados ,declaraciones , definiciones , inicializaciones y mensajes que sean necesarios , no desarrollar la carga del archivo Empresas.txt


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEPARTAMENTOS 50
#define MESES 12


typedef struct {
    int departamento;
    float deuda_total;
} registro;


void generarmatriz( float matriz[][mes]);
void generabinario ( float matriz [][mes]);


int main() {

float matriz [departamento][mes] ;

generarmatriz (matriz);
generabinario (matriz);

printf ( " El mes con mayor deuda es : %d \n " ,  mesMayorDeuda(matriz) ) ;

return 0;


    }


//Iniciso a

void generarmatriz (float matriz[][mes]){

float importe;
int departamento , mes ;
char tipo ;

file *archivo =fopen ("empresas.txt","r");

if ( archivo == null )
    printf("El archivo no se encontro " );
else
{
    while ( fscanf( archivo , "%d %d %f %c", &departamento , &mes , & importe ,&tipo ) ==4) {

    if ( tipo 'E'){
        matriz[mes-1][departamento-1] += importe;
    else
    {
        matriz [mes-1][departamento-1]-= importe;

    }
    }


  }

  close(archivo);

}
}


//inciso b

void generabinario ( float matriz [][mes]) {


file *archivobinario =fopen ("deudores.dat","wb");

registro r;

if (archivobinario == null)

    printf ( " El archivo no se puede crear")

else {

      for (int i = 0; i < DEPARTAMENTOS; i++) {
        float deudaAcumulada = 0;
        for (int j = 0; j < MESES; j++) {
            if (matriz[i][j] > 0) {
                deudaAcumulada += matriz[i][j];
            }
        }

        if (deudaAcumulada > 0) {
             r.departameto = i+1;
             r.deuda_total = deudaAcumulada;
            fwrite(&r, sizeof(registro), 1, archivobinario);
        }

   close(archivobinario) ;
}


//inciso c

// Función para calcular la deuda total de un mes
float calcularDeudaMes(float matriz[DEPARTAMENTOS][MES], int mes) {
    float deudaTotal = 0;
    for (int i = 0; i < DEPARTAMENTOS; i++) {
        deudaTotal += matriz[i][mes];
    }
    return deudaTotal;
}

// Función para encontrar el mes con mayor deuda
int mesMayorDeuda(float matriz[DEPARTAMENTOS][MES]) {
    float maxDeuda = 0;
    int mesMayor = 0;

    for (int j = 0; j < MESES; j++) {
        float deudaMes = calcularDeudaMes(matriz, j);
        if (deudaMes > maxDeuda) {
            maxDeuda = deudaMes;
            mesMayor = j;
        }
    }

    return mesMayor;
}


}

/*
Ejercicio 2

#include <stdio.h>

void CargarDatosVector ( int V[], int *  N) {   //Ingresa la dimencion y los datos
int i ;
printf( " ingrese la cantidad de datos : ");
scanf("%d", N ) ;
for ( i = 0 ; i<  *N ; i++){

    printf ( " ingeese la posicion %d del vector ",  i+1 )
    scanf("%d", & v[i]);


}




void muestraVector ( int v[] ,int N){
int i ;

printf (" [%d " , V [0])); // Muestra el primer elemento de V

for( i=0 , i<N ; i++ )
    printf ( " , %d ", V[i]);

    printf ("]");


}


void InvertirVector ( int V[],int N){

int i , aux ;

for ( i=0 ; i< N/2; i++){
 aux = V[i];
    V[i] = V[N - 1 - i];
    V[N - 1 - i] = aux;

}


}


int main (){

int main() {
int N ,maximo;
int V[50];
CargarDatosVector ( v , &N);
InvertirteVector (V, N);
printf ( " El vector invertido es ");
MuestraVector (V,N));
return 0;



}
*/

