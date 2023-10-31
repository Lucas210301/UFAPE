#include <stdio.h>

int verifical(int n, int matriz[n][n]) // Verifica se as linhas sao validas.
{
    int l, c, c1;

    for (l = 0; l < n; l++)
    {
        for (c = 0; c < n; c++)
        {
            for (c1 = c + 1; c1 < n; c1++)
            {
                if (matriz[l][c] == matriz[l][c1])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificac(int n, int matriz[n][n]) // Verifica se as colunas sao validas.
{
    int l, c, c1;

    for (l = 0; l < n; l++)
    {
        for (c = 0; c < n; c++)
        {
            for (c1 = c + 1; c1 < n; c1++)
            {
                if (matriz[c][l] == matriz[c1][l])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificab(int matriz[9][9]) // Verifica se os blocos sao validos.
{
    int l = 0, c = 0, i, j, k, n = 0, m = 0, g = 0;
    int lm = 0, cm = 0;
    int bloco[3][3];
    int blocoa[9] = {0};

    for (k = 0; k < 9; k++)
    {
        int p = 0;
        for (i = n; i < n + 3; i++)
        {
            for (j = m; j < m + 3; j++)
            {

                bloco[l][c] = matriz[i][j];
                c++;
                if (c == 3)
                {
                    c = 0;
                    l++;
                    if (l == 3)
                    {
                        l = 0;
                    }
                }
            }
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++, p++)
            {
                blocoa[p] = bloco[i][j];
            }
        }

        for (i = 0; i < 8; i++)
        {
            for (j = i + 1; j < 9; j++)
            {
                if (blocoa[i] == blocoa[j])
                {
                    return 0;
                }
            }
        }

        m += 3;
        if (m == 9)
        {
            m = 0;
            n += 3;
        }
    }
    return 1;
}

int main()
{
    int inst, l, c, i;
    int matriz[9][9] = {0};

    scanf("%d", &inst);

    for (i = 0; i < inst; i++)
    {
        for (l = 0; l < 9; l++) // Ler e armazena a matriz.
        {
            for (c = 0; c < 9; c++)
            {
                scanf("%d", &matriz[l][c]);
            }
        }

        if (verifical(9, matriz) == 1 && verificac(9, matriz) == 1 && verificab(matriz) == 1)
        {
            printf("Instancia %d\nSIM\n", i + 1);
            printf("\n");
        }
        else
        {
            printf("Instancia %d\nNAO\n", i + 1);
            printf("\n");
        }
    }

    return 0;
}