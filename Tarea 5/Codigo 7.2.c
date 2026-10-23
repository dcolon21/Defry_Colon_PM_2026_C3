
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cad[50];

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';

    printf("Digitos en posiciones pares: ");

    for (int i = 1; cad[i] != '\0'; i += 2)
    {
        if (isdigit((unsigned char)cad[i]))
        {
            printf("%c ", cad[i]);
        }
    }

    printf("\n");

    return 0;
}

