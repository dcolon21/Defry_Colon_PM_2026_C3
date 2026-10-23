
#include <stdio.h>
#include <string.h>

int main()
{
    char cad[50];

    printf("Ingrese una cadena: ");
    fgets(cad, sizeof(cad), stdin);

    cad[strcspn(cad, "\n")] = '\0';

    printf("Caracteres en posiciones impares: ");

    for (int i = 0; cad[i] != '\0'; i += 2)
    {
        printf("%c", cad[i]);
    }

    printf("\n");

    return 0;
}

