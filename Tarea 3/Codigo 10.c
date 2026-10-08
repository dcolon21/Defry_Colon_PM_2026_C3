
#include <stdio.h>

int pal(int x, int y, int *b)
{
    int c;

    *b = x * y;
    c = *b + y;
    x++;
    y = y * (y + 1);

    printf("%d %d %d %d\n", *b, c, x, y);

    return x;
}

int main(void)
{
    int a, b = 0, c, d;

    a = 2;
    c = 3;
    d = 5;

    a = pal(c, d, &b);
    printf("%d %d %d %d\n", a, b, c, d);

    b = 4;
    b = pal(b, a, &b);
    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}

