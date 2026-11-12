
#include <stdio.h>

typedef struct {
    char calle[40];
    int numero;
    char colonia[40];
    char codigoPostal[12];
    char ciudad[40];
    char telefono[20];
} Domicilio;

typedef struct {
    int clave;
    char nombre[60];
    int edad;
    char sexo;
    int condicion;
    Domicilio domicilio;
} Paciente;

int main() {
    FILE *archivo;
    Paciente p;

    int total = 0, hombres = 0, mujeres = 0;
    int condicion[5] = {0};
    int edades[11] = {0};
    int i, grupo;

    archivo = fopen("pacientes.dat", "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir pacientes.dat\n");
        return 1;
    }

    while (fread(&p, sizeof(Paciente),
                 1, archivo) == 1) {

        total++;

        if (p.sexo == 'M' || p.sexo == 'm' ||
            p.sexo == 'H' || p.sexo == 'h')
            hombres++;

        if (p.sexo == 'F' || p.sexo == 'f')
            mujeres++;

        if (p.condicion >= 1 && p.condicion <= 5)
            condicion[p.condicion - 1]++;

        if (p.edad >= 0) {
            grupo = p.edad / 10;

            if (grupo > 10)
                grupo = 10;

            edades[grupo]++;
        }
    }

    fclose(archivo);

    printf("\nESTADISTICAS DEL HOSPITAL\n");

    printf("Total de pacientes: %d\n", total);

    if (total > 0) {
        printf("Hombres: %.2f%%\n",
               100.0 * hombres / total);

        printf("Mujeres: %.2f%%\n",
               100.0 * mujeres / total);
    }

    printf("\nPACIENTES POR CONDICION\n");

    for (i = 0; i < 5; i++) {
        printf("Condicion %d: %d\n",
               i + 1, condicion[i]);
    }

    printf("\nPACIENTES POR EDAD\n");

    for (i = 0; i < 10; i++) {
        printf("%d-%d anios: %d\n",
               i * 10, i * 10 + 9, edades[i]);
    }

    printf("100 anios o mas: %d\n", edades[10]);

    return 0;
}

