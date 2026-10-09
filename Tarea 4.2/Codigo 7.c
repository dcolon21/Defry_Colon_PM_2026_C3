
#include <stdio.h>

int main()
{
    int a[50][50], m, n;

    printf("Filas y columnas: ");
    scanf("%d %d", &m, &n);

    if (m < 1 || n < 1 || m > 50 || n > 50)
        return 1;

    printf("Ingrese la matriz:\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int arriba = 0, abajo = m - 1;
    int izquierda = 0, derecha = n - 1;

    printf("\nRecorrido en espiral:\n");

    while (arriba <= abajo && izquierda <= derecha)
    {
        for (int j = izquierda; j <= derecha; j++)
            printf("%d ", a[arriba][j]);

        arriba++;

        for (int i = arriba; i <= abajo; i++)
            printf("%d ", a[i][derecha]);

        derecha--;

        if (arriba <= abajo)
        {
            for (int j = derecha; j >= izquierda; j--)
                printf("%d ", a[abajo][j]);

            abajo--;
        }

        if (izquierda <= derecha)
        {
            for (int i = abajo; i >= arriba; i--)
                printf("%d ", a[i][izquierda]);

            izquierda++;
        }
    }

    printf("\n");

    return 0;
}

