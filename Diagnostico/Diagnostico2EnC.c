/*En una empresa de taxis, se registran datos de los N autos que la misma posee. Para cada auto, se tiene: Patente (cadena de 7), viajes realizados en agosto (>0), valor facturado en agosto.
Se pide: ingresar los datos mencionados desde teclado, hallar e informar:
   -   el porcentaje de autos que han facturado más de X (siendo X un dato ingresado previamente)
   -  patente del auto que realizó la menor cantidad de viajes (suponerlo único).*/

#include <stdio.h>

#define MAX_AUTOS 100

typedef struct {
    char patente[8];  // Cadena de 7 caracteres + '\0' para el terminador
    unsigned short viajesEnAgosto;
    unsigned short valorFacturado;
} AutoRegistro;

void LeerDatosAutos(AutoRegistro autos[], int *cantidad) {
    int i;
    printf("Ingrese la cantidad de autos: ");
    scanf("%d", cantidad);

    for (i = 0; i < *cantidad; i++) {
        printf("Ingrese los datos del auto %d:\n", i + 1);
        printf("Patente: ");
        scanf("%s", autos[i].patente);
        printf("Viajes realizados en agosto: ");
        scanf("%hu", &autos[i].viajesEnAgosto);
        printf("Valor facturado en agosto: ");
        scanf("%hu", &autos[i].valorFacturado);
    }
}

float CalcularPorcentajeFacturacionSuperiorA(unsigned short valorLimite, AutoRegistro autos[], int cantidad) {
    int i, conteo = 0;
    for (i = 0; i < cantidad; i++) {
        if (autos[i].valorFacturado > valorLimite) {
            conteo++;
        }
    }
    return (cantidad > 0) ? ((float)conteo / cantidad) * 100 : 0.0;
}

void EncontrarAutoConMenosViajes(AutoRegistro autos[], int cantidad) {
    int i;
    if (cantidad > 0) {
        char patenteMenorViajes[8];
        unsigned short viajesMenores = autos[0].viajesEnAgosto;

        // Inicializa la patenteMenorViajes con la patente del primer auto
        snprintf(patenteMenorViajes, sizeof(patenteMenorViajes), "%s", autos[0].patente);

        for (i = 1; i < cantidad; i++) {
            if (autos[i].viajesEnAgosto < viajesMenores) {
                viajesMenores = autos[i].viajesEnAgosto;
                snprintf(patenteMenorViajes, sizeof(patenteMenorViajes), "%s", autos[i].patente);
            }
        }
        printf("Patente del auto con la menor cantidad de viajes: %s\n", patenteMenorViajes);
    } else {
        printf("No hay autos registrados.\n");
    }
}

int main() {
    AutoRegistro autos[MAX_AUTOS];
    int cantidad;
    unsigned short valorComparacion;

    LeerDatosAutos(autos, &cantidad);

    printf("Ingrese un valor de facturación para comparar: ");
    scanf("%hu", &valorComparacion);

    printf("Porcentaje de autos que han facturado más de %hu: %.2f%%\n",
           valorComparacion, CalcularPorcentajeFacturacionSuperiorA(valorComparacion, autos, cantidad));

    EncontrarAutoConMenosViajes(autos, cantidad);

    return 0;
}
