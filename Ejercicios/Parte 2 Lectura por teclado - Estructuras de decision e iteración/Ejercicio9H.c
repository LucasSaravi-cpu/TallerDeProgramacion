/*Informar el importe de un pasaje a�reo teniendo en cuenta que el mismo depende de la
clase ($100000-turista y $200000-bussines) y recibe un descuento del 10% si viaja la primera
semana del mes. Ingresar la clase (T � B) y el d�a (1..31) indicar el importe del pasaje   */



#include <stdio.h>

int main() {
    char clase;
    int dia;
    double costo_base, importe_pasaje;

    // Solicitar al usuario que ingrese la clase (T para turista, B para business)
    printf("Ingrese la clase (T para turista, B para business): ");
    scanf(" %c", &clase);

    // Solicitar al usuario que ingrese el d�a del viaje (1..31)
    printf("Ingrese el d�a del viaje (1..31): ");
    scanf("%d", &dia);

    // Determinar el costo base seg�n la clase
    if (clase == 'T') {
        costo_base = 100000.0; // Costo base para turista
    } else if (clase == 'B') {
        costo_base = 200000.0; // Costo base para business
    } else {
        printf("Clase no v�lida. Use T para turista o B para business.\n");
        return 1; // Salir del programa con un error
    }

    // Verificar si el viaje es en la primera semana del mes (d�as 1-7)
    if (dia >= 1 && dia <= 7) {
        // Aplicar un descuento del 10%
        importe_pasaje = costo_base - (costo_base * 0.10);
    } else {
        importe_pasaje = costo_base;
    }

    // Mostrar el importe del pasaje
    printf("El importe del pasaje es: $%.2lf\n", importe_pasaje);

    return 0;
}
