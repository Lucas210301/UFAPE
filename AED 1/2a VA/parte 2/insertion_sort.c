#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função principal do Insertion Sort
void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que a chave,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

// Função para preencher um array com números aleatórios
void preencherArrayAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % tamanho; // Preenchendo com números aleatórios
    }
}

// Função para medir o tempo de execução do Insertion Sort
double medirTempoInsertionSort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    insertionSort(arr, tamanho);
    fim = clock();

    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_execucao;
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Definindo os tamanhos dos arrays
    int tamanhos[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Executando o Insertion Sort para cada tamanho de lista
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr = malloc(sizeof(int) * tamanho); // Alocando dinamicamente o array

        // Preenchendo o array com números aleatórios
        preencherArrayAleatorio(arr, tamanho);

        // Medindo o tempo de execução do Insertion Sort
        double tempo = medirTempoInsertionSort(arr, tamanho);
        
        // Imprimindo os resultados
        printf("Tempo de execucao do Insertion Sort com %d elementos: %f segundos\n", tamanho, tempo);

        // Liberando a memória alocada para o array
        free(arr);
    }

    return 0;
}
