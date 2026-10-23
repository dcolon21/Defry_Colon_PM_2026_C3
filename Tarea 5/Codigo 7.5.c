
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cad[50];
    int inicio = 1;

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';

    for (int i = 0; cad[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)cad[i];

        if (isspace(c))
        {
            inicio = 1;
        }
        else
        {
            if (inicio && islower(c))
                cad[i] = (char)toupper(c);

            inicio = 0;
        }
    }

    printf("Resultado: %s\n", cad);

    return 0;
}

