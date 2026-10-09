
#include <stdio.h>

void contarNumeros(int vec[], int n)
{
    int positivos = 0, negativos = 0, ceros = 0;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] > 0)
            positivos++;
        else if (vec[i] < 0)
            negativos++;
        else
            ceros++;
    }

    printf("\nPositivos: %d", positivos);
    printf("\nNegativos: %d", negativos);
    printf("\nCeros: %d\n", ceros);
}

int main(void)
{
    int vec[100], n;

    printf("Cantidad de numeros (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1);
        if (scanf("%d", &vec[i]) != 1)
            return 1;
    }

    contarNumeros(vec, n);
    return 0;
}

