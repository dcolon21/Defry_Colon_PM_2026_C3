
#include <stdio.h>

int eliminarRepetidos(int vec[], int n)
{
    int j = 1;

    for (int i = 1; i < n; i++)
    {
        if (vec[i] != vec[j - 1])
        {
            vec[j] = vec[i];
            j++;
        }
    }

    return j;
}

int main(void)
{
    int vec[100], n;

    printf("Cantidad de elementos: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Ingrese los numeros ordenados:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);

        if (i > 0 && vec[i] < vec[i - 1])
        {
            printf("El arreglo debe estar ordenado.\n");
            return 1;
        }
    }

    n = eliminarRepetidos(vec, n);

    printf("\nArreglo sin repetidos:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);

    printf("\n");
    return 0;
}

