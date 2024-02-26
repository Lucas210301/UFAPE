#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para preencher um array com números aleatórios
void preencherArrayAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % tamanho; // Preenchendo com números aleatórios
    }
}

// Função para medir o tempo de execução do Quick Sort
double medirTempoQuickSort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    quickSort(arr, 0, tamanho - 1);
    fim = clock();

    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_execucao;
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Definindo os tamanhos dos arrays
    int tamanhos[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Executando o Quick Sort para cada tamanho de lista
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr = malloc(sizeof(int) * tamanho); // Alocando dinamicamente o array

        // Preenchendo o array com números aleatórios
        preencherArrayAleatorio(arr, tamanho);

        // Medindo o tempo de execução do Quick Sort
        double tempo = medirTempoQuickSort(arr, tamanho);
        
        // Imprimindo os resultados
        printf("Tempo de execucao do Quick Sort com %d elementos: %f segundos\n", tamanho, tempo);

        // Liberando a memória alocada para o array
        free(arr);
    }

    return 0;
}
