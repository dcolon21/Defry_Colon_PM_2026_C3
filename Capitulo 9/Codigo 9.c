
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int clave;
    char nombre[40];
    int existencia;
    float precio;
} Producto;

Producto productos[100];
int total = 0;

int buscar(int clave) {
    int i;

    for (i = 0; i < total; i++) {
        if (productos[i].clave == clave)
            return i;
    }

    return -1;
}

void guardar() {
    FILE *archivo = fopen("com.dat", "wb");

    if (archivo == NULL) {
        printf("Error al guardar.\n");
        return;
    }

    fwrite(productos, sizeof(Producto), total, archivo);
    fclose(archivo);
}

void cargar() {
    FILE *archivo = fopen("com.dat", "rb");

    if (archivo != NULL) {
        total = (int)fread(productos,
                           sizeof(Producto), 100, archivo);
        fclose(archivo);
    }
}

void inventario() {
    int i;

    printf("\nINVENTARIO\n");

    for (i = 0; i < total; i++) {
        printf("%d | %s | %d | %.2f\n",
               productos[i].clave,
               productos[i].nombre,
               productos[i].existencia,
               productos[i].precio);
    }
}

void ventas() {
    int clave, cantidad, pos;
    float totalVenta = 0;

    while (1) {
        printf("Clave (0 para terminar): ");
        scanf("%d", &clave);

        if (clave == 0)
            break;

        pos = buscar(clave);

        if (pos == -1) {
            printf("Producto no encontrado.\n");
            continue;
        }

        printf("Cantidad: ");
        scanf("%d", &cantidad);

        if (cantidad > 0 &&
            cantidad <= productos[pos].existencia) {

            productos[pos].existencia -= cantidad;
            totalVenta += cantidad * productos[pos].precio;

            printf("Venta registrada.\n");
        } else {
            printf("Cantidad invalida.\n");
        }
    }

    printf("Total de venta: %.2f\n", totalVenta);
    guardar();
}

void reabastecer() {
    int clave, cantidad, pos;

    while (1) {
        printf("Clave (0 para terminar): ");
        scanf("%d", &clave);

        if (clave == 0)
            break;

        pos = buscar(clave);

        if (pos == -1) {
            printf("Producto no encontrado.\n");
            continue;
        }

        printf("Cantidad a agregar: ");
        scanf("%d", &cantidad);

        if (cantidad > 0) {
            productos[pos].existencia += cantidad;
            printf("Inventario actualizado.\n");
        }
    }

    guardar();
}

void nuevoProducto() {
    Producto p;
    int i, j;

    while (1) {
        printf("Clave (0 para terminar): ");
        scanf("%d", &p.clave);

        if (p.clave == 0)
            break;

        if (buscar(p.clave) != -1 || total >= 100) {
            printf("Clave repetida o inventario lleno.\n");
            continue;
        }

        printf("Nombre: ");
        scanf("%39s", p.nombre);

        printf("Existencia: ");
        scanf("%d", &p.existencia);

        printf("Precio: ");
        scanf("%f", &p.precio);

        if (p.existencia < 0 || p.precio < 0) {
            printf("Datos invalidos.\n");
            continue;
        }

        i = total;

        while (i > 0 &&
               productos[i - 1].clave > p.clave) {
            productos[i] = productos[i - 1];
            i--;
        }

        productos[i] = p;
        total++;
    }

    guardar();
}

int main() {
    int opcion;

    cargar();

    do {
        printf("\nMENU DE INVENTARIO\n");
        printf("1. Ventas\n");
        printf("2. Reabastecimiento\n");
        printf("3. Nuevos productos\n");
        printf("4. Inventario\n");
        printf("0. Salir\n");
        printf("Seleccione: ");

        if (scanf("%d", &opcion) != 1)
            break;

        switch (opcion) {
            case 1: ventas(); break;
            case 2: reabastecer(); break;
            case 3: nuevoProducto(); break;
            case 4: inventario(); break;
            case 0: guardar(); break;
            default: printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}

