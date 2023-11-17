// Conteúdo do main.c
#include "tarefas.h"

int main() {
    ListaTarefas lista;
    Tarefa tarefa;
    int opcao, pos, id;

    inicializarLista(&lista);
    carregarDeArquivo(&lista);

    do {
        // ... (seu código do menu aqui)

    } while (opcao != -1);

    liberarMemoria(&lista);

    return 0;
}
