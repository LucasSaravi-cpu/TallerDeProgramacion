/*
Una biblioteca tiene un archivo binario prestamos.dat que representa los ejemlares prestados a sus socios con el sigueinte formato de registro

typedef struct{
short int idsocio;
short int idlibro;
char idEjemplar[8]
char fechavencimiento[9]
}

desarrolar en en c sub programas para 

a) partiendo desde archivo prestamos.dat y teniendo en cuenta solamente los prestamos con vencimiento en el mes de noviembre del corriente año genere simultaneamente

una matriz P de 100x200 donde las filas representan el nmero de socios y las columnas el numero de libro , almacenando 1 en p[i][j] si el socio i+1 debe devolvevr el libro numero j+1 0 en caso contrario

un archivo de texto vencenoviembre.txt con el siguiente formato en cada linea idsocio idejemplar dia vencimiento

B) mediante una funion int a partir de P devolver la cantidad de socos que no tienen que devolver ningun libro

escribir el main.c con la invocacion subproframas desarrolados declaraciones definiciones e inicializaciones.}

*/
#include <stdio.h>


typedef struct {
    short int idsocio;
    short int idlibro;
    char idEjemplar[9]; // Ajuste del tamaño para incluir el carácter nulo '\0'
    char fechavencimiento[10]; // Ajuste del tamaño para incluir el carácter nulo '\0'
} Prestamo;

// Función para generar la matriz y el archivo de texto
void generarMatrizYArchivo(int matriz[][200]) {
    FILE *archivoPrestamos = fopen("prestamos.dat", "rb");
    FILE *archivoVencimiento = fopen("vencenoviembre.txt", "w");

    if (archivoPrestamos == NULL || archivoVencimiento == NULL) {
        perror("Error al abrir los archivos");
        return;
    }

    // Inicialización de la matriz con ceros
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 200; j++) {
            matriz[i][j] = 0;
        }
    }

    Prestamo prestamo;
    while (fread(&prestamo, sizeof(Prestamo), 1, archivoPrestamos) == 1) {
        // Verificar si el vencimiento es en noviembre
        if (prestamo.fechavencimiento[3] == '1' && prestamo.fechavencimiento[4] == '1') {
            matriz[prestamo.idsocio - 1][prestamo.idlibro - 1] = 1; // Marcar en la matriz
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
}

// Función para contar socios sin libros pendientes
int contarSociosSinLibros(int matriz[][200]) {
    int contador = 0;

    for (int i = 0; i < 100; i++) {
        int tieneLibros = 0;

        for (int j = 0; j < 200; j++) {
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

int main() {
    int matriz[100][200]; // Matriz para almacenar la información
    generarMatrizYArchivo(matriz);

    int sociosSinLibros = contarSociosSinLibros(matriz);
    printf("Cantidad de socios sin libros pendientes: %d\n", sociosSinLibros);

    return 0;
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












