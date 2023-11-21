#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);

    for (int i = 1; i <= 10; i++) {
        int resultado = N * i;
        printf("%d\n", resultado);
    }
    
    return 0;
}