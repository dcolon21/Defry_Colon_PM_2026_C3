
#include <stdio.h>

int main()
{
    static long long sec[10][12][5];
    long long total[10] = {0};
    long long mesUltimo[12] = {0};

    for (int c = 0; c < 10; c++)
    {
        for (int a = 0; a < 5; a++)
        {
            for (int m = 0; m < 12; m++)
            {
                printf("Centro %d, anio %d, mes %d: ",
                       c + 1, a + 1, m + 1);

                scanf("%lld", &sec[c][m][a]);

                total[c] += sec[c][m][a];

                if (a == 4)
                    mesUltimo[m] += sec[c][m][a];
            }
        }
    }

    int mayor = 0, menor = 0;
    int mesMayor = 0, mesMenor = 0;

    for (int c = 0; c < 10; c++)
    {
        printf("Centro %d: %lld visitantes\n",
               c + 1, total[c]);

        if (total[c] > total[mayor])
            mayor = c;

        if (total[c] < total[menor])
            menor = c;
    }

    for (int m = 0; m < 12; m++)
    {
        if (mesUltimo[m] > mesUltimo[mesMayor])
            mesMayor = m;

        if (mesUltimo[m] < mesUltimo[mesMenor])
            mesMenor = m;
    }

    printf("\nCentro mas visitado: %d\n", mayor + 1);
    printf("Centro menos visitado: %d\n", menor + 1);
    printf("Mes de mayor asistencia: %d\n", mesMayor + 1);
    printf("Mes de menor asistencia: %d\n", mesMenor + 1);

    return 0;
}

