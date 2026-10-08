
#include <stdio.h>
#include <stdlib.h>

#define SALIR 0
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define RAIZ 5
#define CUADRADO 6

#define ERR_OK 0
#define ERR_SYNTAX 1
#define ERR_DivByZero 555
#define ERR_RAIZ_NEGATIVA 556

// Declaracion de funciones
int suma(double s1, double s2, double *r);
int resta(double minuendo, double sustraendo, double *r);
int multiplicacion(double n1, double n2, double *r);
int divicion(double dividendo, double divisor, double *r);
int raizCuadrada(double numero, double *r);
int elevarCuadrado(double numero, double *r);

int main()
{
    int menu = -1;
    double n1 = 0.0;
    double n2 = 0.0;
    double result = 0.0;
    int err = ERR_OK;

    printf("\nCALCULADORA V2.0");

    do
    {
        printf("\n\n===== MENU =====");
        printf("\n0 - SALIR");
        printf("\n1 - SUMAR");
        printf("\n2 - RESTAR");
        printf("\n3 - MULTIPLICAR");
        printf("\n4 - DIVIDIR");
        printf("\n5 - RAIZ CUADRADA");
        printf("\n6 - ELEVAR AL CUADRADO");
        printf("\nSeleccione una opcion: ");

        if (scanf("%d", &menu) != 1)
        {
            printf("\nEntrada invalida.\n");
            return ERR_SYNTAX;
        }

        if (menu >= SUMAR && menu <= DIVIDIR)
        {
            printf("\nEscriba el primer numero: ");
            if (scanf("%lf", &n1) != 1)
                return ERR_SYNTAX;

            printf("Escriba el segundo numero: ");
            if (scanf("%lf", &n2) != 1)
                return ERR_SYNTAX;
        }
        else if (menu == RAIZ || menu == CUADRADO)
        {
            printf("\nEscriba el numero: ");
            if (scanf("%lf", &n1) != 1)
                return ERR_SYNTAX;
        }

        err = ERR_OK;

        switch (menu)
        {
            case SUMAR:
                err = suma(n1, n2, &result);
                break;

            case RESTAR:
                err = resta(n1, n2, &result);
                break;

            case MULTIPLICAR:
                err = multiplicacion(n1, n2, &result);
                break;

            case DIVIDIR:
                err = divicion(n1, n2, &result);
                break;

            case RAIZ:
                err = raizCuadrada(n1, &result);
                break;

            case CUADRADO:
                err = elevarCuadrado(n1, &result);
                break;

            case SALIR:
                printf("\nSaliendo de la calculadora...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
                continue;
        }

        if (menu != SALIR)
        {
            if (err == ERR_OK)
                printf("\nResultado = %.6lf\n", result);
            else if (err == ERR_DivByZero)
                printf("\nNo se puede dividir entre cero.\n");
            else if (err == ERR_RAIZ_NEGATIVA)
                printf("\nNo existe raiz real de un numero negativo.\n");
        }

    } while (menu != SALIR);

    return 0;
}

// SUMA
int suma(double s1, double s2, double *r)
{
    *r = s1 + s2;
    return ERR_OK;
}

// RESTA
int resta(double minuendo, double sustraendo, double *r)
{
    *r = minuendo - sustraendo;
    return ERR_OK;
}

// MULTIPLICACION
int multiplicacion(double n1, double n2, double *r)
{
    *r = n1 * n2;
    return ERR_OK;
}

// DIVISION
int divicion(double dividendo, double divisor, double *r)
{
    if (divisor == 0)
        return ERR_DivByZero;

    *r = dividendo / divisor;
    return ERR_OK;
}

// RAIZ CUADRADA - METODO DE NEWTON-RAPHSON
int raizCuadrada(double numero, double *r)
{
    if (numero < 0)
        return ERR_RAIZ_NEGATIVA;

    if (numero == 0)
    {
        *r = 0;
        return ERR_OK;
    }

    double aproximacion = numero >= 1 ? numero : 1.0;

    for (int i = 0; i < 100; i++)
    {
        double nueva = (aproximacion +
                        numero / aproximacion) / 2.0;

        if (nueva == aproximacion)
            break;

        aproximacion = nueva;
    }

    *r = aproximacion;
    return ERR_OK;
}

// ELEVAR AL CUADRADO
int elevarCuadrado(double numero, double *r)
{
    *r = numero * numero;
    return ERR_OK;
}

