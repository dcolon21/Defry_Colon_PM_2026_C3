
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    float notas[3];
} Alumno;

int comparar(const void *a, const void *b) {
    const Alumno *x = (const Alumno *)a;
    const Alumno *y = (const Alumno *)b;

    return (x->matricula > y->matricula) -
           (x->matricula < y->matricula);
}

int main() {
    FILE *entrada, *salida;
    Alumno alumnos[100];
    int total = 0, i;

    entrada = fopen("arc.dat", "r");

    if (entrada == NULL) {
        printf("Error al abrir arc.dat\n");
        return 1;
    }

    while (total < 100 &&
           fscanf(entrada, "%d %f %f %f",
                  &alumnos[total].matricula,
                  &alumnos[total].notas[0],
                  &alumnos[total].notas[1],
                  &alumnos[total].notas[2]) == 4) {
        total++;
    }

    fclose(entrada);

    qsort(alumnos, total, sizeof(Alumno), comparar);

    salida = fopen("arc1.dat", "w");

    if (salida == NULL)
        return 1;

    for (i = 0; i < total; i++) {
        fprintf(salida, "%d %.1f %.1f %.1f\n",
                alumnos[i].matricula,
                alumnos[i].notas[0],
                alumnos[i].notas[1],
                alumnos[i].notas[2]);
    }

    fclose(salida);

    printf("Alumnos ordenados: %d\n", total);

    return 0;
}

