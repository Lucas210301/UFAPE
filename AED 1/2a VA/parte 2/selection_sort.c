#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // Tamanho máximo do array reduzido

// Protótipo da função selectionSort
void selectionSort(int arr[], int n);

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

// Função para medir o tempo de execução do Selection Sort
double medirTempoSelectionSort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    selectionSort(arr, tamanho);
    fim = clock();

    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_execucao;
}

// Implementação do Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Definindo os tamanhos dos arrays
    int tamanhos[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Executando o Selection Sort para cada tamanho de lista
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr = malloc(sizeof(int) * tamanho); // Alocando dinamicamente o array

        // Preenchendo o array com números aleatórios
        preencherArrayAleatorio(arr, tamanho);

        // Medindo o tempo de execução do Selection Sort
        double tempo = medirTempoSelectionSort(arr, tamanho);
        
        // Imprimindo os resultados
        printf("Tempo de execucao do Selection Sort com %d elementos: %f segundos\n", tamanho, tempo);

        // Liberando a memória alocada para o array
        free(arr);
    }

    return 0;
}
