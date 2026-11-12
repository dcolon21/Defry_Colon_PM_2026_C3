
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char nombre[100];
    char *texto;
    size_t capacidad = 100;
    size_t longitud = 0;
    int caracter;

    printf("Ingrese el nombre del archivo: ");
    scanf("%99s", nombre);

    archivo = fopen(nombre, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    texto = (char *)malloc(capacidad);

    if (texto == NULL) {
        printf("Error al reservar memoria.\n");
        fclose(archivo);
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {

        if (longitud + 1 >= capacidad) {
            size_t nuevaCapacidad;
            char *temporal;

            if (capacidad > ((size_t)-1) / 2) {
                printf("Archivo demasiado grande.\n");
                free(texto);
                fclose(archivo);
                return 1;
            }

            nuevaCapacidad = capacidad * 2;

            temporal = (char *)realloc(texto, nuevaCapacidad);

            if (temporal == NULL) {
                printf("Error al ampliar memoria.\n");
                free(texto);
                fclose(archivo);
                return 1;
            }

            texto = temporal;
            capacidad = nuevaCapacidad;
        }

        texto[longitud] = (char)caracter;
        longitud++;
    }

    texto[longitud] = '\0';

    printf("\nCONTENIDO DEL ARCHIVO:\n");
    printf("%s\n", texto);

    printf("\nCaracteres leidos: %zu\n", longitud);

    free(texto);
    fclose(archivo);

    return 0;
}

