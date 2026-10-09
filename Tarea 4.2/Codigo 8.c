
#include <stdio.h>

int main()
{
    int a[50][50], m, n;

    printf("Cantidad de filas: ");
    scanf("%d", &m);

    printf("Cantidad de columnas: ");
    scanf("%d", &n);

    if (m < 1 || n < 1 || m > 50 || n > 50)
        return 1;

    printf("Ingrese la matriz:\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\nRecorrido por columnas:\n");

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i][j]);
    }

    printf("\n");

    return 0;
}

