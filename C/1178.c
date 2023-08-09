#include <stdio.h>
int main()
{
   int a;
    double n[100],b,c,d;
    scanf("%lf", &b);
    n[a]=b;
    for(a=0; a<100;a++)
    {
        printf("N[%d] = %.4lf\n", a, n[a]);
        b/=2;
        n[a+1]=b;
    }
    return 0;
}