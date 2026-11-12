
#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char cadena[51];
    char ventana[51] = {0};
    int c, veces = 0;
    size_t n, longitud = 0;

    archivo = fopen("arc2.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese la cadena a buscar: ");
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = '\0';
    n = strlen(cadena);

    if (n == 0) {
        printf("Cadena vacia.\n");
        fclose(archivo);
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        if (longitud < n) {
            ventana[longitud++] = (char)c;
        } else {
            memmove(ventana, ventana + 1, n - 1);
            ventana[n - 1] = (char)c;
        }

        if (longitud == n &&
            memcmp(ventana, cadena, n) == 0) {
            veces++;
        }
    }

    printf("Apariciones: %d\n", veces);

    fclose(archivo);
    return 0;
}

