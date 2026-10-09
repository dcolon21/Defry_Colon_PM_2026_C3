
#include <stdio.h>

int main()
{
    int a[100][100], n;
    long long objetivo = 0;
    int valido = 1;

    printf("Orden impar de la matriz: ");
    scanf("%d", &n);

    if (n < 1 || n > 100 || n % 2 == 0)
        return 1;

    printf("Ingrese la matriz:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int j = 0; j < n; j++)
        objetivo += a[0][j];

    for (int i = 0; i < n; i++)
    {
        long long fila = 0, columna = 0;

        for (int j = 0; j < n; j++)
        {
            fila += a[i][j];
            columna += a[j][i];
        }

        if (fila != objetivo || columna != objetivo)
            valido = 0;
    }

    long long d1 = 0, d2 = 0;

    for (int i = 0; i < n; i++)
    {
        d1 += a[i][i];
        d2 += a[i][n - 1 - i];
    }

    if (d1 != objetivo || d2 != objetivo)
        valido = 0;

    int vistos[10001] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = a[i][j];

            if (x < 1 || x > n * n)
                valido = 0;
            else
            {
                if (vistos[x])
                    valido = 0;

                vistos[x] = 1;
            }
        }
    }

    if (valido)
        printf("Es un cuadrado magico normal.\n");
    else
        printf("No es un cuadrado magico normal.\n");

    return 0;
}

