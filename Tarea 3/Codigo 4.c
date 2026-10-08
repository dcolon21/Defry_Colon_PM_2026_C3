
#include <stdio.h>

double calcularInversion(int meses, double capital, double tasa)
{
    for (int i = 1; i <= meses; i++)
    {
        capital += capital * (tasa / 100.0);
    }

    return capital;
}

int main(void)
{
    int meses;
    double capital, tasa;

    printf("Capital inicial: ");
    scanf("%lf", &capital);

    printf("Tasa mensual en porcentaje: ");
    scanf("%lf", &tasa);

    printf("Cantidad de meses: ");
    scanf("%d", &meses);

    if (meses < 0 || capital < 0 || tasa < 0)
    {
        printf("Datos invalidos.\n");
        return 1;
    }

    printf("Capital final: %.2f\n",
           calcularInversion(meses, capital, tasa));

    return 0;
}

