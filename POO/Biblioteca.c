#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  char livros[n][100];
  for (int i = 0; i < n; i++) {
    scanf(" %[^\n]", livros[i]);
  }

  char livro[100]; // Corre��o: Declarar 'livro' como uma matriz de caracteres
  scanf(" %[^\n]", livro);

  int encontrado = 0;
  for (int i = 0; i < n; i++) {
    // Corre��o: Remover a tentativa de usar strtok, usar strcmp diretamente
    if (strcmp(livro, livros[i]) == 0) {
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    printf("Sim\n");
  } else {
    printf("N�o\n");
  }

  return 0;
}
