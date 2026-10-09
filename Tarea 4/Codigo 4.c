
#include <stdio.h>

int buscar(int v[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return i;

    return -1;
}

void mostrar(int v[], int n)
{
    printf("\nArreglo: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void)
{
    int v[100], n = 0, opcion, ele, pos;

    do
    {
        printf("\n1. Insertar");
        printf("\n2. Eliminar");
        printf("\n3. Mostrar");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                printf("Numero a insertar: ");
                scanf("%d", &ele);

                if (n == 100)
                    printf("Arreglo lleno.\n");
                else if (buscar(v, n, ele) != -1)
                    printf("El numero ya existe.\n");
                else
                {
                    v[n] = ele;
                    n++;
                    printf("Insertado.\n");
                }
                break;

            case 2:
                printf("Numero a eliminar: ");
                scanf("%d", &ele);

                pos = buscar(v, n, ele);

                if (pos == -1)
                    printf("Numero no encontrado.\n");
                else
                {
                    for (int i = pos; i < n - 1; i++)
                        v[i] = v[i + 1];

                    n--;
                    printf("Eliminado.\n");
                }
                break;

            case 3:
                mostrar(v, n);
                break;
        }

    } while (opcion != 0);

    return 0;
}

