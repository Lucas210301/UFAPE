#include <stdio.h>

int main()
{
    double delta, dp = 0, tudo = 0, media = 0;
    int l, c, menor = 999999, n = 3, e = 0;
    int matriz[n][n];

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            scanf("%d", &matriz[l][c]);

            if (matriz[l][c] > 0)
            {
                media += matriz[l][c];
                e++;
            }

            if (matriz[l][c] < menor)
            {
                menor = matriz[l][c];
            }
        }
    }

    media = media / e;

    if (menor % 2 == 0)
    {
        delta = 1;
    }
    else
    {
        delta = 0;
    }

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (l == c)
            {
                dp += matriz[l][c];
            }
        }
    }

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            tudo += matriz[l][c];
        }
    }

    tudo = tudo - dp;

    printf("%.2lf %d %.lf %.lf", media, menor, delta, tudo);

    return 0;
}