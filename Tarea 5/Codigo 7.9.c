
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cad[50];
    int fin;

    printf("Ingrese una frase: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';
    fin = strlen(cad) - 1;

    printf("Frase invertida:\n");

    while (fin >= 0)
    {
        while (fin >= 0 &&
               isspace((unsigned char)cad[fin]))
            fin--;

        if (fin < 0)
            break;

        int inicio = fin;

        while (inicio >= 0 &&
               !isspace((unsigned char)cad[inicio]))
            inicio--;

        for (int i = inicio + 1; i <= fin; i++)
            putchar(cad[i]);

        putchar(' ');
        fin = inicio - 1;
    }

    printf("\n");
    return 0;
}

