/* Dado un archivo de texto que representa la facturación diaria de una empresa. Hay dos tipos de líneas, la
de cabecera (una por factura y es la primera), y las de detalle que están a continuación y representan los
artículos de la factura. La cabecera empieza con la letra F seguido 12 dígitos del número de factura y 30
caracteres el nombre del cliente. La de detalle empieza con la letra D seguido de 6 dígitos código de artículo,
20 caracteres de descripción de artículo, 7 dígitos para el precio los dos últimos son decimales, y 5 dígitos
de cantidad. Desarrollar un programa que lea el archivo de facturación y genere un archivo binario que por
cada factura genere un registro con número de factura, cantidad de ítems e importe total*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para el registro de factura en el archivo binario
typedef struct {
    char numeroFactura[13]; // Número de factura de 12 dígitos + terminador de cadena
    int cantidadItems;      // Cantidad de ítems en la factura
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
    float precio;   // Precio en centavos para facilitar el cálculo
    int cantidad; // Cantidad de artículos

    if (!archivoTexto || !archivoBinario) {
        printf("Error al abrir los archivos.\n");

    } else{



    while (fscanf(archivoTexto, " %c", &tipoLinea)==1) {
        // Verificar si es una línea de cabecera (comienza con 'F')
        if (tipoLinea == 'F') {
            // Si ya había una factura procesada, guardarla en el archivo binario
            if (factura.cantidadItems > 0) {
                fwrite(&factura, sizeof(FacturaRegistro), 1, archivoBinario);
            }

            // Reiniciar los datos de la nueva factura
            factura.cantidadItems = 0;
            factura.importeTotal = 0.0;


           fscanf(archivoTexto, "%12s%30[^\n]", factura.numeroFactura, nombreCliente);
        }
        // Verificar si es una línea de detalle (comienza con 'D')
        else if (tipoLinea == 'D') {
           fscanf(archivoTexto, "%7s%21s%7f%5d", codigoArticulo, descripcion, &precio, &cantidad);
         printf("%f\n",precio);

           factura.cantidadItems += cantidad;
            factura.importeTotal += (precio / 100.0) * cantidad;
        }


    }
        // Guardar la última factura procesada en el archivo binario
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
