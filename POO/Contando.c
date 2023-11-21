#include <stdio.h>
#include <stdlib.h>

int ContaDigitosPares(int numero) {
  /*
  Conta a quantidade de d�gitos pares em um n�mero.

  Args:
    numero: O n�mero a ser analisado.

  Returns:
    A quantidade de d�gitos pares no n�mero.
  */

  if (numero == 0) {
    return 0;
  }

  int resto = numero % 10;
  if (resto % 2 == 0) {
    return 1 + ContaDigitosPares(numero / 10);
  } else {
    return ContaDigitosPares(numero / 10);
  }
}

int main() {
  int numero;
  scanf("%d", &numero);
  int quantidade = ContaDigitosPares(numero);
  printf("%d\n", quantidade);
  return 0;
}
