#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const char* getStatusString(int status) {
    switch (status) {
        case PENDENTE:
            return "Pendente";
        case EM_PROGRESSO:
            return "Em Progresso";
        case CONCLUIDA:
            return "Concluída";
        case CANCELADA:
            return "Cancelada";
        default:
            return "Desconhecido";
    }
}

void inicializarLista(ListaTarefas *lista) {
    lista->tarefas = (Tarefa *)malloc(MAX_TAREFAS * sizeof(Tarefa));
    if (lista->tarefas == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    lista->quantidade = 0;
    lista->capacidade = MAX_TAREFAS;
}

void aumentarCapacidade(ListaTarefas *lista) {
    lista->capacidade += 10;
    lista->tarefas = (Tarefa *)realloc(lista->tarefas, lista->capacidade * sizeof(Tarefa));
    if (lista->tarefas == NULL) {
        printf("Erro ao realocar memória.\n");
        exit(EXIT_FAILURE);
    }
}

int inserirInicio(ListaTarefas *lista, Tarefa tarefa) {
    if (lista->quantidade == lista->capacidade) {
        aumentarCapacidade(lista);
    }

    for (int i = lista->quantidade; i > 0; i--) {
        lista->tarefas[i] = lista->tarefas[i - 1];
    }

    lista->tarefas[0] = tarefa;
    lista->quantidade++;
    return 1;
}

int inserirFim(ListaTarefas *lista, Tarefa tarefa) {
    if (lista->quantidade == lista->capacidade) {
        aumentarCapacidade(lista);
    }

    lista->tarefas[lista->quantidade] = tarefa;
    lista->quantidade++;
    return 1;
}

int inserirPosicao(ListaTarefas *lista, Tarefa tarefa, int posicao) {
    if (posicao < 0 || posicao > lista->quantidade) {
        printf("Posicao invalida.\n");
        return 0;
    }

    if (lista->quantidade == lista->capacidade) {
        aumentarCapacidade(lista);
    }

    for (int i = lista->quantidade; i > posicao; i--) {
        lista->tarefas[i] = lista->tarefas[i - 1];
    }

    lista->tarefas[posicao] = tarefa;
    lista->quantidade++;
    return 1;
}

void listarTarefas(ListaTarefas lista) {
    if (lista.quantidade == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    } else {
        printf("Lista de Tarefas:\n");
        for (int i = 0; i < lista.quantidade; i++) {
            printf("ID: %d\tDescricao: %-50s\tStatus: %d (%s)\tPrazo: %s\n",
                   lista.tarefas[i].id,
                   lista.tarefas[i].descricao,
                   lista.tarefas[i].status,
                   getStatusString(lista.tarefas[i].status),
                   lista.tarefas[i].prazo);
        }
    }
}

int removerPosicao(ListaTarefas *lista, int posicao) {
    if (posicao < 0 || posicao >= lista->quantidade) {
        printf("Posicao invalida.\n");
        return 0;
    }

    for (int i = posicao; i < lista->quantidade - 1; i++) {
        lista->tarefas[i] = lista->tarefas[i + 1];
    }
    lista->quantidade--;
    printf("Tarefa removida com sucesso.\n");
    return 1;
}

int removerValor(ListaTarefas *lista, int id) {
    int i, encontrado = 0;
    for (i = 0; i < lista->quantidade; i++) {
        if (lista->tarefas[i].id == id) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < lista->quantidade - 1; j++) {
            lista->tarefas[j] = lista->tarefas[j + 1];
        }
        lista->quantidade--;
        printf("Tarefa removida com sucesso.\n");
        return 1;
    } else {
        printf("Tarefa com ID %d nao encontrada.\n", id);
        return 0;
    }
}

int procurar(ListaTarefas lista, int id) {
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.tarefas[i].id == id) {
            return i; // Retorna a posição se encontrado
        }
    }
    return -1; // Retorna -1 se não encontrado
}

int tamanho(ListaTarefas lista) {
    return lista.quantidade;
}

void liberarMemoria(ListaTarefas *lista) {
    free(lista->tarefas);
    lista->quantidade = 0;
    lista->capacidade = 0;
}

void salvarEmArquivo(ListaTarefas lista) {
    FILE *arquivo = fopen("tarefas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lista.quantidade; i++) {
        fprintf(arquivo, "%d;%s;%d;%s\n",
                lista.tarefas[i].id,
                lista.tarefas[i].descricao,
                lista.tarefas[i].status,
                lista.tarefas[i].prazo);
    }

    fclose(arquivo);
    printf("Dados salvos em arquivo.\n");
}

void carregarDeArquivo(ListaTarefas *lista) {
    FILE *arquivo = fopen("tarefas.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado.\n");
        return;
    }

    Tarefa tarefa;

    while (fscanf(arquivo, "%d;%49[^;];%d;%10s\n", &tarefa.id, tarefa.descricao, &        tarefa.status, tarefa.prazo) == 4) {
        inserirFim(lista, tarefa);
    }

    fclose(arquivo);
    printf("Dados carregados do arquivo.\n");
}

void atualizarArquivo(ListaTarefas lista) {
    FILE *arquivo = fopen("tarefas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lista.quantidade; i++) {
        fprintf(arquivo, "%d;%s;%d;%s\n",
                lista.tarefas[i].id,
                lista.tarefas[i].descricao,
                lista.tarefas[i].status,
                lista.tarefas[i].prazo);
    }

    fclose(arquivo);
    printf("Arquivo atualizado com sucesso.\n");
}

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
        printf("9. Sair e Salvar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                printf("Descricao: ");
                getchar(); // Consumir a quebra de linha pendente do buffer
                fgets(tarefa.descricao, sizeof(tarefa.descricao), stdin);
                tarefa.descricao[strcspn(tarefa.descricao, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                inserirInicio(&lista, tarefa);
                break;
            case 2:
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                getchar(); // Consumir a quebra de linha pendente do buffer
                printf("Descricao: ");
                fgets(tarefa.descricao, sizeof(tarefa.descricao), stdin);
                tarefa.descricao[strcspn(tarefa.descricao, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                inserirFim(&lista, tarefa);
                break;
            case 3:
                printf("Informe os dados da tarefa:\n");
                printf("ID: ");
                scanf("%d", &tarefa.id);
                getchar(); // Consumir a quebra de linha pendente do buffer
                printf("Descricao: ");
                fgets(tarefa.descricao, sizeof(tarefa.descricao), stdin);
                tarefa.descricao[strcspn(tarefa.descricao, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Status (0 - pendente, 1 - em progresso, 2 - concluida, 3 - cancelada): ");
                scanf("%d", &tarefa.status);
                printf("Prazo (DD-MM-AAAA): ");
                scanf("%10s", tarefa.prazo);
                printf("Informe a posicao: ");
                scanf("%d", &pos);
                inserirPosicao(&lista, tarefa, pos);
                break;
            case 4:
                listarTarefas(lista);
                break;
            case 5:
                printf("Informe a posicao: ");
                scanf("%d", &pos);
                removerPosicao(&lista, pos);
                break;
            case 6:
                printf("Informe o ID: ");
                scanf("%d", &id);
                removerValor(&lista, id);
                break;
            case 7:
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
                printf("Tamanho da lista: %d\n", tamanho(lista));
                break;
            case 9:
                printf("Saindo do sistema...\n");
                atualizarArquivo(lista);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    liberarMemoria(&lista);

    return 0;
}

