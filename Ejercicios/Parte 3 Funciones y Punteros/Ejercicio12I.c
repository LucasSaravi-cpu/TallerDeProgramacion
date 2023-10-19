#include <stdio.h>

const char *determinarCategoriaEdad(int edad) {
    if (edad <= 11) {
        return "niño";
    } else if (edad <= 17) {
        return "adolescente";
    } else if (edad <= 25) {
        return "adulto joven";
    } else {
        return "adulto";
    }
}

int main() {
    int edad;

    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    const char *categoria = determinarCategoriaEdad(edad);

    printf("La persona es un %s.\n", categoria);

    return 0;
}




