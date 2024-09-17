/*Informar el importe de un pasaje aéreo teniendo en cuenta que el mismo depende de la
clase ($100000-turista y $200000-bussines) y recibe un descuento del 10% si viaja la primera
semana del mes. Ingresar la clase (T ó B) y el día (1..31) indicar el importe del pasaje   */



#include <stdio.h>

int main() {
    char clase;
    int dia;
    double costo_base, importe_pasaje;


    printf("Ingrese la clase (T para turista, B para business): ");
    scanf(" %c", &clase);


    printf("Ingrese el dIa del viaje (1..31): ");
    scanf("%d", &dia);


    if (clase == 'T') {
        costo_base = 100000.0;
    } else if (clase == 'B') {
        costo_base = 200000.0;
    } else {
        printf("Clase no valida. Use T para turista o B para business.\n");
        return 1;
    }


    if (dia >= 1 && dia <= 7) {

        importe_pasaje = costo_base - (costo_base * 0.10);
    } else {
        importe_pasaje = costo_base;
    }


    printf("El importe del pasaje es: $%.2lf\n", importe_pasaje);

    return 0;
}
