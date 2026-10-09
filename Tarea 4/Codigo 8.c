
#include <stdio.h>

void ordenar(int a[], int n)
{
    int aux;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

int main()
{
    int a[200], n, m;

    printf("Cantidad del primer arreglo: ");
    scanf("%d", &n);

    printf("Cantidad del segundo arreglo: ");
    scanf("%d", &m);

    if (n < 1 || m < 1 || n > 100 || m > 100)
        return 1;

    printf("\nPrimer arreglo:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nSegundo arreglo:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &a[n + i]);

    ordenar(a, n + m);

    printf("\nArreglo ordenado:\n");

    for (int i = 0; i < n + m; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
