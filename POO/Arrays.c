#include <stdio.h>

int main()
{
    int valor;
    int par[5];
    int impar[5];
    int indicePar = 0;
    int indiceImpar = 0;
    
    for(int i = 0; i<15; i++){
        scanf("%d", &valor);
        if (valor % 2 == 0){
            par[indicePar] = valor;
            indicePar++;
        }   else {
            impar[indiceImpar] = valor;
            indiceImpar++;
        }
        
        if (indicePar ==5){
            for (int j = 0; j<5; j++){
                printf("par[%d] = %d\n",j,par[j]);
            }
            indicePar = 0;
        }
        if (indiceImpar ==5){
            for (int j = 0; j<5; j++){
                printf("impar[%d] = %d\n",j,impar[j]);
            }
            indiceImpar = 0;
        }
    }
    
    if (indiceImpar >0) {
        for (int j = 0; j<indiceImpar; j++){
                printf("impar[%d] = %d\n",j,impar[j]);
            }
    
    }
    
    if (indicePar >0) {
        for(int j = 0; j<indicePar; j++){
                printf("par[%d] = %d\n",j,par[j]);
            }   
    } 
    
    return 0;
}