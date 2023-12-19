#include <stdio.h>
#include <stdlib.h>

#define N 8

// Estrutura para representar um vértice do grafo
typedef struct Vertex {
    int id;
    struct Vertex* next;
} Vertex;

// Estrutura para representar o grafo do tabuleiro de xadrez
typedef struct {
    Vertex* vertices;
    int n;
} Graph;

// Arrays para representar os movimentos possíveis do cavalo
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int *visited;
Graph grafo;

// Função para inicializar o grafo
void initializeGraph(Graph *graph);

// Função para adicionar uma aresta ao grafo
void addEdge(Graph *graph, int src, int dest);

// Função para realizar o passeio do cavalo usando busca em profundidade
void knightTourUtil(Graph *graph, int *visited, int currentVertex, int *tour, int *found, int *count);

// Função para verificar se uma posição no tabuleiro é válida
int isValidMove(int x, int y, int *visited);

// Função para imprimir o grafo
void printGraph(Graph *graph);

// Função principal
int main() {
    Graph chessBoard;
    initializeGraph(&chessBoard);

    // Escolha a posição inicial do cavalo (0 a N*N-1)
    int startPosition = 0;

    printf("Grafo do tabuleiro de xadrez:\n");
    printGraph(&chessBoard);

    printf("\nPasseio do cavalo iniciando em %d:\n", startPosition);
    visited = (int *)malloc(sizeof(int) * N * N);
    for (int i = 0; i < N * N; ++i) {
        visited[i] = 0;
    }

    int tour[N * N];
    int found = 0;
    int count = 0;

    knightTourUtil(&chessBoard, visited, startPosition, tour, &found, &count);

    if (!found) {
        printf("Passeio do cavalo não encontrado.\n");
    }

    free(visited);
    free(chessBoard.vertices); // Libera a memória alocada para os vértices do grafo
    return 0;
}

void initializeGraph(Graph *graph) {
    // Inicializar os vértices
    graph->vertices = (Vertex *)malloc(sizeof(Vertex) * N * N);
    for (int i = 0; i < N * N; ++i) {
        graph->vertices[i].id = i;
        graph->vertices[i].next = NULL;
    }

    // Adicionar arestas ao grafo representando movimentos do cavalo
    for (int i = 0; i < N * N; ++i) {
        int x = i / N;
        int y = i % N;

        // Geração de todos os movimentos legais do cavalo
        for (int j = 0; j < 8; ++j) {
            int nextX = x + moveX[j];
            int nextY = y + moveY[j];

            if (isValidMove(nextX, nextY, NULL)) {
                addEdge(graph, i, nextX * N + nextY);
            }
        }
    }
}

void addEdge(Graph *graph, int src, int dest) {
    Vertex *novo = (Vertex *)malloc(sizeof(Vertex));
    novo->id = dest;
    novo->next = NULL;

    Vertex *temp = &graph->vertices[src];
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = novo;
}

int isValidMove(int x, int y, int *visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && (visited == NULL || visited[x * N + y] == 0));
}

void knightTourUtil(Graph *graph, int *visited, int currentVertex, int *tour, int *found, int *count) {
    visited[currentVertex] = 1;
    tour[*count] = currentVertex;
    ++(*count);

    if (*count == N * N) {
        // Passeio do cavalo concluído
        *found = 1;
        printf("Passeio do cavalo encontrado:\n");
        for (int i = 0; i < N * N; ++i) {
            printf("(%d, %d) ", graph->vertices[tour[i]].id / N, graph->vertices[tour[i]].id % N);
            if ((i + 1) % N == 0)
                printf("\n");
        }
        return;
    }

    Vertex *temp = graph->vertices[currentVertex].next;
    while (temp != NULL) {
        if (!visited[temp->id] && !(*found)) {
            knightTourUtil(graph, visited, temp->id, tour, found, count);
        }
        temp = temp->next;
    }

    // Backtracking
    visited[currentVertex] = 0;
    --(*count);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < N * N; ++i) {
        printf("Vértice (%d, %d): ", graph->vertices[i].id / N, graph->vertices[i].id % N);
        Vertex *temp = graph->vertices[i].next;
        while (temp != NULL) {
            printf("(%d, %d) ", temp->id / N, temp->id % N);
            temp = temp->next;
        }
        printf("\n");
    }
}
