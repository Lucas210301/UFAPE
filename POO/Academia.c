#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente {
    char nome[51];
    int senha;
    char situacao;
};

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;

    // Cadastro dos clientes
    char buffer[51]; // Usado para ler a entrada da linha do nome
    while (1) {
        if (numClientes >= MAX_CLIENTES) {
            break;
        }

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        // Remover a quebra de linha do nome
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "SAIR") == 0) {
            break;
        }

        strcpy(clientes[numClientes].nome, buffer);

        if (scanf("%d\n", &clientes[numClientes].senha) != 1) {
            break;
        }

        if (scanf("%c\n", &clientes[numClientes].situacao) != 1) {
            break;
        }

        numClientes++;
    }

    // Verifica��o das senhas de acesso
    int senha;
    while (1) {
        if (scanf("%d", &senha) != 1) {
            break;
        }

        if (senha == -1) {
            break;
        }

        int clienteEncontrado = 0;

        for (int i = 0; i < numClientes; i++) {
            if (clientes[i].senha == senha) {
                clienteEncontrado = 1;
                if (clientes[i].situacao == 'P') {
                    printf("%s, seja bem-vindo(a)!\n", clientes[i].nome);
                } else {
                    printf("N�o est� esquecendo de algo, %s? Procure a recep��o!\n", clientes[i].nome);
                }
                break;
            }
        }

        if (!clienteEncontrado) {
            printf("Seja bem-vindo(a)! Procure a recep��o!\n");
        }
    }

    return 0;
}