#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // É bissexto
    } else {
        return 0; // Não é bissexto
    }
}

int main() {
    int year;

    printf("Digite um ano: ");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        printf("%d é um ano bissexto.\n", year);
    } else {
        printf("%d não é um ano bissexto.\n", year);
    }

    return 0;
}

