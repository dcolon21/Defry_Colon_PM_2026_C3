
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arc[20][80];
    int frecuencia[80] = {0};

    for (int i = 0; i < 20; i++)
    {
        printf("Cadena %d: ", i + 1);
        fgets(arc[i], sizeof(arc[i]), stdin);

        arc[i][strcspn(arc[i], "\n")] = '\0';
    }

    for (int i = 0; i < 20; i++)
    {
        int longitud = 0;

        for (int j = 0; ; j++)
        {
            unsigned char c = (unsigned char)arc[i][j];

            if (isalnum(c))
            {
                longitud++;
            }
            else
            {
                if (longitud > 0)
                {
                    frecuencia[longitud]++;
                    longitud = 0;
                }
            }

            if (c == '\0')
                break;
        }
    }

    printf("\nLongitud\tFrecuencia\n");

    for (int i = 1; i < 80; i++)
    {
        if (frecuencia[i] > 0)
            printf("%d\t\t%d\n", i, frecuencia[i]);
    }

    return 0;
}

