#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_DISCIPLINAS 20
#define NOTA 7.5

typedef struct Disciplina {
    char codigo[25];
    char nome[100];
    int matriculados;
} Disciplina;

typedef struct Aluno {
    char codigo[30];
    char nome[500];
    int idade;
    int sexo;
    double nota;
    Disciplina* disciplinas[MAX_DISCIPLINAS];
    int numDisciplinas;
} Aluno;

typedef struct Lista {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos;
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int numDisciplinas;
    int numMatriculas;
} Lista;

typedef struct Resultados {
    int sexoM;
    int sexoF;
    double somaIdades;
    double somaIdadesNotas;
    int numAlunosNotas;
} Resultados;

void inicializarAluno(Aluno *aluno) {
    aluno->numDisciplinas = 0;
}

void inicializarDisciplina(Disciplina *disciplina) {
    disciplina->matriculados = 0;
}

void inicializarResultado(Resultados *resultado) {
    resultado->sexoM = 0;
    resultado->sexoF = 0;
    resultado->somaIdades = 0;
    resultado->somaIdadesNotas = 0;
    resultado->numAlunosNotas = 0;
}

void contabilizarResultados(Resultados *resultado, Aluno *aluno) {
    if (aluno->sexo == 0) {
        ++resultado->sexoF;
    } else {
        ++resultado->sexoM;
    }

    resultado->somaIdades += aluno->idade;

    if (aluno->nota >= NOTA) {
        resultado->somaIdadesNotas += aluno->idade;
        ++resultado->numAlunosNotas;
    }
}

void buscarAlunos(Lista *lista, int pos) {
    for (int i = 0; i < lista->numAlunos; ++i) {
        for (int j = 0; j < lista->alunos[i].numDisciplinas; ++j) {
            if (lista->alunos[i].disciplinas[j] == &lista->disciplinas[pos]) {
                printf("%s\n", lista->alunos[i].nome);
            }
        }
    }
}

void imprimirResultados(Resultados *resultado, Lista *lista) {
    printf("%d\n", resultado->sexoM);
    printf("%d\n", resultado->sexoF);

    double mediaIdades = resultado->somaIdades / lista->numAlunos;
    printf("%.2lf\n", mediaIdades);

    if (resultado->numAlunosNotas > 0) {
        double mediaIdadesNotas = resultado->somaIdadesNotas / resultado->numAlunosNotas;
        printf("%.2lf\n", mediaIdadesNotas);
    } else {
        printf("N/A\n");
    }

    for (int i = 0; i < lista->numDisciplinas; ++i) {
        printf("%s\n%d\n", lista->disciplinas[i].nome, lista->disciplinas[i].matriculados);
        buscarAlunos(lista, i);
    }
}

void cadastrarAluno(Aluno *aluno, Resultados *resultado) {
    inicializarAluno(aluno);
    scanf("%s", aluno->codigo);
    getchar();
    gets(aluno->nome);
    scanf("%d", &aluno->idade);
    getchar();
    scanf("%d", &aluno->sexo);
    getchar();
    scanf("%lf", &aluno->nota);
    getchar();
    contabilizarResultados(resultado, aluno);
}

void cadastrarDisciplinas(Disciplina *disciplina) {
    inicializarDisciplina(disciplina);
    scanf("%s", disciplina->codigo);
    getchar();
    gets(disciplina->nome);
}

void matricular(char *codAluno, char *codDisciplina, Lista *lista) {
    for (int i = 0; i < lista->numAlunos; ++i) {
        if (strcmp(lista->alunos[i].codigo, codAluno) == 0) {
            for (int j = 0; j < lista->numDisciplinas; ++j) {
                if (strcmp(lista->disciplinas[j].codigo, codDisciplina) == 0) {
                    lista->alunos[i].disciplinas[lista->alunos[i].numDisciplinas] = &lista->disciplinas[j];
                    ++lista->alunos[i].numDisciplinas;
                    ++lista->disciplinas[j].matriculados;
                }
            }
        }
    }
}

void ordenarAlunos(Lista *lista) {
    int n = lista->numAlunos;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strcmp(lista->alunos[j].nome, lista->alunos[j + 1].nome) > 0) {
                Aluno temp = lista->alunos[j];
                lista->alunos[j] = lista->alunos[j + 1];
                lista->alunos[j + 1] = temp;
            }
        }
    }
}

void ordenarDisciplinas(Lista *lista) {
    int n = lista->numDisciplinas;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strcmp(lista->disciplinas[j].nome, lista->disciplinas[j + 1].nome) > 0) {
                Disciplina temp = lista->disciplinas[j];
                lista->disciplinas[j] = lista->disciplinas[j + 1];
                lista->disciplinas[j + 1] = temp;
            }
        }
    }
}

int main() {
    Lista lista;
    Resultados resultado;
    int i;
    char codAluno[30], codDisciplina[25];

    inicializarResultado(&resultado);

    scanf("%d", &lista.numAlunos);
    getchar();

    for (i = 0; i < lista.numAlunos; ++i) {
        cadastrarAluno(&lista.alunos[i], &resultado);
    }

    scanf("%d", &lista.numDisciplinas);
    getchar();

    for (i = 0; i < lista.numDisciplinas; ++i) {
        cadastrarDisciplinas(&lista.disciplinas[i]);
    }

    ordenarAlunos(&lista);
    ordenarDisciplinas(&lista);

    scanf("%d", &lista.numMatriculas);
    getchar();

    for (i = 0; i < lista.numMatriculas; ++i) {
        scanf("%s %s", codAluno, codDisciplina);
        matricular(codAluno, codDisciplina, &lista);
    }

    imprimirResultados(&resultado, &lista);

    return 0;
}
