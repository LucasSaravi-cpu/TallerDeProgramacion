/*Dado un vector de enteros de n elementos, desarrollar una funci�n que encuentre y devuelva la posici�n
del m�ximo. Implementar 3 veces utilizando for, while y do while*/
#include <stdio.h>
#include <stdlib.h>

int encuentrapos_for(int v[], int n);
int encuentrapos_while(int v[], int n);
int encuentrapos_do_while(int v[], int n);

int main() {
    FILE *file;
    int n, i;
    int v[50];

    // Abrir el archivo para lectura
    file = fopen("NUMEROS.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leer la cantidad de n�meros
    fscanf(file, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &v[i]);

    }



    fclose(file); // Cerrar el archivo

    // Mostrar el vector
    printf("Vector de enteros:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");


    // Encontrar y mostrar la posici�n del m�ximo usando las tres funciones
    printf("La posicion del maximo (for) es: %d\n", encuentrapos_for(v, n));
    printf("La posicion del maximo (while) es: %d\n", encuentrapos_while(v, n));
    printf("La posicion del maximo (do while) es: %d\n", encuentrapos_do_while(v, n));

    return 0;
}

// Funci�n que encuentra la posici�n del m�ximo usando for
int encuentrapos_for(int v[], int n) {
int max=v[0],pos=0,i;

for (i=1;i<n;i++){
    if (v[i]>max){
       max=v[i];
       pos=i;}
}
return pos+1;
}

// Funci�n que encuentra la posici�n del m�ximo usando while
int encuentrapos_while(int v[], int n) {
    int max = v[0], pos = 0, i = 1;
    while (i < n) {
        if (v[i] > max) {
            max = v[i];
            pos = i;
        }
        i++;
    }
    return pos + 1; // Retorna la posici�n en base 1
}

// Funci�n que encuentra la posici�n del m�ximo usando do while
int encuentrapos_do_while(int v[], int n) {
    int max = v[0], pos = 0, i = 1;
    if (n > 1) {
        do {
            if (v[i] > max) {
                max = v[i];
                pos = i;
            }
            i++;
        } while (i < n);
    }
    return pos + 1; // Retorna la posici�n en base 1
}
