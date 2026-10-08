
#include <stdio.h>

double valorAbsoluto(double x)
{
    if (x < 0)
        return -x;
    return x;
}

double calcularCoseno(double x, int *cantidad)
{
    double suma = 1.0;
    double termino = 1.0;
    int n = 0;

    *cantidad = 1;

    do
    {
        n++;
        termino = -termino * x * x /
                  ((2.0 * n - 1) * (2.0 * n));

        suma += termino;
        (*cantidad)++;

    } while (valorAbsoluto(termino) > 0.001 && n < 100);

    return suma;
}

int main(void)
{
    double x;
    int cantidad;

    printf("Ingrese X en radianes: ");
    scanf("%lf", &x);

    printf("Coseno aproximado: %.6f\n",
           calcularCoseno(x, &cantidad));

    printf("Terminos utilizados: %d\n", cantidad);

    return 0;
}

