/* Dado un archivo de texto que representa la facturaci�n diaria de una empresa. Hay dos tipos de l�neas, la
de cabecera (una por factura y es la primera), y las de detalle que est�n a continuaci�n y representan los
art�culos de la factura. La cabecera empieza con la letra F seguido 12 d�gitos del n�mero de factura y 30
caracteres el nombre del cliente. La de detalle empieza con la letra D seguido de 6 d�gitos c�digo de art�culo,
20 caracteres de descripci�n de art�culo, 7 d�gitos para el precio los dos �ltimos son decimales, y 5 d�gitos
de cantidad. Desarrollar un programa que lea el archivo de facturaci�n y genere un archivo binario que por
cada factura genere un registro con n�mero de factura, cantidad de �tems e importe total*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para el registro de factura en el archivo binario
typedef struct {
    char numeroFactura[13]; // N�mero de factura de 12 d�gitos + terminador de cadena
    int cantidadItems;      // Cantidad de �tems en la factura
    float importeTotal;     // Importe total de la factura
} FacturaRegistro;


void mostrarArchivo();


int main() {
    FILE *archivoTexto = fopen("facturacion.txt", "r");
    FILE *archivoBinario = fopen("facturacion.dat", "wb+");


    FacturaRegistro factura;
    factura.cantidadItems = 0;
    factura.importeTotal = 0.0;

     char tipoLinea;
    char nombreCliente[31]; // Nombre del cliente (30 caracteres + terminador de cadena)
    char codigoArticulo[7];
    char descripcion[21];
    float precio;   // Precio en centavos para facilitar el c�lculo
    int cantidad; // Cantidad de art�culos

    if (!archivoTexto || !archivoBinario) {
        printf("Error al abrir los archivos.\n");

    } else{



    while (fscanf(archivoTexto, " %c", &tipoLinea)==1) {
        // Verificar si es una l�nea de cabecera (comienza con 'F')
        if (tipoLinea == 'F') {
            // Si ya hab�a una factura procesada, guardarla en el archivo binario
            if (factura.cantidadItems > 0) {
                fwrite(&factura, sizeof(FacturaRegistro), 1, archivoBinario);
            }

            // Reiniciar los datos de la nueva factura
            factura.cantidadItems = 0;
            factura.importeTotal = 0.0;


           fscanf(archivoTexto, "%12s%30[^\n]", factura.numeroFactura, nombreCliente);
        }
        // Verificar si es una l�nea de detalle (comienza con 'D')
        else if (tipoLinea == 'D') {
           fscanf(archivoTexto, "%7s%21s%7f%5d", codigoArticulo, descripcion, &precio, &cantidad);
         printf("%f\n",precio);

           factura.cantidadItems += cantidad;
            factura.importeTotal += (precio / 100.0) * cantidad;
        }


    }
        // Guardar la �ltima factura procesada en el archivo binario
    if (factura.cantidadItems > 0) {
        fwrite(&factura, sizeof(FacturaRegistro), 1, archivoBinario);
    }

    // Cerrar archivos
    fclose(archivoTexto);
    fclose(archivoBinario);

    printf("Archivo binario de facturacion generado correctamente.\n");

    }


     mostrarArchivo();
    return 0;
}


void mostrarArchivo(){

 FILE *archivoBinario = fopen("facturacion.dat", "rb");

    if (!archivoBinario) {
        printf("Error al abrir el archivo binario de facturacion.\n");

    } else {

    FacturaRegistro factura;

    printf("Contenido del archivo binario:\n");


    while (fread(&factura, sizeof(FacturaRegistro), 1, archivoBinario)) {
        printf("Numero factura : %s\n", factura.numeroFactura);
        printf("Cantidad items %d\n", factura.cantidadItems);
        printf("Importe total : %.2f\n", factura.importeTotal);
        printf("------------------------\n");
    }

    fclose(archivoBinario);
    }
}
