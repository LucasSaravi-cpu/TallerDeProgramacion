/*Una empresa distribuidora de repuestos de automotores tiene un archivo binario PENDIFACTU.DAT con las
facturas pendientes de cobro, con el siguiente formato de registro.
 typedef struct {
 int NroFactura; //ordenado por este criterio
 float Precio; //Precio unitario del articulo
 } RegistroFactu;
Las facturas ya cobradas están registradas en otro archivo binario COBROS.DAT de enteros (ordenado) que
representa el número de factura (podría haber facturas erróneas)
Crear un archivo PENDIFACTUNUEVO.DAT con la misma estructura de PENDIFACTU.DAT tal que solo queden
las facturas no cobradas, informar finalmente el importe total cobrado y la cantidad de facturas erróneas que
había en COBROS.DAT.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char codigo[5];   // Código de la factura
    unsigned char ctotales;   // Créditos totales
    unsigned char cpagadas;   // Créditos pagados
} RegistroFactu;

typedef struct {
    char codigo[5];   // Código de la factura en pagos
} RegistroPago;

int main() {
    FILE *archivoPendientes = fopen("PENDIFACTU.DAT", "rb");
    FILE *archivoCobros = fopen("COBROS.DAT", "rb");
    FILE *archivoPendientesNuevo = fopen("PENDIFACTUNUEVO.DAT", "wb");


        RegistroFactu factura;
    RegistroPago pago;
    float totalCobrado = 0.0;
    int facturasErroneas = 0;
    if (!archivoPendientes || !archivoCobros || !archivoPendientesNuevo) {
        printf("Error al abrir los archivos.\n");

    } else{



    // Leer la primera factura y pago para empezar
    fread(&factura, sizeof(RegistroFactu), 1, archivoPendientes);
    fread(&pago, sizeof(RegistroPago), 1, archivoCobros);

    while (!feof(archivoPendientes) && !feof(archivoCobros)) {
        // Comparar el código de la factura y el código de pago
        if (strncmp(factura.codigo, pago.codigo, 5) < 0) {
            // La factura no está en el archivo de pagos, se guarda en el nuevo archivo
            fwrite(&factura, sizeof(RegistroFactu), 1, archivoPendientesNuevo);
            fread(&factura, sizeof(RegistroFactu), 1, archivoPendientes); // Avanzar a la siguiente factura
        }
        else if (strncmp(factura.codigo, pago.codigo, 5) == 0) {
            // La factura fue pagada
            factura.cpagadas++;
            if (factura.cpagadas == factura.ctotales) {
                totalCobrado += factura.ctotales; // Sumar al total cobrado
            } else {
                fwrite(&factura, sizeof(RegistroFactu), 1, archivoPendientesNuevo); // Aún quedan créditos pendientes
            }
            fread(&factura, sizeof(RegistroFactu), 1, archivoPendientes); // Avanzar a la siguiente factura
            fread(&pago, sizeof(RegistroPago), 1, archivoCobros);         // Avanzar al siguiente pago
        }
        else {
            // Si el pago no tiene una factura correspondiente, contar como errónea
            facturasErroneas++;
            fread(&pago, sizeof(RegistroPago), 1, archivoCobros);         // Avanzar al siguiente pago
        }
    }

    // Procesar facturas restantes en pendientes
    while (!feof(archivoPendientes)) {
        fwrite(&factura, sizeof(RegistroFactu), 1, archivoPendientesNuevo);
        fread(&factura, sizeof(RegistroFactu), 1, archivoPendientes);
    }

    // Cerrar archivos
    fclose(archivoPendientes);
    fclose(archivoCobros);
    fclose(archivoPendientesNuevo);

    // Informar resultados
    printf("Importe total cobrado: %.2f\n", totalCobrado);
    printf("Cantidad de facturas erróneas en COBROS.DAT: %d\n", facturasErroneas);

    }

    return 0;
}
