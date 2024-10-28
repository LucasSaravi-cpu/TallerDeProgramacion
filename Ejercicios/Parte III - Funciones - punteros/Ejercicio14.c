/* Para N personas se registró el peso y la altura, calcular sus índices de masa corporal y determinar e informar
el porcentaje de los que tienen un índice normal (18.5 <= ICM <= 24.9). Implementar y utilizar la función
IMC correctamente parametrizada que devuelva verdadero si el índice es normal y falso en caso contrario.
*/


#include <stdio.h>

int imc(float peso, float altura);

int main() {
    int N, contador_normal = 0;

    printf("Ingrese el numero de personas: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        float peso, altura;
        printf("Ingrese el peso de la persona %d (en kg): ", i + 1);
        scanf("%f", &peso);
        printf("Ingrese la altura de la persona %d (en metros): ", i + 1);
        scanf("%f", &altura);

        if (imc(peso, altura)) {
            contador_normal++;
        }
    }

    float porcentaje_normal = (N > 0) ? ((float)contador_normal / N) * 100 : 0;
    printf("El porcentaje de personas con IMC normal es: %.2f%%\n", porcentaje_normal);

    return 0;
}


int imc(float peso, float altura) {

    float indice = peso / (altura * altura);
    return (indice >= 18 && indice <= 21);
}
