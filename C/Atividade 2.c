#include <stdio.h>

int main() {
    int num1, num2;
    int sumOfCubes, cubeOfSum, difference;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    sumOfCubes = (num1 * num1 * num1) + (num2 * num2 * num2);
    cubeOfSum = (num1 + num2) * (num1 + num2) * (num1 + num2);
    difference = cubeOfSum - sumOfCubes;

    printf("A diferença entre o cubo da soma e a soma dos cubos de %d e %d é %d.\n", num1, num2, difference);

    return 0;
}
