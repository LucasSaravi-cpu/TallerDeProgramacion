/* Desarrollar un programa que grabe en un archivo binario NUMEN.DAT números enteros ingresados por
teclado, finaliza el ingreso cuando aparecen dos números consecutivos iguales (esos datos van al archivo).
Mostrar el archivo generado*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main (){
    int aux, num;
    FILE * archivo;

    aux  = -1;
    archivo= fopen("NUMEN.dat", "wb" );  //archivo nuevo binario, si existe se borra su contenido, para escritura

    if (archivo == NULL) {
        printf("archivo clientes no existe!");
    } else{



    printf(" ingrese un numero entero: \n");
    scanf("%d", &num);


    while (aux!=num){
        fwrite(&num, sizeof(int), 1, archivo);
        aux=num;
        printf(" ingrese un numero entero: \n");
        scanf("%d", &num);

    }
   fclose(archivo);
    }

    //Se abre de nuevo el archivo para una lectura
    archivo= fopen("NUMEN.dat", "rb+" ); //// archivo binario ya existente para L/E

    fread(&num,sizeof(int),1,archivo);
    while(!feof(archivo)) {
        printf("%d",num);
        fread(&num,sizeof(int),1,archivo);

    }

    fclose(archivo);

}

