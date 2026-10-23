
#include <stdio.h>
#include <string.h>

typedef struct
{
    char calle[80];
    int codigoPostal;
    char colonia[50];
    char ciudad[50];
    char telefono[25];
} Domicilio;

typedef struct
{
    char materia[50];
    double promedio;
} Calificacion;

typedef struct
{
    char nivel[30];
    int grado;
    char salon[20];
    Calificacion calificaciones[7];
} Estudios;

typedef struct
{
    int matricula;
    char nombre[80];
    Domicilio domicilio;
    Estudios estudios;
} Alumno;

void leer(char s[], int tam)
{
    fgets(s, tam, stdin);
    s[strcspn(s, "\n")] = '\0';
}

double promedio(Alumno a)
{
    double suma = 0;

    for (int i = 0; i < 7; i++)
        suma += a.estudios.calificaciones[i].promedio;

    return suma / 7.0;
}

int buscar(Alumno a[], int n, int matricula)
{
    for (int i = 0; i < n; i++)
        if (a[i].matricula == matricula)
            return i;

    return -1;
}

int pertenece(Alumno a, char nivel[],
              int grado, char salon[])
{
    return strcmp(a.estudios.nivel, nivel) == 0 &&
           a.estudios.grado == grado &&
           strcmp(a.estudios.salon, salon) == 0;
}

int main()
{
    static Alumno a[1000];
    int n, opcion, matricula, pos;
    int grado;
    char nivel[30], salon[20];

    printf("Cantidad de alumnos: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 1000)
        return 1;

    for (int i = 0; i < n; i++)
    {
        printf("\nALUMNO %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        getchar();

        if (buscar(a, i, a[i].matricula) != -1)
        {
            printf("Matricula repetida.\n");
            return 1;
        }

        printf("Nombre: ");
        leer(a[i].nombre, 80);

        printf("Calle y numero: ");
        leer(a[i].domicilio.calle, 80);

        printf("Codigo postal: ");
        scanf("%d", &a[i].domicilio.codigoPostal);
        getchar();

        printf("Colonia: ");
        leer(a[i].domicilio.colonia, 50);

        printf("Ciudad: ");
        leer(a[i].domicilio.ciudad, 50);

        printf("Telefono: ");
        leer(a[i].domicilio.telefono, 25);

        printf("Nivel (Primaria/Secundaria/Preparatoria): ");
        leer(a[i].estudios.nivel, 30);

        printf("Grado: ");
        scanf("%d", &a[i].estudios.grado);
        getchar();

        printf("Salon: ");
        leer(a[i].estudios.salon, 20);

        for (int j = 0; j < 7; j++)
        {
            printf("Materia %d: ", j + 1);
            leer(a[i].estudios.calificaciones[j].materia, 50);

            printf("Promedio de la materia: ");
            scanf("%lf",
                  &a[i].estudios.calificaciones[j].promedio);
            getchar();
        }
    }

    do
    {
        printf("\n1. Promedio por matricula");
        printf("\n2. Listado de grupo");
        printf("\n3. Mejor alumno de grupo");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 0)
            break;

        if (opcion == 1)
        {
            printf("Matricula: ");
            scanf("%d", &matricula);
            getchar();

            pos = buscar(a, n, matricula);

            if (pos == -1)
                printf("Alumno no encontrado.\n");
            else
                printf("%s - Promedio: %.2f\n",
                       a[pos].nombre, promedio(a[pos]));
        }
        else if (opcion == 2 || opcion == 3)
        {
            printf("Nivel: ");
            leer(nivel, 30);

            printf("Grado: ");
            scanf("%d", &grado);
            getchar();

            printf("Salon: ");
            leer(salon, 20);

            int mejor = -1;
            int encontrados = 0;

            for (int i = 0; i < n; i++)
            {
                if (pertenece(a[i], nivel, grado, salon))
                {
                    encontrados++;

                    if (opcion == 2)
                    {
                        printf("%d - %s - %.2f\n",
                               a[i].matricula,
                               a[i].nombre,
                               promedio(a[i]));
                    }

                    if (mejor == -1 ||
                        promedio(a[i]) > promedio(a[mejor]))
                    {
                        mejor = i;
                    }
                }
            }

            if (encontrados == 0)
            {
                printf("No hay alumnos en ese grupo.\n");
            }
            else if (opcion == 3)
            {
                printf("\nMejor alumno:\n");
                printf("Matricula: %d\n", a[mejor].matricula);
                printf("Nombre: %s\n", a[mejor].nombre);
                printf("Promedio: %.2f\n", promedio(a[mejor]));
            }
        }

    } while (1);

    return 0;
}

