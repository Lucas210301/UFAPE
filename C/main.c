#include <stdio.h>
#include <stdlib.h>



int main()
{

    int vetA[10], vetB[10];
    int valor, i, proxPosB;;

    for(i=0; i < 10; i++){
        printf("Digite proximo numero do vetor A:\n");
        scanf("%d", &valor );
        vetA[i] = valor;
    }

    proxPosB = 0;
    for(i =0; i < 10; i++){
        if (vetA[i] > 0){
            vetB[proxPosB] = vetA[i];
            proxPosB++;
        }
    }

    printf("Valores no vetor B\n");
    for (i=0; i < proxPosB; i++){
        printf(" %d ", vetB[i]);
    }

    return 0;
}
