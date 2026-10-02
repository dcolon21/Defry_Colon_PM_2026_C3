#include <studio.h>
/* Numeros perfectos.
El programa, al recibir copmo dato un numero positivo como limite, obtiene
los numeros perfectos que hay entre 1 y ese numero, y ademas imprime cuantos numeros perfectos hay en el intervalo.

I,J , NUM, SUM, C: variables de tipo entero. */
void main (void)
{
int I, J, NUM, SUM, C = 0;
    printf ("\nIngrese el numero limite: ");
    scanf ("\nIngrese el numero limite ");
    for (I = 1; I <= NUM; I++)
{
        sum = 0;
        for (J = 1; J <= (I/2); j++)
        if ((I%J)==0)
        sum += j;
        IF (SUM == I)
        }
{printf (*\n%d es un numero perfecto", I);
C++;
}
}
printf("\nEntre 1 y %d hay %d numeros perfectos", NUM, C);
}
