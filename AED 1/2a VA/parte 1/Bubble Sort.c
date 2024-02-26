#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar números aleatórios entre min e max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Função para preencher um array com números aleatórios
void preencherArrayAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = randomInt(1, 1000); // Altere os valores mínimo e máximo conforme necessário
    }
}

// Função para imprimir um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int tamanho = 10; // Tamanho do array de teste
    int arr[tamanho];

    // Preenche o array com números aleatórios
    preencherArrayAleatorio(arr, tamanho);

    printf("Array original:\n");
    imprimirArray(arr, tamanho);

    // Teste Bubble Sort
    bubbleSort(arr, tamanho);
    printf("\nArray ordenado com Bubble Sort:\n");
    imprimirArray(arr, tamanho);

    return 0;
}
