#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um vértice do grafo
typedef struct Vertex {
    int id;
    struct Vertex* next;
} Vertex;

// Estrutura para representar o grafo
typedef struct Graph {
    int numVertices;
    Vertex** adjacencyList;
} Graph;

// Função para criar um novo vértice
Vertex* createVertex(int id) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->id = id;
    newVertex->next = NULL;
    return newVertex;
}

// Função para criar um novo grafo
Graph* createGraph(int numVertices) {
    Graph* grafoLabirinto = (Graph*)malloc(sizeof(Graph));
    grafoLabirinto->numVertices = numVertices;
    grafoLabirinto->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));

    for (int i = 0; i < numVertices; ++i) {
        grafoLabirinto->adjacencyList[i] = NULL;
    }

    return grafoLabirinto;
}

// Função para adicionar uma aresta entre dois vértices
void addEdge(Graph* grafoLabirinto, int src, int dest) {
    Vertex* newVertex = createVertex(dest);
    newVertex->next = grafoLabirinto->adjacencyList[src];
    grafoLabirinto->adjacencyList[src] = newVertex;
}

// Função para imprimir o grafo
void printGraph(Graph* grafoLabirinto) {
    for (int i = 0; i < grafoLabirinto->numVertices; ++i) {
        Vertex* temp = grafoLabirinto->adjacencyList[i];
        printf("\nLista de adjacência do vértice %d\n", i);
        while (temp) {
            printf("-> %d ", temp->id);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função para ler o labirinto de um arquivo
void readMazeFromFile(char* filename, char** maze, int numRows, int numCols) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", filename);
        perror("Detalhes do erro");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            fscanf(file, " %c", &maze[i][j]);
        }
    }

    fclose(file);
}

// Função para adicionar arestas com base no labirinto
void addEdgesFromMaze(Graph* grafoLabirinto, char** maze, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (maze[i][j] != 'X') {
                // Adicionar arestas para os vizinhos não bloqueados
                if (i < numRows - 1 && maze[i + 1][j] != 'X') {
                    addEdge(grafoLabirinto, i * numCols + j, (i + 1) * numCols + j);
                }
                if (j < numCols - 1 && maze[i][j + 1] != 'X') {
                    addEdge(grafoLabirinto, i * numCols + j, i * numCols + (j + 1));
                }
                // Adicionar aresta para a saída (canto inferior direito)
                if (i == numRows - 1 && j == numCols - 1) {
                    addEdge(grafoLabirinto, i * numCols + j, numRows * numCols);
                }
            }
        }
    }
}

// Implementação da busca em profundidade (DFS)
void depthFirstSearch(Graph* grafoLabirinto, int start, int* visited) {
    visited[start] = 1;
    printf("%d ", start);

    Vertex* temp = grafoLabirinto->adjacencyList[start];
    while (temp) {
        int adjVertex = temp->id;
        if (!visited[adjVertex]) {
            depthFirstSearch(grafoLabirinto, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Implementação da busca em largura (BFS)
void breadthFirstSearch(Graph* grafoLabirinto, int start, int* visited) {
    int queue[grafoLabirinto->numVertices];
    int front = 0, rear = 0;

    visited[start] = 1;
    printf("%d ", start);
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        Vertex* temp = grafoLabirinto->adjacencyList[currentVertex];

        while (temp) {
            int adjVertex = temp->id;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                printf("%d ", adjVertex);
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Leitura do labirinto de um arquivo
    char* filenames[] = {"l1.txt", "l2.txt", "l3.txt", "l4.txt"};
    int numRows[] = {20, 40, 80, 150};
    int numCols[] = {20, 40, 80, 150};

    for (int k = 0; k < 4; ++k) {
        char** maze = (char**)malloc(numRows[k] * sizeof(char*));
        for (int i = 0; i < numRows[k]; ++i) {
            maze[i] = (char*)malloc(numCols[k] * sizeof(char));
        }

        readMazeFromFile(filenames[k], maze, numRows[k], numCols[k]);

        // Criar e inicializar o grafo
        Graph* grafoLabirinto = createGraph(numRows[k] * numCols[k] + 1); // +1 para o vértice de saída

        // Adicionar arestas ao grafo com base no labirinto
        addEdgesFromMaze(grafoLabirinto, maze, numRows[k], numCols[k]);

        // Imprimir o grafo
        printf("\nGrafo para labirinto %s:\n", filenames[k]);
        printGraph(grafoLabirinto);

        // Inicializar vetor de visitados
        int visited[numRows[k] * numCols[k] + 1];
        for (int i = 0; i < numRows[k] * numCols[k] + 1; ++i) {
            visited[i] = 0;
        }

        printf("\nDFS para labirinto %s: ", filenames[k]);
        depthFirstSearch(grafoLabirinto, 0, visited);

        // Reinicializar vetor de visitados
        for (int i = 0; i < numRows[k] * numCols[k] + 1; ++i) {
            visited[i] = 0;
        }

        printf("\nBFS para labirinto %s: ", filenames[k]);
        breadthFirstSearch(grafoLabirinto, 0, visited);

        // Liberar memória
        for (int i = 0; i < numRows[k]; ++i) {
            free(maze[i]);
        }
        free(maze);

        free(grafoLabirinto->adjacencyList);
        free(grafoLabirinto);
    }

    return 0;
}
