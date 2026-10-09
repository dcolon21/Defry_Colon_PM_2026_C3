
#include <stdio.h>

int buscar(int v[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return i;
    return -1;
}

void insertar(int v[], int *n, int x)
{
    if (*n == 100 || buscar(v, *n, x) != -1)
    {
        printf("No se puede insertar.\n");
        return;
    }

    int i = *n - 1;

    while (i >= 0 && v[i] > x)
    {
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = x;
    (*n)++;
}

void eliminar(int v[], int *n, int x)
{
    int pos = buscar(v, *n, x);

    if (pos == -1)
    {
        printf("Elemento no encontrado.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
        v[i] = v[i + 1];

    (*n)--;
}

int main(void)
{
    int v[100], n = 0, opcion, x;

    do
    {
        printf("\n1. Insertar");
        printf("\n2. Eliminar");
        printf("\n3. Mostrar");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        if (opcion == 1 || opcion == 2)
        {
            printf("Numero: ");
            scanf("%d", &x);

            if (opcion == 1)
                insertar(v, &n, x);
            else
                eliminar(v, &n, x);
        }

        if (opcion == 3)
        {
            printf("Arreglo ordenado: ");
            for (int i = 0; i < n; i++)
                printf("%d ", v[i]);
            printf("\n");
        }

    } while (opcion != 0);

    return 0;
}
