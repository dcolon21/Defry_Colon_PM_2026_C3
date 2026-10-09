
#include <stdio.h>

void analizar(double a[12])
{
    double suma = 0, mayor = a[0];
    int mesMayor = 0, superiores = 0;

    for (int i = 0; i < 12; i++)
    {
        suma += a[i];

        if (a[i] > mayor)
        {
            mayor = a[i];
            mesMayor = i;
        }
    }

    double promedio = suma / 12;

    for (int i = 0; i < 12; i++)
    {
        if (a[i] > promedio)
            superiores++;
    }

    printf("\nPromedio mensual: %.2f", promedio);
    printf("\nMeses superiores al promedio: %d", superiores);
    printf("\nMes de mayor cosecha: %d", mesMayor + 1);
    printf("\nMayor cosecha: %.2f toneladas\n", mayor);
}

int main()
{
    double a[12];

    for (int i = 0; i < 12; i++)
    {
        printf("Toneladas del mes %d: ", i + 1);
        scanf("%lf", &a[i]);
    }

    analizar(a);

    return 0;
}
