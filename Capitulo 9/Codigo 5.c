
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *entrada, *salida;
    char lineas[100][200];
    int total = 0, i;

    entrada = fopen("arc.txt", "r");

    if (entrada == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (total < 100 &&
           fgets(lineas[total], 200, entrada) != NULL) {
        total++;
    }

    fclose(entrada);

    salida = fopen("arc_invertido.txt", "w");

    if (salida == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    for (i = total - 1; i >= 0; i--) {
        fputs(lineas[i], salida);

        if (i > 0 &&
            strchr(lineas[i], '\n') == NULL) {
            fputc('\n', salida);
        }
    }

    fclose(salida);

    printf("Archivo invertido creado.\n");

    return 0;
}

