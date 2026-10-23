
#include <stdio.h>
#include <string.h>

typedef struct
{
    char calle[80];
    char codigoPostal[20];
    char colonia[50];
    char ciudad[50];
    char telefono[25];
} Domicilio;

typedef struct
{
    long long cuenta;
    char nombre[80];
    Domicilio domicilio;
    double saldo;
} Cliente;

void leer(char texto[], int tam)
{
    fgets(texto, tam, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

int buscar(Cliente cli[], int n, long long cuenta)
{
    for (int i = 0; i < n; i++)
        if (cli[i].cuenta == cuenta)
            return i;

    return -1;
}

int main()
{
    Cliente cli[100];
    int n, pos, opcion;
    long long cuenta;
    double monto;

    printf("Cantidad de clientes: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        printf("\nCliente %d\n", i + 1);

        printf("Numero de cuenta: ");
        scanf("%lld", &cli[i].cuenta);
        getchar();

        if (buscar(cli, i, cli[i].cuenta) != -1)
        {
            printf("Cuenta repetida.\n");
            return 1;
        }

        printf("Nombre: ");
        leer(cli[i].nombre, 80);

        printf("Calle y numero: ");
        leer(cli[i].domicilio.calle, 80);

        printf("Codigo postal: ");
        leer(cli[i].domicilio.codigoPostal, 20);

        printf("Colonia: ");
        leer(cli[i].domicilio.colonia, 50);

        printf("Ciudad: ");
        leer(cli[i].domicilio.ciudad, 50);

        printf("Telefono: ");
        leer(cli[i].domicilio.telefono, 25);

        printf("Saldo inicial: ");
        scanf("%lf", &cli[i].saldo);
        getchar();

        if (cli[i].saldo < 0)
            return 1;
    }

    do
    {
        printf("\n1. Deposito");
        printf("\n2. Retiro");
        printf("\n3. Consultar saldo");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        if (opcion == 0)
            break;

        if (opcion < 1 || opcion > 3)
        {
            printf("Opcion incorrecta.\n");
            continue;
        }

        printf("Numero de cuenta (0 para salir): ");
        scanf("%lld", &cuenta);

        if (cuenta == 0)
            break;

        pos = buscar(cli, n, cuenta);

        if (pos == -1)
        {
            printf("Cuenta inexistente.\n");
            continue;
        }

        if (opcion == 3)
        {
            printf("Cliente: %s\n", cli[pos].nombre);
            printf("Saldo: %.2f\n", cli[pos].saldo);
            continue;
        }

        printf("Monto: ");
        scanf("%lf", &monto);

        if (monto <= 0)
        {
            printf("Monto invalido.\n");
            continue;
        }

        if (opcion == 1)
        {
            cli[pos].saldo += monto;
            printf("Deposito realizado.\n");
        }
        else
        {
            if (monto > cli[pos].saldo)
            {
                printf("Saldo insuficiente.\n");
                continue;
            }

            cli[pos].saldo -= monto;
            printf("Retiro realizado.\n");
        }

        printf("Nuevo saldo: %.2f\n", cli[pos].saldo);

    } while (1);

    return 0;
}

