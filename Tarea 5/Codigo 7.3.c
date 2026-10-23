
#include <stdio.h>
#include <string.h>

int main()
{
    char cad[31];
    int longitud;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';

    longitud = strlen(cad);

    for (int i = longitud; i < 30; i++)
    {
        cad[i] = '-';
    }

    cad[30] = '\0';

    printf("Cadena completa: %s\n", cad);

    return 0;
}

