#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // Tamanho máximo do array reduzido

// Protótipo da função heapSort
void heapSort(int arr[], int n);

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

// Função para medir o tempo de execução do Heap Sort
void medirTempoHeapSort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    heapSort(arr, tamanho);
    fim = clock();

    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Heap Sort com %d elementos: %f segundos\n", tamanho, tempo_execucao);
}

// Implementação do Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Definindo os tamanhos dos arrays
    int tamanhos[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Executando o Heap Sort para cada tamanho de lista
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr = malloc(sizeof(int) * tamanho); // Alocando dinamicamente o array

        // Preenchendo o array com números aleatórios
        preencherArrayAleatorio(arr, tamanho);

        // Medindo o tempo de execução do Heap Sort
        medirTempoHeapSort(arr, tamanho);

        // Liberando a memória alocada para o array
        free(arr);
    }

    return 0;
}
