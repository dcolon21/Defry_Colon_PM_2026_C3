
#include <stdio.h>

#define N 100
#define DIGITOS 30

void sumar(const int a[], const int b[], int r[])
{
    int acarreo = 0;

    for (int j = 0; j < DIGITOS; j++)
    {
        int suma = a[j] + b[j] + acarreo;
        r[j] = suma % 10;
        acarreo = suma / 10;
    }
}

void imprimir(const int numero[])
{
    int inicio = DIGITOS - 1;

    while (inicio > 0 && numero[inicio] == 0)
        inicio--;

    for (int j = inicio; j >= 0; j--)
        printf("%d", numero[j]);
}

int main(void)
{
    int fib[N][DIGITOS] = {{0}};

    fib[1][0] = 1;

    for (int i = 2; i < N; i++)
        sumar(fib[i - 1], fib[i - 2], fib[i]);

    for (int i = 0; i < N; i++)
    {
        printf("Fibonacci %d = ", i + 1);
        imprimir(fib[i]);
        printf("\n");
    }

    return 0;
}

