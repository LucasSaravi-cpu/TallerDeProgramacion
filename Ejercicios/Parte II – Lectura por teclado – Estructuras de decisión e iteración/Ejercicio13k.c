/*Informar el importe de un pasaje aéreo teniendo en cuenta que el mismo depende de la clase (Turista
- Business) y recibe un descuento del 10% si viaja la primera semana del mes. Ingresar la clase (T ó B) 
y el día (1..31) indicar el importe del pasaje (suponiendo que los precios bases son constantes 
previamente definidas como 100000 y 200000, respectivamente)   */


#include <stdio.h>

#define PRECIO_TURISTA 100000
#define PRECIO_BUSINESS 200000
#define DESCUENTO 0.10 // 10% de descuento

int main() {
    char clase;
    int dia;
    float precioBase;
    float importe;

    // Solicitar clase y día
    printf("Ingrese la clase (T para Turista, B para Business): ");
    scanf(" %c", &clase);
    printf("Ingrese el día del viaje (1..31): ");
    scanf("%d", &dia);

    // Determinar el precio base según la clase
    if (clase == 'T' || clase == 't') {
        precioBase = PRECIO_TURISTA;
    } else if (clase == 'B' || clase == 'b') {
        precioBase = PRECIO_BUSINESS;
    } else {
        printf("Clase no válida.\n");
        return 1; // Salir con error
    }

    // Aplicar descuento si el día está en la primera semana
    if (dia >= 1 && dia <= 7) {
        importe = precioBase * (1 - DESCUENTO);
    } else {
        importe = precioBase;
    }

    // Mostrar el importe final
    printf("El importe del pasaje es: %.2f\n", importe);

    return 0;
}
