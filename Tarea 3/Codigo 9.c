
#include <stdio.h>

int invertirNumero(int numero)
{
    int invertido = 0;

    while (numero > 0)
    {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }

    return invertido;
}

int main(void)
{
    int numero;

    printf("Ingrese un numero de cuatro digitos: ");
    scanf("%d", &numero);

    if (numero < 1000 || numero > 9999)
    {
        printf("Debe ingresar cuatro digitos.\n");
        return 1;
    }

    printf("Numero invertido: %04d\n",
           invertirNumero(numero));

    return 0;
}

