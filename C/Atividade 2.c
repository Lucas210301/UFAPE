#include <stdio.h>

int main() {
    int num1, num2;
    int sumOfCubes, cubeOfSum, difference;

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &num1);

    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);

    sumOfCubes = (num1 * num1 * num1) + (num2 * num2 * num2);
    cubeOfSum = (num1 + num2) * (num1 + num2) * (num1 + num2);
    difference = cubeOfSum - sumOfCubes;

    printf("A diferen�a entre o cubo da soma e a soma dos cubos de %d e %d � %d.\n", num1, num2, difference);

    return 0;
}
