
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    int c, dentro = 0, palabras = 0;

    archivo = fopen("arc.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        if (isspace((unsigned char)c)) {
            dentro = 0;
        } else if (dentro == 0) {
            palabras++;
            dentro = 1;
        }
    }

    printf("Total de palabras: %d\n", palabras);

    fclose(archivo);
    return 0;
}

