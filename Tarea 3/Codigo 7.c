
#include <stdio.h>

int esPrimo(int numero)
{
    if (numero < 2)
        return 0;

    for (int i = 2; i <= numero / i; i++)
    {
        if (numero % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    int numero;

    printf("Ingrese un numero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0)
    {
        printf("Numero invalido.\n");
        return 1;
    }

    if (esPrimo(numero))
        printf("%d es primo.\n", numero);
    else
        printf("%d no es primo.\n", numero);

    return 0;
}

