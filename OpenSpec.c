#include <stdio.h>

int main(void)
{
    double kilometros;
    double precio_combustible;
    double rendimiento;
    double costo_mantenimiento_km;
    double litros;
    double costo_combustible;
    double costo_mantenimiento;
    double costo_total;
    double costo_por_km;

    printf("Calculadora de costo de viaje\n");
    printf("-----------------------------\n");

    printf("Kilometros recorridos: ");
    if (scanf("%lf", &kilometros) != 1 || kilometros <= 0.0) {
        printf("Error: los kilometros deben ser un numero mayor que cero.\n");
        return 1;
    }

    printf("Precio del combustible por litro (RD$): ");
    if (scanf("%lf", &precio_combustible) != 1 || precio_combustible < 0.0) {
        printf("Error: el precio del combustible no puede ser negativo.\n");
        return 1;
    }

    printf("Rendimiento del vehiculo (km/L): ");
    if (scanf("%lf", &rendimiento) != 1 || rendimiento <= 0.0) {
        printf("Error: el rendimiento debe ser mayor que cero.\n");
        return 1;
    }

    printf("Costo de mantenimiento por kilometro (RD$): ");
    if (scanf("%lf", &costo_mantenimiento_km) != 1 || costo_mantenimiento_km < 0.0) {
        printf("Error: el costo de mantenimiento no puede ser negativo.\n");
        return 1;
    }

    litros = kilometros / rendimiento;
    costo_combustible = litros * precio_combustible;
    costo_mantenimiento = kilometros * costo_mantenimiento_km;
    costo_total = costo_combustible + costo_mantenimiento;
    costo_por_km = costo_total / kilometros;

    printf("\nResultados del viaje\n");
    printf("--------------------\n");
    printf("Kilometros recorridos:       %.2f km\n", kilometros);
    printf("Combustible consumido:       %.2f L\n", litros);
    printf("Costo de combustible:        RD$ %.2f\n", costo_combustible);
    printf("Costo de mantenimiento:      RD$ %.2f\n", costo_mantenimiento);
    printf("Costo total del viaje:       RD$ %.2f\n", costo_total);
    printf("Costo por kilometro:         RD$ %.2f/km\n", costo_por_km);

    return 0;
}
