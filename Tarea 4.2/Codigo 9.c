
#include <stdio.h>

int col[8];
int usadas[8];
int diag1[15];
int diag2[15];
int soluciones = 0;

void resolver(int fila)
{
    if (fila == 8)
    {
        soluciones++;

        if (soluciones == 1)
        {
            printf("Una solucion:\n");

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (col[i] == j)
                        printf("R ");
                    else
                        printf(". ");
                }

                printf("\n");
            }
        }

        return;
    }

    for (int j = 0; j < 8; j++)
    {
        int d1 = fila - j + 7;
        int d2 = fila + j;

        if (!usadas[j] && !diag1[d1] && !diag2[d2])
        {
            col[fila] = j;
            usadas[j] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;

            resolver(fila + 1);

            usadas[j] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }
}

int main()
{
    resolver(0);

    printf("\nTotal de soluciones: %d\n", soluciones);

    return 0;
}

