
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    int c;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    archivo = fopen("arc.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        c = tolower((unsigned char)c);

        switch (c) {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }

    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);

    fclose(archivo);
    return 0;
}

