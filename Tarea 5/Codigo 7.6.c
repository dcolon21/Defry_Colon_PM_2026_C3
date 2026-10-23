
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cad[21];
    char mayor[21] = "";
    char respuesta;
    int longitudMayor = -1;

    do
    {
        printf("Desea ingresar una cadena? (S/N): ");
        scanf(" %c", &respuesta);

        while (getchar() != '\n');

        if (toupper((unsigned char)respuesta) != 'S')
            break;

        printf("Ingrese la cadena: ");
        fgets(cad, sizeof(cad), stdin);

        cad[strcspn(cad, "\n")] = '\0';

        int longitud = strlen(cad);

        if (longitud > longitudMayor)
        {
            longitudMayor = longitud;
            strcpy(mayor, cad);
        }

    } while (1);

    if (longitudMayor >= 0)
    {
        printf("\nCadena mas larga: %s\n", mayor);
        printf("Longitud: %d\n", longitudMayor);
    }
    else
    {
        printf("No se ingresaron cadenas.\n");
    }

    return 0;
}

