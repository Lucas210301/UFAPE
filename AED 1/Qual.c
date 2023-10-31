#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//3221 - Qual o numero de d�gitos de um numero inteiro?
//https://thehuxley.com/problem/3221

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