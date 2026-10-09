
#include <stdio.h>

int main()
{
    int n;

    printf("Orden de la matriz (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
                printf("1 ");
            else
                printf("0 ");
        }

        printf("\n");
    }

    return 0;
}

