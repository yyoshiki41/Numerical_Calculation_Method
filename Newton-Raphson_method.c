#include <stdio.h>
#include <math.h>

#define EPS 0.01

int main()
{
    double i;
    double x1, x2;
    double f1, f2, j11, j12, j21, j22, dx1, dx2, norm;

    FILE *output;
    output = fopen("Newton-Raphson_method.txt", "w");
    x1 = 0.7; // 初期値
    x2 = 1.0; // 初期値

    for (i = 0; i < 100; i++) {
        f1 = 2 * x1 * x1 * x1 + 3 * x2 * x2 * x2 - 19;
        f2 = x1 * x1 * x1 + 2 * x2 * x2 * x2 - 10;

        j11 = 6 * x1 * x1;
        j12 = 9 * x2 * x2;
        j21 = 3 * x1 * x1;
        j22 = 6 * x2 * x2;

        dx1 = (j22 * f1 - j12 * f2) / (j11 * j22 - j12 * j21);
        dx2 = (-j21 * f1 - j11 * f2) / (j11 * j22 - j12 * j21);

        norm = sqrt(dx1 * dx1 + dx2 * dx2);
        if(norm < EPS) break;

        fprintf(output,"%lf\t%lf\n", x1, x2);
        x1 -= dx1;
        x2 -= dx2;
    }

    fclose(output);

    return 0;
}
