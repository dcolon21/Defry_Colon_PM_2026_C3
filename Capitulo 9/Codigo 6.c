
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    int actual, anterior = 0;
    int errores = 0;

    archivo = fopen("doc.dat", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((actual = fgetc(archivo)) != EOF) {
        int a = tolower((unsigned char)anterior);
        int b = tolower((unsigned char)actual);

        if ((a == 'n' && (b == 'b' || b == 'p')) ||
            (a == 'm' && b == 'v')) {

            printf("Error encontrado: %c%c\n",
                   anterior, actual);
            errores++;
        }

        anterior = actual;
    }

    printf("Total de errores: %d\n", errores);

    fclose(archivo);
    return 0;
}
