
#include <stdio.h>
#include <string.h>

typedef struct
{
    char calle[80];
    char colonia[50];
    char codigoPostal[20];
    char ciudad[50];
    char telefono[25];
} Domicilio;

typedef struct
{
    int numero;
    char nombre[80];
    char departamento[50];
    Domicilio domicilio;
    double salario;
} Empleado;

void leer(char s[], int tam)
{
    fgets(s, tam, stdin);
    s[strcspn(s, "\n")] = '\0';
}

int buscar(Empleado e[], int n, int numero)
{
    for (int i = 0; i < n; i++)
        if (e[i].numero == numero)
            return i;

    return -1;
}

int main()
{
    Empleado e[100];
    int n = 0, opcion, numero, pos;
    char departamento[50];

    do
    {
        printf("\n1. Alta");
        printf("\n2. Baja");
        printf("\n3. Listado por departamento");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
            case 1:
            {
                if (n == 100)
                {
                    printf("Capacidad completa.\n");
                    break;
                }

                printf("Numero de empleado: ");
                scanf("%d", &numero);
                getchar();

                if (buscar(e, n, numero) != -1)
                {
                    printf("Empleado existente.\n");
                    break;
                }

                Empleado nuevo = {0};
                nuevo.numero = numero;

                printf("Nombre: ");
                leer(nuevo.nombre, 80);

                printf("Departamento: ");
                leer(nuevo.departamento, 50);

                printf("Calle y numero: ");
                leer(nuevo.domicilio.calle, 80);

                printf("Colonia: ");
                leer(nuevo.domicilio.colonia, 50);

                printf("Codigo postal: ");
                leer(nuevo.domicilio.codigoPostal, 20);

                printf("Ciudad: ");
                leer(nuevo.domicilio.ciudad, 50);

                printf("Telefono: ");
                leer(nuevo.domicilio.telefono, 25);

                printf("Salario mensual: ");
                scanf("%lf", &nuevo.salario);

                if (nuevo.salario < 0)
                {
                    printf("Salario invalido.\n");
                    break;
                }

                int i = n - 1;

                while (i >= 0 && e[i].numero > numero)
                {
                    e[i + 1] = e[i];
                    i--;
                }

                e[i + 1] = nuevo;
                n++;

                printf("Empleado agregado.\n");
                break;
            }

            case 2:
                printf("Numero de empleado: ");
                scanf("%d", &numero);

                pos = buscar(e, n, numero);

                if (pos == -1)
                {
                    printf("No encontrado.\n");
                    break;
                }

                for (int i = pos; i < n - 1; i++)
                    e[i] = e[i + 1];

                n--;
                printf("Empleado eliminado.\n");
                break;

            case 3:
                printf("Departamento: ");
                leer(departamento, 50);

                printf("\nLISTADO DE EMPLEADOS\n");

                for (int i = 0; i < n; i++)
                {
                    if (strcmp(e[i].departamento,
                               departamento) == 0)
                    {
                        printf("%d - %s - %.2f\n",
                               e[i].numero,
                               e[i].nombre,
                               e[i].salario);
                    }
                }
                break;
        }

    } while (opcion != 0);

    return 0;
}

