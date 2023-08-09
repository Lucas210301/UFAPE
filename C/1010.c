#include <stdio.h>

int main() {
    int codigo, quantidade;
    double valor, total;

    scanf("%i %i %lf", &codigo, &quantidade, &valor);
    total = quantidade * valor;

    scanf("%i %i %lf", &codigo, &quantidade, &valor);
    printf("VALOR A PAGAR: R$ %.2lf\n", total + quantidade * valor);
}
