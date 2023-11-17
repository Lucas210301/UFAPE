// Conteúdo do main.c
#include "tarefas.h"

int main() {
    ListaTarefas lista;
    Tarefa tarefa;
    int opcao, pos, id;

    inicializarLista(&lista);
    carregarDeArquivo(&lista);

    do {
        printf("\n===== Menu de Opcoes =====\n");
        printf("1. Inserir tarefa no inicio\n");
        printf("2. Inserir tarefa no fim\n");
        printf("3. Inserir tarefa em posicao especifica\n");
        printf("4. Listar tarefas\n");
        printf("5. Remover tarefa por posicao\n");
        printf("6. Remover tarefa por ID\n");
        printf("7. Procurar tarefa por ID\n");
        printf("8. Tamanho da lista\n");
        printf("-1. Sair e Salvar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Implemente a leitura da tarefa e chame a função de inserção no início
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                printf("Descricao: ");
                scanf("%49s", tarefa.descricao);
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                inserirInicio(&lista, tarefa);
                break;
            case 2:
                // Implemente a leitura da tarefa e chame a função de inserção no fim
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                printf("Descricao: ");
                scanf("%49s", tarefa.descricao);
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                inserirFim(&lista, tarefa);
                break;
            case 3:
                // Implemente a leitura da tarefa, posição e chame a função de inserção em posição específica
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                printf("Descricao: ");
                scanf("%49s", tarefa.descricao);
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                printf("Informe a posicao: ");
                scanf("%d", &pos);
                inserirPosicao(&lista, tarefa, pos);
                break;
            case 4:
                // Lista as tarefas
                listarTarefas(lista);
                break;
            case 5:
                // Implemente a leitura da posição e chame a função de remoção por posição
                printf("Informe a posicao: ");
                scanf("%d", &pos);
                removerPosicao(&lista, pos);
                break;
            case 6:
                // Implemente a leitura do ID e chame a função de remoção por ID
                printf("Informe o ID: ");
                scanf("%d", &id);
                removerValor(&lista, id);
                break;
            case 7:
                // Implemente a leitura do ID e chame a função de procurar por ID
                printf("Informe o ID: ");
                scanf("%d", &id);
                pos = procurar(lista, id);
                if (pos != -1) {
                    printf("Tarefa encontrada na posição %d.\n", pos);
                } else {
                    printf("Tarefa não encontrada.\n");
                }
                break;
            case 8:
                // Mostra o tamanho da lista
                printf("Tamanho da lista: %d\n", tamanho(lista));
                break;
            case -1:
                // Sair e salvar
                printf("Saindo do sistema...\n");
                atualizarArquivo(lista);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != -1);

    liberarMemoria(&lista);

    return 0;
}
