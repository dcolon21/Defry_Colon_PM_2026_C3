
#include <stdio.h>

int esPerfecto(int numero)
{
    int suma = 0;

    if (numero < 2)
        return 0;

    for (int i = 1; i <= numero / 2; i++)
    {
        if (numero % i == 0)
            suma += i;
    }

    return suma == numero;
}

int main(void)
{
    int n;

    printf("Ingrese el valor de N: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Numero invalido.\n");
        return 1;
    }

    printf("Numeros perfectos entre 1 y %d:\n", n);

    for (int i = 1; i <= n; i++)
    {
        if (esPerfecto(i))
            printf("%d\n", i);
    }

    return 0;
}

