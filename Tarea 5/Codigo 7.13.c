
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarPalabras(char cad[])
{
    int cantidad = 0;
    int dentro = 0;

    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (isspace((unsigned char)cad[i]))
        {
            dentro = 0;
        }
        else if (!dentro)
        {
            cantidad++;
            dentro = 1;
        }
    }

    return cantidad;
}

int main()
{
    char arc[10][50];

    for (int i = 0; i < 10; i++)
    {
        printf("Cadena %d: ", i + 1);
        fgets(arc[i], sizeof(arc[i]), stdin);

        arc[i][strcspn(arc[i], "\n")] = '\0';
    }

    printf("\nCantidad de palabras:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Cadena %d: %d palabras\n",
               i + 1, contarPalabras(arc[i]));
    }

    return 0;
}

