
#include <stdio.h>

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} Alumno;

int main() {
    FILE *entrada, *salida;
    Alumno alumno;
    int anterior = 0;
    int primero = 1;
    int total = 0;

    entrada = fopen("ad5.dat", "rb");

    if (entrada == NULL) {
        printf("Error al abrir ad5.dat\n");
        return 1;
    }

    salida = fopen("ad5_sin_repetidos.dat", "wb");

    if (salida == NULL) {
        fclose(entrada);
        return 1;
    }

    while (fread(&alumno, sizeof(Alumno),
                 1, entrada) == 1) {

        if (primero ||
            alumno.matricula != anterior) {

            fwrite(&alumno, sizeof(Alumno),
                   1, salida);

            anterior = alumno.matricula;
            primero = 0;
            total++;
        }
    }

    printf("Registros unicos: %d\n", total);

    fclose(entrada);
    fclose(salida);

    return 0;
}

