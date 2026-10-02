#include <stdio.h>
 #include <stdlib.h>

#include <time.h>
 #define ARRAY_SIZE 10

int i;
 int change;//verificar si terminamos
 int n;
 int a[ARRAY_SIZE];//arrai de enteros 4 bytes y 10 elementos
 int buf;//memoria temporal
 time_t seed;

int main(int argc, char* argv[])
 {
 seed = 0;
 srand(time(&seed));
 n = sizeof(a) / sizeof(*a);
 for (i = 0; i <= n-1; i++)
 {
 a[i] = rand() % 100;
 }
 for (i = 0; i <= n-1; i++)
 {
 printf("Element a[%d]: %d\n", i, a[i]);
 }
 printf("\-------------------------------------------\n");
 //////////////
 change = 1;
 while (change == 1)
 {
 change = 0;
 for (i = 0; i <= n-2; i++)
 {
 if (a[i] > a[i+1])
 {
 buf = a[i];
 a[i] = a[i+1];
 a[i+1] = buf;
 change = 1;
 }
 }
 }
 /////////

 for (i = 0; i <= n-1; i++)
 {
 printf("Element a[%d]: %d\n", i, a[i]);
 }
 return 0;
 }
