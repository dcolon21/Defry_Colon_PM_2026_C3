#include <stdio.h>
#include <stdlib.h>
/* Nomina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la nomina de la universidad

I: Variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main(void)

{
    INT I;
    float SAL; NOM;
    nom = 0;
    for (I=1; I<=15; I++)

{
printf(“\Ingrese el salario del profesor%d:\t”, I);
scanf(“%f”, &SAL);
NOM = NOM + SAL;
}
printf(“\nEl total de la nómina es: %.2f”, NOM);
}
