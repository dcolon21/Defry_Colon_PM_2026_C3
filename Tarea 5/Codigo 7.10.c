
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main()
{
    char cad[50];
    char fecha[11];
    char respuesta;

    time_t ahora = time(NULL);
    struct tm *hoy = localtime(&ahora);

    if (hoy == NULL)
        return 1;

    strftime(fecha, sizeof(fecha), "%d/%m/%Y", hoy);

    printf("Fecha actual: %s\n", fecha);

    do
    {
        printf("\nIngresar cadena? (S/N): ");
        scanf(" %c", &respuesta);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (toupper((unsigned char)respuesta) != 'S')
            break;

        printf("Cadena: ");
        fgets(cad, sizeof(cad), stdin);

        cad[strcspn(cad, "\n")] = '\0';

        if (strncmp(cad, fecha, 10) == 0 &&
            (cad[10] == ' ' || cad[10] == '\0'))
        {
            printf("Coincide: %s\n", cad);
        }

    } while (1);

    return 0;
}

