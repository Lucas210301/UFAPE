#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    double EV = 0.0;
    double sum = 0.0;

    for (int X = 1; X <= N; X++) {
        double P_X = 0.0;
        for (int i = 1; i <= X; i++) {
            P_X += i;
        }
        EV += X * P_X;
        sum += P_X;
    }

    EV /= sum;

    printf("%.2lf\n", EV);

    return 0;
}
