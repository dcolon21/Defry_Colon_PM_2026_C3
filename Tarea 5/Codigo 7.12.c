
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarMayusculas(char cad[])
{
    int cantidad = 0;

    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (isupper((unsigned char)cad[i]))
            cantidad++;
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

        if (contarMayusculas(arc[i]) >
            contarMayusculas(arc[mayor]))
        {
            mayor = i;
        }
    }

    printf("\nCadena con mas mayusculas: %s\n", arc[mayor]);
    printf("Cantidad: %d\n", contarMayusculas(arc[mayor]));

    return 0;
}

}

