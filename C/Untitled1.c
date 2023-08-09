- #include <stdio.h>
int main() {
int numero;
int contador = 0;
int multiplos = 0;
printf("Digite sete numeros inteiros:\n");
while (contador < 7) {
scanf("%d", &numero);
if (numero % 13 == 0) {
multiplos++;
}
contador++;
}
printf("A quantidade de numeros multiplos de 13: %d\n", multiplos);
return 0;
}
