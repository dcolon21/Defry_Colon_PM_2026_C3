
#include <stdio.h>

int main()
{
    int a[50][50], b[50][50];
    int m, n;

    printf("Filas M: ");
    scanf("%d", &m);

    printf("Columnas N: ");
    scanf("%d", &n);

    if (m < 1 || n < 1 || m > 50 || n > 50)
        return 1;

    printf("Matriz A (MxN):\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Matriz B (NxM):\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    printf("\nMatriz resultante:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j] + b[j][i]);

        printf("\n");
    }

    return 0;
}

