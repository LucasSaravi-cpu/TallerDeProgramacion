/*Una biblioteca tiene un archivo binario PRESTAMOS.DAT que representa los ejemplares prestados a sus 
socios, con el siguiente formato de registro.
 typedef struct { 
 short int idSocio; //representa el número de socio con rango 1 a 100. 
 short int idLibro; // representa el identificador de libro con rango 1 a 200
 char idEjemplar[8] //Cadena que representa el código del ejemplar.
 char fechaVencimiento [9]; //cadena con formato aaaammdd, es la fecha límite para devolver
 } rgPrestamos; 
Desarrollar en C subprogramas para:
a) Partiendo desde el archivo PRESTAMOS.DAT y teniendo en cuenta solamente los préstamos con 
vencimiento en el mes de noviembre del corriente año, genere simultáneamente:
i) una matriz P de 100 x 200 donde las filas representan el número de socio y las columnas el número 
de libro, almacenando un 1 (uno) en P[i][j] si el socio i+1 debe devolver el libro número j+1, 0 
(cero) en caso contrario.
ii) un archivo de texto VENCENOVIEMBRE.TXT, con el siguiente formato en cada línea: 
idSocio idEjemplar díaVencimiento
b) Mediante una función int, a partir de P devolver la cantidad de socios que no tienen que devolver 
ningún libro en noviembre
Escribir el main.c con la invocación a los subprogramas desarrollados, declaraciones, definiciones e 
inicializaciones que sean necesarias. NO desarrollar la carga de ninguna estructura ni archivo, a menos 
que se pida explícitamente*/

#include <stdio.h>
#include <stdlib.h>
#define n 100
#define m 200


typedef struct {
    short int idsocio;
    short int idlibro;
    char idEjemplar[9]; // Ajuste del tamaño para incluir el carácter nulo '\0'
    char fechavencimiento[10]; // Ajuste del tamaño para incluir el carácter nulo '\0'
} Prestamo;


int contarSociosSinLibros(int matriz[n][m]);


int main() {

    int matriz[n][m];


    FILE *archivoPrestamos = fopen("prestamos.dat", "rb");
    FILE *archivoVencimiento = fopen("vencenoviembre.txt", "w");
     Prestamo prestamo;

    if (archivoPrestamos == NULL || archivoVencimiento == NULL) {
        perror("Error al abrir los archivos");

    }else{


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = 0;
        }
    }


    while (fread(&prestamo, sizeof(Prestamo), 1, archivoPrestamos) == 1) {

        if (prestamo.fechavencimiento[3] == '1' && prestamo.fechavencimiento[4] == '1') {
            matriz[prestamo.idsocio + 1][prestamo.idlibro + 1] = 1; // Marcar en la matriz
            fprintf(archivoVencimiento, "%d %s %s\n", prestamo.idsocio, prestamo.idEjemplar, prestamo.fechavencimiento);
        }
    }

    fclose(archivoPrestamos);
    fclose(archivoVencimiento);


    // Imprimir la matriz
    printf("Matriz P:\n");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 200; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }




    int sociosSinLibros = contarSociosSinLibros(matriz);
    printf("Cantidad de socios sin libros pendientes: %d\n", sociosSinLibros);


    }


    return 0;
}



int contarSociosSinLibros(int matriz[n][m]) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        int tieneLibros = 0;

        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 1) {
                tieneLibros++;

            }
        }

        if (!tieneLibros==0) {
            contador++;
        }
    }

    return contador;
}

/*Completar

#include <stdio.h>
#include <stdlib.h>

void cargarvector(int v[] , int n );
void muestravector(int v[] , int n );
void maximoVector(int v[] , int n ,int *max);

int main (){

int N , maximo ;
int v[_______]  // V tiene 20 posiciones 

printf(" ingrese la cantidad de datos");
scanf("%d" , &N);

cargar vector(v,n);
printf("el vector es " );
muestravector(v,n);
maximo vector (v, n,&maximo)
printf(" el maxomo es %d" ,maximo);

return 0 ;
}

void cargarvector ( int v[] , int N){
int i;
for (i=0 ; i<N ; i++) {
printf( "ingrese la posicion %2d del vector" ,v[i+1] );
scanf( "%d" , & V [i+1]);

}


void muestravector( int v[] , int n ){
int i ;
printf("%d" , v[1] );
for ( i=1 ; i<N ; i++) 
printf("%d" , v[i] );
}

void maximoVector ( int v[]; int N , int *max){
int i ;
*max=v[0];
for (i=0; i<N ; i++)
if (*max < v[i] )
  * max = v{i];
  }


*/












