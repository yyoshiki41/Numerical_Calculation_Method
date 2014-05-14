#include <stdio.h>

#define N 5 //データの個数

int main()
{
    int i;
    double a0, a1;
    double A00, A01, A02, A11, A12;

    // y = a0 + a1 * x
    double x[N] = {1.0, 2.0, 3.0, 4.0, 5.0},
           y[N] = {10.6, 15.5, 19.9, 23.8, 33.2};

    A00 = A01 = A02 = A11 = A12 = 0.0;

    for (i = 0; i < N; i++) {
        A00 += 1.0;
        A01 += x[i];
        A02 += y[i];
        A11 += x[i] * x[i];
        A12 += x[i] * y[i];
    }

    a0 = (A02 * A11 - A01 * A12) / (A00 * A11 - A01 * A01);
    a1 = (A00 * A12 - A01 * A02) / (A00 * A11 - A01 * A01);

    printf("a0 = %lf\n", a0);
    printf("a1 = %lf\n", a1);
    return 0;
}
