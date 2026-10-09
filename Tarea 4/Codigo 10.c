
#include <stdio.h>

void mezclar(int a[], int n, int b[], int m, int c[])
{
    int i = 0;
    int j = m - 1;
    int k = 0;

    while (i < n && j >= 0)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j--];
    }

    while (i < n)
        c[k++] = a[i++];

    while (j >= 0)
        c[k++] = b[j--];
}

int main()
{
    int a[100], b[100], c[200];
    int n, m;

    printf("Cantidad del primer arreglo: ");
    scanf("%d", &n);

    printf("Cantidad del segundo arreglo: ");
    scanf("%d", &m);

    if (n < 1 || n > 100 || m < 1 || m > 100)
        return 1;

    printf("Primer arreglo ascendente:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Segundo arreglo descendente:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return 1;

    for (int i = 1; i < m; i++)
        if (b[i] > b[i - 1])
            return 1;

    mezclar(a, n, b, m, c);

    printf("\nArreglo combinado ascendente:\n");

    for (int i = 0; i < n + m; i++)
        printf("%d ", c[i]);

    return 0;
}
