#include <stdio.h>

int mdc(int a, int b)
{
    int aux, resto;
    if (b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }

    resto = a % b;

    while (resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

int main()
{
    int a, b, n, cont = 0, res;

    scanf("%d", &n);

    while (cont < n)
    {
        scanf("%d%d", &a, &b);
        res = mdc(a, b);
        printf("MDC(%d,%d) = %d\n", a, b, res);
        cont++;
    }

    return 0;
}