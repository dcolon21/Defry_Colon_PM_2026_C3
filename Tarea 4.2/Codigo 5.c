
#include <stdio.h>

int main()
{
    static double a[50][50];
    static double b[50][50];
    static double c[50][50];

    int m, n, p;

    printf("Filas de A (M): ");
    scanf("%d", &m);

    printf("Columnas de A y filas de B (N): ");
    scanf("%d", &n);

    printf("Columnas de B (P): ");
    scanf("%d", &p);

    if (m < 1 || n < 1 || p < 1 ||
        m > 50 || n > 50 || p > 50)
        return 1;

    printf("\nMatriz A:\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    printf("\nMatriz B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%lf", &b[i][j]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("\nProducto A x B:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%.2f ", c[i][j]);

        printf("\n");
    }

    return 0;
}

