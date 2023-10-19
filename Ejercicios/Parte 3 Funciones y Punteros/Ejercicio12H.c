#include <stdio.h>

double calcularImportePasaje(char clase, int dia) {
    double costo_base;

    if (clase == 'T') {
        costo_base = 100000.0; // Costo base para turista
    } else if (clase == 'B') {
        costo_base = 200000.0; // Costo base para business
    } else {
        printf("Clase no válida. Use T para turista o B para business.\n");
        return -1.0; // Valor negativo para indicar un error
    }

    if (dia >= 1 && dia <= 7) {
        return costo_base - (costo_base * 0.10); // Aplicar descuento del 10% en la primera semana
    } else {
        return costo_base;
    }
}

int main() {
    char clase;
    int dia;
    double importe_pasaje;

    printf("Ingrese la clase (T para turista, B para business): ");
    scanf(" %c", &clase);

    printf("Ingrese el día del viaje (1..31): ");
    scanf("%d", &dia);

    importe_pasaje = calcularImportePasaje(clase, dia);

    if (importe_pasaje >= 0) {
        printf("El importe del pasaje es: $%.2lf\n", importe_pasaje);
    }

    return 0;
}








