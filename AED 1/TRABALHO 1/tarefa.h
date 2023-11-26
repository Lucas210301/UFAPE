#ifndef TAREFA_H
#define TAREFA_H

#define MAX_TAREFAS 10

enum Status {
    PENDENTE,
    EM_PROGRESSO,
    CONCLUIDA,
    CANCELADA
};

typedef struct {
    int id;
    char descricao[50];
    int status;
    char prazo[11]; // Formato DD-MM-AAAA
} Tarefa;

typedef struct {
    Tarefa *tarefas;
    int quantidade;
    int capacidade;
} ListaTarefas;

const char* getStatusString(int status);
void inicializarLista(ListaTarefas *lista);
void aumentarCapacidade(ListaTarefas *lista);
int inserirInicio(ListaTarefas *lista, Tarefa tarefa);
int inserirFim(ListaTarefas *lista, Tarefa tarefa);
int inserirPosicao(ListaTarefas *lista, Tarefa tarefa, int posicao);
void listarTarefas(ListaTarefas lista);
int removerPosicao(ListaTarefas *lista, int posicao);
int removerValor(ListaTarefas *lista, int id);
int procurar(ListaTarefas lista, int id);
int tamanho(ListaTarefas lista);
void liberarMemoria(ListaTarefas *lista);
void salvarEmArquivo(ListaTarefas lista);
void carregarDeArquivo(ListaTarefas *lista);
void atualizarArquivo(ListaTarefas lista);

#endif
