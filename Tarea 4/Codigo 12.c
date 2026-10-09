
#include <stdio.h>

int palindromo(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            return 0;
    }

    return 1;
}

int main()
{
    int a[100], n;

    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 1;

    printf("Ingrese los elementos:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (palindromo(a, n))
        printf("\nEs palindromo.\n");
    else
        printf("\nNo es palindromo.\n");

    return 0;
}
