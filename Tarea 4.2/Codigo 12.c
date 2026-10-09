
#include <stdio.h>

#define E 7

int main()
{
    static long long fut[E][12][5];
    long long total[E] = {0};
    long long ultimo[E] = {0};

    int orden[E];
    int mayor = 0, menor = 0;

    for (int e = 0; e < E; e++)
    {
        orden[e] = e;

        for (int a = 0; a < 5; a++)
        {
            for (int m = 0; m < 12; m++)
            {
                printf("Estadio %d, anio %d, mes %d: ",
                       e + 1, a + 1, m + 1);

                scanf("%lld", &fut[e][m][a]);

                total[e] += fut[e][m][a];

                if (a == 4)
                    ultimo[e] += fut[e][m][a];
            }
        }
    }

    for (int e = 1; e < E; e++)
    {
        if (total[e] > total[mayor])
            mayor = e;

        if (total[e] < total[menor])
            menor = e;
    }

    for (int i = 0; i < E - 1; i++)
    {
        for (int j = i + 1; j < E; j++)
        {
            if (ultimo[orden[j]] > ultimo[orden[i]])
            {
                int aux = orden[i];
                orden[i] = orden[j];
                orden[j] = aux;
            }
        }
    }

    printf("\nAsistencia del ultimo anio:\n");

    for (int i = 0; i < E; i++)
    {
        printf("Estadio %d: %lld\n",
               orden[i] + 1, ultimo[orden[i]]);
    }

    printf("\nMayor asistencia total: estadio %d\n",
           mayor + 1);

    printf("Menor asistencia total: estadio %d\n",
           menor + 1);

    for (int e = 0; e < E; e++)
    {
        int mejor = 0;

        for (int m = 1; m < 12; m++)
        {
            if (fut[e][m][4] > fut[e][mejor][4])
                mejor = m;
        }

        printf("Estadio %d, mejor mes del ultimo anio: %d\n",
               e + 1, mejor + 1);
    }

    return 0;
}

