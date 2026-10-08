
#include <stdio.h>

long long K = 5;

long long f1(void)
{
    K *= K;
    return K;
}

int f2(void)
{
    int K = 3;
    K++;
    return K;
}

int f3(void)
{
    static int K = 6;
    K += 3;
    return K;
}

long long f4(void)
{
    int valorLocal = 4;
    return valorLocal + K;
}

int main(void)
{
    int I;

    for (I = 1; I <= 4; I++)
    {
        printf("\nITERACION %d\n", I);

        printf("Resultado f1: %lld\n", f1());
        printf("Resultado f2: %d\n", f2());
        printf("Resultado f3: %d\n", f3());
        printf("Resultado f4: %lld\n", f4());
    }

    return 0;
}

