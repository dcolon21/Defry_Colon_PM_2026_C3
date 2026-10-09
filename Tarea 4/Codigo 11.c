
#include <stdio.h>

int main()
{
    unsigned long long perfectos[8];
    int exponentes[8] = {2, 3, 5, 7, 13, 17, 19, 31};

    for (int i = 0; i < 8; i++)
    {
        int p = exponentes[i];

        unsigned long long m = (1ULL << p) - 1ULL;

        perfectos[i] = (1ULL << (p - 1)) * m;
    }

    printf("Primeros ocho numeros perfectos:\n");

    for (int i = 0; i < 8; i++)
        printf("%d: %llu\n", i + 1, perfectos[i]);

    return 0;
}
