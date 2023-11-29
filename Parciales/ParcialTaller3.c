/* Un hotel 20 habitaciones tiene las reservas para el mes de julio en un archivo reservas.txt cada linea tiene habitantes , cantidad de huespedes , duia , inicio , dia salda todos int 
Desarrrollar subprogramas que

a) Desde reservas txt genere una matriz A 31x20 donde las filas representen los dias del mes ( la fila 0 es el dia 1 ) y las columnas
los habitatantes ( 0 -19 ) almacenando la cantidad de huespedes a cada dia 

Ejemplo  linea 4 5 3 5 se almacena 5 en la posicion 2 4 y 3 4

A partir de A devolver la cantidad de dias que no hay habitaciones libres funcion int

Luego desde la matriz A generar un archivo binario disponibles.dat con el siguiente registro 

typedef struct {
	
int dia , ocupacion , habitantes; } regdisponibles;

solo grabar los dias que tienen alguna habitacion libres

Escribir el main */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	int dia;
	int ocupacion;
	int habitacion;
}regdisponible;


void generaMatrizA( int A[31][20]){
	
	int hab,huesped,inicio,salida;
	file * arch = fopen("reservas.txt","r");
	
	fscanf(arch,"%d %d %d %d" , &hab , &huesped , & inicio , %salida);
	

	while(!feof(arch)) {
		
		for ( int dia = inicio ; dia<=salida ; dia ++ ){
			
			A[inicio-1][salida-1]= huesped;
		}
	fscanf(arch,"%d %d %d %d" , &hab , &huesped , & inicio , %salida);	
		
	}
	
}

int contardiassinhabitacioneslbres(int A[31][20] ){
	
	int diassinlibres=0;
	
	for ( int dias=0 ; dia <31 ;dia++){
		int libres=0;
		for ( int hab= 0 ; hab<20 ; hab++){
			if A[dia][hab]==0 {
				libres++;
			}
		
		}
		
		if libres==0 {
			diaslibres+++;
	}
	
	return diaslibres;
}


void generaArchDisponibles ( int A[31][20] ){
	
	
	File * arch =fopen("disponible.dat","wb");
	regdisponible registro;
	
	for ( dia=0 ; dia<31 ; dia++){
		int libres=0;
		for (int hab=0 ; hab<20 ; hab++){
			if (A[dia][hab]==0{
				libres++;
			}
		}
	if libres>0 {
		registro.dia=dia+1;
		registro.ocupacion=20-libres;
		registro.habitaciones=libres;
		
		fwrite(&registro,sizeof(Rgdisponible),1,arch);
	}
	}
	fclose(arch);
}




void main(){
	
	int A[31][20] ={0];
	generamatrizA(A);
	intdiassinlibres=contardiassinhabitacioneslibres(A);
	generaArchdisponible(A);
	}
