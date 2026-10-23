
#include <stdio.h>
#include <string.h>

#define N 20

typedef struct
{
    char nombre[50];
    int pj, pg, pe, pp;
    int gf, gc, dg, puntos;
} Equipo;

int buscar(Equipo e[], char nombre[])
{
    for (int i = 0; i < N; i++)
        if (strcmp(e[i].nombre, nombre) == 0)
            return i;

    return -1;
}

void actualizar(Equipo *a, Equipo *b, int ga, int gb)
{
    a->pj++;
    b->pj++;

    a->gf += ga;
    a->gc += gb;

    b->gf += gb;
    b->gc += ga;

    if (ga > gb)
    {
        a->pg++;
        b->pp++;
        a->puntos += 3;
    }
    else if (ga < gb)
    {
        b->pg++;
        a->pp++;
        b->puntos += 3;
    }
    else
    {
        a->pe++;
        b->pe++;
        a->puntos++;
        b->puntos++;
    }

    a->dg = a->gf - a->gc;
    b->dg = b->gf - b->gc;
}

void tabla(Equipo e[])
{
    Equipo copia[N], aux;

    for (int i = 0; i < N; i++)
        copia[i] = e[i];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (copia[j].puntos > copia[i].puntos ||
               (copia[j].puntos == copia[i].puntos &&
                copia[j].dg > copia[i].dg))
            {
                aux = copia[i];
                copia[i] = copia[j];
                copia[j] = aux;
            }
        }
    }

    printf("\nEQUIPO              PJ PG PE PP GF GC DG PTS\n");

    for (int i = 0; i < N; i++)
    {
        printf("%-19s %2d %2d %2d %2d %2d %2d %3d %3d\n",
               copia[i].nombre, copia[i].pj,
               copia[i].pg, copia[i].pe, copia[i].pp,
               copia[i].gf, copia[i].gc,
               copia[i].dg, copia[i].puntos);
    }
}

int main()
{
    Equipo e[N] = {0};
    char nombre1[50], nombre2[50];
    int ga, gb, partidos, x, y;
    char continuar;

    printf("Ingrese los nombres de los 20 equipos:\n");

    for (int i = 0; i < N; i++)
    {
        printf("Equipo %d: ", i + 1);
        scanf(" %49[^\n]", e[i].nombre);
    }

    do
    {
        printf("\nCantidad de partidos de la fecha: ");
        scanf("%d", &partidos);

        if (partidos < 0 || partidos > 10)
        {
            printf("Cantidad invalida.\n");
            continue;
        }

        for (int i = 0; i < partidos; i++)
        {
            printf("\nEquipo local: ");
            scanf(" %49[^\n]", nombre1);

            printf("Equipo visitante: ");
            scanf(" %49[^\n]", nombre2);

            printf("Goles local y visitante: ");
            scanf("%d %d", &ga, &gb);

            x = buscar(e, nombre1);
            y = buscar(e, nombre2);

            if (x == -1 || y == -1 || x == y ||
                ga < 0 || gb < 0)
            {
                printf("Datos incorrectos.\n");
                i--;
                continue;
            }

            actualizar(&e[x], &e[y], ga, gb);
        }

        tabla(e);

        printf("\nOtra fecha? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}

