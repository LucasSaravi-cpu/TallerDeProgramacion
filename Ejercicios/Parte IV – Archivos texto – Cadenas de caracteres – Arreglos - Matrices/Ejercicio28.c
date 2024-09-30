/*   Desarrollar una funci�n que pase la primera letra a may�scula de cada palabra de una cadena de caracteres.
Por ejemplo �calle jujuy 1085 6 a� pasa a �Calle Jujuy 1085 6 A�*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void capitalizarPrimeraLetra(char *cadena);

int main() {
    char cadena[100];


    FILE *archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }


    fgets(cadena, sizeof(cadena), archivo);
    fclose(archivo);

    cadena[strcspn(cadena, "\n")] = 0;

    capitalizarPrimeraLetra(cadena);

    printf("Cadena con primeras letras en may�scula: %s\n", cadena);

    return 0;
}

void capitalizarPrimeraLetra(char *cadena) {
    int i;
    int longitud = strlen(cadena);

    for (i = 0; i < longitud; i++) {
        // Si es el primer car�cter o el anterior es un espacio
        if (i == 0 || (cadena[i - 1] == ' ')) {
            cadena[i] = toupper(cadena[i]);
        }
    }
}
