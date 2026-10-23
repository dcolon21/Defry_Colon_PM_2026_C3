
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cad[30];
    int valido = 1;

    printf("Ingrese numero telefonico de 10 digitos: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';

    if (strlen(cad) != 10)
        valido = 0;

    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)cad[i]))
            valido = 0;
    }

    if (!valido)
    {
        printf("Numero invalido.\n");
        return 1;
    }

    printf("Nueva cadena: (%.2s)-%c-%s\n",
           cad, cad[2], cad + 3);

    return 0;
}

