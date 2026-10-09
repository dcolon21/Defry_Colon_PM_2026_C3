
#include <stdio.h>

int tablero[8][8];

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dentro(int x, int y)
{
    return x >= 0 && x < 8 &&
           y >= 0 && y < 8 &&
           tablero[x][y] == 0;
}

int grado(int x, int y)
{
    int cantidad = 0;

    for (int k = 0; k < 8; k++)
    {
        if (dentro(x + dx[k], y + dy[k]))
            cantidad++;
    }

    return cantidad;
}

int caballo(int x, int y, int paso)
{
    tablero[x][y] = paso;

    if (paso == 64)
        return 1;

    int orden[8], cantidad = 0;

    for (int k = 0; k < 8; k++)
    {
        if (dentro(x + dx[k], y + dy[k]))
            orden[cantidad++] = k;
    }

    for (int i = 0; i < cantidad; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            int a = orden[i];
            int b = orden[j];

            if (grado(x + dx[b], y + dy[b]) <
                grado(x + dx[a], y + dy[a]))
            {
                int aux = orden[i];
                orden[i] = orden[j];
                orden[j] = aux;
            }
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        int k = orden[i];

        if (caballo(x + dx[k], y + dy[k], paso + 1))
            return 1;
    }

    tablero[x][y] = 0;
    return 0;
}

int main()
{
    int x, y;

    printf("Fila inicial (1-8): ");
    scanf("%d", &x);

    printf("Columna inicial (1-8): ");
    scanf("%d", &y);

    if (x < 1 || x > 8 || y < 1 || y > 8)
        return 1;

    if (caballo(x - 1, y - 1, 1))
    {
        printf("\nRecorrido del caballo:\n");

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                printf("%2d ", tablero[i][j]);

            printf("\n");
        }
    }
    else
    {
        printf("No se encontro un recorrido.\n");
    }

    return 0;
}

