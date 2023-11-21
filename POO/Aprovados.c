#include <stdio.h>

int main() {
    int aprovados = 0;

    while (1) {
        int acertos_portugues, acertos_matematica;
        float nota_redacao;

        if (scanf("%d", &acertos_portugues) != 1 || acertos_portugues < 0) {
            break;
        }

        if (scanf("%d", &acertos_matematica) != 1) {
            break;
        }

        if (scanf("%f", &nota_redacao) != 1) {
            break;
        }

        if (acertos_portugues * 2 >= 80 && acertos_matematica * 100 / 35 >= 60 && nota_redacao >= 7.0) {
            aprovados++;
        }
    }

    printf("%d\n", aprovados);

    return 0;
}