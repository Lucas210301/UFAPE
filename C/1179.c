#include <stdio.h>
int main()
{
    int a,b,d,e,f,g,h,i,j,n,p;
    int c=0, l=0, m=0, x=0;
 int par[5],impar[5],para[15];


    for(b=0; b<15; b++)
        scanf("%d", &para[b]);
    for(a=0; a<15; a++)
    {
        if(l==5)
        {
            for(n=0; n<5; n++)
                printf("impar[%d] = %d\n", n, impar[n]);
            l=0;
        }
        if(m==5)
        {
            for(p=0; p<5; p++)
                printf("par[%d] = %d\n", p, par[p]);
            m=0;
        }

        if(para[a]%2!=0)
        {
            impar[c]=para[a];
            ++c;
            l++;
            if(c==5) c=0;
        }
        if(para[a]%2==0)
        {
            par[x]=para[a];
            ++x;
            m++;
            if(x==5) x=0;
        }
    }
    for(i=0; i<l; i++)
            printf("impar[%d] = %d\n", i, impar[i]);
    for(j=0; j<m; j++)
            printf("par[%d] = %d\n", j, par[j]);
    return 0;
}
