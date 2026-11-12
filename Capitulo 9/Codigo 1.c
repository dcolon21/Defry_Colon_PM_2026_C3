
#include <stdio.h>

int main() {
    FILE *archivo;
    int c, longitud = 0, mayor = 0;

    archivo = fopen("arc1.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        if (c == '\n') {
            if (longitud > mayor)
                mayor = longitud;
            longitud = 0;
        } else if (c != '\r') {
            longitud++;
        }
    }

    if (longitud > mayor)
        mayor = longitud;

    printf("Longitud maxima: %d\n", mayor);

    fclose(archivo);
    return 0;
}

