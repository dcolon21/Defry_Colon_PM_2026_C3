
#include <stdio.h>
#include <string.h>

typedef struct
{
    int clave;
    char nombre[80];
    int existencia;
} Producto;

int buscar(Producto p[], int n, int clave)
{
    for (int i = 0; i < n; i++)
        if (p[i].clave == clave)
            return i;

    return -1;
}

int main()
{
    Producto p[100];
    int n, clave, cantidad, pos;
    char operacion;

    printf("Cantidad de productos: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        printf("\nProducto %d\n", i + 1);

        printf("Clave: ");
        scanf("%d", &p[i].clave);

        if (buscar(p, i, p[i].clave) != -1)
        {
            printf("Clave repetida.\n");
            return 1;
        }

        printf("Nombre: ");
        scanf(" %79[^\n]", p[i].nombre);

        printf("Existencia inicial: ");
        scanf("%d", &p[i].existencia);

        if (p[i].existencia < 0)
            return 1;
    }

    do
    {
        printf("\nC-Compra, V-Venta, 0-Salir: ");
        scanf(" %c", &operacion);

        if (operacion == '0')
            break;

        if (operacion != 'C' && operacion != 'V' &&
            operacion != 'c' && operacion != 'v')
        {
            printf("Operacion invalida.\n");
            continue;
        }

        printf("Clave del producto: ");
        scanf("%d", &clave);

        printf("Cantidad: ");
        scanf("%d", &cantidad);

        pos = buscar(p, n, clave);

        if (pos == -1 || cantidad <= 0)
        {
            printf("Datos incorrectos.\n");
            continue;
        }

        if (operacion == 'C' || operacion == 'c')
        {
            p[pos].existencia += cantidad;
            printf("Compra registrada.\n");
        }
        else
        {
            if (cantidad > p[pos].existencia)
            {
                printf("Existencia insuficiente.\n");
                continue;
            }

            p[pos].existencia -= cantidad;
            printf("Venta registrada.\n");
        }

        printf("Existencia actual: %d\n",
               p[pos].existencia);

    } while (1);

    printf("\nINVENTARIO FINAL\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s - %d unidades\n",
               p[i].clave,
               p[i].nombre,
               p[i].existencia);
    }

    return 0;
}

