#include <stdio.h>
int main()
{
    int n[10], a, v;
    scanf("%d", &v);
    for(a=0; a<=9; a++)
    {
        n[a]=v;
        printf("N[%d] = %d\n",a,v);
        v*=2;
    }
    return 0;
}
