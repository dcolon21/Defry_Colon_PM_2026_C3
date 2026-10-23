
#include <stdio.h>
#include <string.h>

int main()
{
    char cad1[50], cad2[50];
    char *p1, *p2;

    printf("Primera cadena: ");
    fgets(cad1, sizeof(cad1), stdin);

    printf("Segunda cadena: ");
    fgets(cad2, sizeof(cad2), stdin);

    cad1[strcspn(cad1, "\n")] = '\0';
    cad2[strcspn(cad2, "\n")] = '\0';

    p1 = strtok(cad1, " \t");
    p2 = strtok(cad2, " \t");

    printf("\nCadena intercalada:\n");

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL)
        {
            printf("%s ", p1);
            p1 = strtok(NULL, " \t");
        }

        if (p2 != NULL)
        {
            printf("%s ", p2);
            p2 = strtok(NULL, " \t");
        }
    }

    printf("\n");
    return 0;
}

