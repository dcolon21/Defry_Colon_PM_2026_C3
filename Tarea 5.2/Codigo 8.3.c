
#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero;
    char nombre[80];
    char departamento[50];
    char puesto[50];
    char grado[50];
    char nacionalidad[50];
    double salario[12];
} Profesor;

void leer(char s[], int tam)
{
    fgets(s, tam, stdin);
    s[strcspn(s, "\n")] = '\0';
}

double ingreso(Profesor p)
{
    double total = 0;

    for (int i = 0; i < 12; i++)
        total += p.salario[i];

    return total;
}

int main()
{
    static Profesor p[200];

    char departamentos[4][50] = {
        "Economia", "Derecho",
        "Computacion", "Administracion"
    };

    double totalDepto[4] = {0};
    double total = 0, extranjeros = 0;
    int n, mayor = 0, deptoMayor = 0;

    printf("Cantidad de profesores: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 200)
        return 1;

    for (int i = 0; i < n; i++)
    {
        int d;

        printf("\nProfesor %d\n", i + 1);

        printf("Numero de empleado: ");
        scanf("%d", &p[i].numero);
        getchar();

        printf("Nombre: ");
        leer(p[i].nombre, 80);

        printf("Departamento (1-Economia, 2-Derecho,");
        printf(" 3-Computacion, 4-Administracion): ");
        scanf("%d", &d);
        getchar();

        if (d < 1 || d > 4)
            return 1;

        strcpy(p[i].departamento, departamentos[d - 1]);

        printf("Puesto: ");
        leer(p[i].puesto, 50);

        printf("Grado academico: ");
        leer(p[i].grado, 50);

        printf("Nacionalidad: ");
        leer(p[i].nacionalidad, 50);

        for (int j = 0; j < 12; j++)
        {
            printf("Salario mes %d: ", j + 1);
            scanf("%lf", &p[i].salario[j]);
        }
        getchar();

        double t = ingreso(p[i]);

        total += t;
        totalDepto[d - 1] += t;

        if (strcmp(p[i].nacionalidad, "Colombia") != 0)
            extranjeros += t;

        if (ingreso(p[i]) > ingreso(p[mayor]))
            mayor = i;
    }

    for (int d = 1; d < 4; d++)
        if (totalDepto[d] > totalDepto[deptoMayor])
            deptoMayor = d;

    printf("\nProfesor con mayor ingreso:\n");
    printf("Nombre: %s\n", p[mayor].nombre);
    printf("Departamento: %s\n", p[mayor].departamento);
    printf("Nacionalidad: %s\n", p[mayor].nacionalidad);
    printf("Ingreso: %.2f\n", ingreso(p[mayor]));

    printf("\nPago a extranjeros: %.2f\n", extranjeros);

    if (total > 0)
        printf("Porcentaje: %.2f%%\n",
               extranjeros * 100.0 / total);

    printf("Departamento con mayores egresos: %s\n",
           departamentos[deptoMayor]);

    return 0;
}

