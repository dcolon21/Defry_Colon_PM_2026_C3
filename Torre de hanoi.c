
#include <stdio.h>

void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }

    hanoi(n - 1, origen, destino, auxiliar);

    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    hanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int discos;

    printf("TORRES DE HANOI\n");
    printf("Ingrese la cantidad de discos: ");
    scanf("%d", &discos);

    if (discos < 1 || discos > 15) {
        printf("Ingrese entre 1 y 15 discos.\n");
        return 1;
    }

    printf("\nMovimientos necesarios:\n");
    hanoi(discos, 'A', 'B', 'C');

    printf("\nTotal de movimientos: %lld\n",
           (1LL << discos) - 1);

    return 0;
}

