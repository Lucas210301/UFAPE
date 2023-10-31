#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int num;
    scanf("%d", &num);
    
    int i;
    
    while(num > 10)
    {
        num = num/10;
        i++;
    }
    
    printf("%d", i+1);
	return 0;
}
