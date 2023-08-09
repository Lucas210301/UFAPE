#include <stdio.h>
int main()
{
    double a[100];
    int i;
    for(i=0; i<=99; i++)
        scanf("%lf", &a[i]);
    for(i=0; i<=99; i++)
    {
        if(a[i]<=10.0)
            printf("A[%d] = %.1lf\n",i, a[i]);
    }
    return 0;
}