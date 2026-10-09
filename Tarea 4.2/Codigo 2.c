
#include <stdio.h>

int main()
{
    double ventas[5][12];
    double mensual[12] = {0};
    double anual = 0;
    double mayorJulio = 0;

    int departamentoJulio = 0;
    int mesMayor = 0, mesMenor = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("Departamento %d, mes %d: ", i + 1, j + 1);
            scanf("%lf", &ventas[i][j]);

            mensual[j] += ventas[i][j];

            if (j == 6 &&
                (departamentoJulio == 0 ||
                 ventas[i][j] > mayorJulio))
            {
                mayorJulio = ventas[i][j];
                departamentoJulio = i + 1;
            }
        }
    }

    for (int j = 0; j < 12; j++)
    {
        printf("Mes %d: %.2f\n", j + 1, mensual[j]);
        anual += mensual[j];

        if (ventas[2][j] > ventas[2][mesMayor])
            mesMayor = j;

        if (ventas[2][j] < ventas[2][mesMenor])
            mesMenor = j;
    }

    printf("\nTotal anual: %.2f\n", anual);
    printf("Mayor venta en julio: departamento %d\n",
           departamentoJulio);
    printf("Departamento 3, mes mayor: %d\n", mesMayor + 1);
    printf("Departamento 3, mes menor: %d\n", mesMenor + 1);

    return 0;
}

