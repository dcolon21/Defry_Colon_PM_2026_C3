
#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long resultado = 1;

    for (int i = 2; i <= n; i++)
        resultado *= i;

    return resultado;
}

int main(void)
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    if (n < 0 || n > 20)
    {
        printf("Ingrese un numero entre 0 y 20.\n");
        return 1;
    }

    printf("%d! = %llu\n", n, factorial(n));
    return 0;
}

