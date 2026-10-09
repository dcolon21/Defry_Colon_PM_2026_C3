
#include <stdio.h>

void estadisticas(double a[], int n)
{
    double suma = 0;
    int aprobados = 0, altos = 0;

    for (int i = 0; i < n; i++)
    {
        suma += a[i];

        if (a[i] > 1300)
            aprobados++;

        if (a[i] >= 1500)
            altos++;
    }

    printf("\nPromedio: %.2f", suma / n);
    printf("\nPorcentaje mayor a 1300: %.2f%%",
           100.0 * aprobados / n);
    printf("\nAlumnos con 1500 o mas: %d\n", altos);
}

int main()
{
    double a[100];
    int n;

    printf("Cantidad de alumnos (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        printf("Puntuacion del alumno %d: ", i + 1);
        scanf("%lf", &a[i]);
    }

    estadisticas(a, n);

    return 0;
}
