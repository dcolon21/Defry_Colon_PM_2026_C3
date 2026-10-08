
#include <stdio.h>

void calcularPromedios(int n)
{
    int numero, pares = 0, impares = 0;
    double sumaPares = 0, sumaImpares = 0;

    for (int i = 1; i <= n; i++)
    {
        printf("Numero %d: ", i);
        scanf("%d", &numero);

        if (numero % 2 == 0)
        {
            sumaPares += numero;
            pares++;
        }
        else
        {
            sumaImpares += numero;
            impares++;
        }
    }

    if (pares > 0)
        printf("Promedio pares: %.2f\n", sumaPares / pares);
    else
        printf("No hay numeros pares.\n");

    if (impares > 0)
        printf("Promedio impares: %.2f\n", sumaImpares / impares);
    else
        printf("No hay numeros impares.\n");
}

int main(void)
{
    int n;

    printf("Cantidad de numeros (1 a 500): ");
    scanf("%d", &n);

    if (n < 1 || n > 500)
    {
        printf("Cantidad invalida.\n");
        return 1;
    }

    calcularPromedios(n);
    return 0;
}

