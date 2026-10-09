
#include <stdio.h>

int main()
{
    double a[50][50], aux;
    int m, n;

    printf("Cantidad de filas: ");
    scanf("%d", &m);

    printf("Cantidad de columnas: ");
    scanf("%d", &n);

    if (m < 1 || n < 1 || m > 50 || n > 50)
        return 1;

    printf("Ingrese los elementos:\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    for (int i = 0; i < m / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux = a[i][j];
            a[i][j] = a[m - 1 - i][j];
            a[m - 1 - i][j] = aux;
        }
    }

    printf("\nMatriz invertida:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.2f ", a[i][j]);

        printf("\n");
    }

    return 0;
}

