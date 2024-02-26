#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Protótipo da função bubbleSort
void bubbleSort(int arr[], int n);

// Função para gerar números aleatórios entre min e max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Função para preencher um array com números aleatórios
void preencherArrayAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = randomInt(1, tamanho); // Preenchendo com números de 1 a tamanho
    }
}

// Função para medir o tempo de execução do Bubble Sort
void medirTempoBubbleSort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    bubbleSort(arr, tamanho);
    fim = clock();

    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Bubble Sort com %d elementos: %f segundos\n", tamanho, tempo_execucao);
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Definindo os tamanhos dos arrays
    int tamanhos[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Executando o Bubble Sort para cada tamanho de lista
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr = malloc(sizeof(int) * tamanho); // Alocando dinamicamente o array

        // Preenchendo o array com números aleatórios
        preencherArrayAleatorio(arr, tamanho);

        // Medindo o tempo de execução do Bubble Sort
        medirTempoBubbleSort(arr, tamanho);

        // Liberando a memória alocada para o array
        free(arr);
    }

    return 0;
}
