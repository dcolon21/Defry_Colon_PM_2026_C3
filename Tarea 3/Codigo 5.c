
#include <stdio.h>

double potencia(int base, int exponente)
{
    double resultado = 1;

    for (int i = 0; i < exponente; i++)
        resultado *= base;

    return resultado;
}

double calcularSerie(int n)
{
    double suma = 0;

    for (int i = 1; i <= n; i++)
    {
        double termino = potencia(i, i);

        if (i % 2 == 0)
            suma -= termino;
        else
            suma += termino;
    }

    return suma;
}

int main(void)
{
    int n;

    printf("Numero de terminos: ");
    scanf("%d", &n);

    if (n < 1)
        return 1;

    printf("Resultado: %.2f\n", calcularSerie(n));
    return 0;
}

