
#include <stdio.h>

double calcularSerie(int n)
{
    double resultado = 1.0;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            resultado *= i;
        else
            resultado /= i;
    }

    return resultado;
}

int main(void)
{
    int n;

    printf("Numero de terminos: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Cantidad invalida.\n");
        return 1;
    }

    printf("Resultado: %.6f\n", calcularSerie(n));
    return 0;
}

