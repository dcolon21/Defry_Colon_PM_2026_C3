
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarVocales(char cad[])
{
    int cantidad = 0;

    for (int i = 0; cad[i] != '\0'; i++)
    {
        char c = tolower((unsigned char)cad[i]);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u')
        {
            cantidad++;
        }
    }

    return cantidad;
}

int main()
{
    char arc[10][50];
    int mayor = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Cadena %d: ", i + 1);
        fgets(arc[i], sizeof(arc[i]), stdin);

        arc[i][strcspn(arc[i], "\n")] = '\0';

        if (contarVocales(arc[i]) >
            contarVocales(arc[mayor]))
        {
            mayor = i;
        }
    }

    printf("\nCadena con mas vocales: %s\n", arc[mayor]);
    printf("Cantidad: %d\n", contarVocales(arc[mayor]));

    return 0;
}

