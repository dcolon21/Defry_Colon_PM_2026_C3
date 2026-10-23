
#include <stdio.h>

int main()
{
    char cad[30];
    int dia, mes, anio;
    int anioCompleto;

    const char *meses[] = {
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    printf("Ingrese fecha (dd/mm/aa): ");
    fgets(cad, sizeof(cad), stdin);

    if (sscanf(cad, "%d/%d/%d", &dia, &mes, &anio) != 3)
    {
        printf("Formato incorrecto.\n");
        return 1;
    }

    if (dia < 1 || dia > 31 ||
        mes < 1 || mes > 12 ||
        anio < 0 || anio > 99)
    {
        printf("Fecha invalida.\n");
        return 1;
    }

    if (anio <= 49)
        anioCompleto = 2000 + anio;
    else
        anioCompleto = 1900 + anio;

    printf("%02d de %s de %d\n",
           dia, meses[mes - 1], anioCompleto);

    return 0;
}

