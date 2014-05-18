#include <stdio.h>
#include <stdlib.h>

#define JMAX 200

int main()
{
    int i, j, n;
    double *u0, *u1, *u2, dt, dx, x;
    dt = 0.01;
    dx = 0.1;
    n = (int)(1.0 / dx);

    u0 = (double *)malloc((n+1) * sizeof(double));
    u1 = (double *)malloc((n+1) * sizeof(double));
    u2 = (double *)malloc((n+1) * sizeof(double));

    FILE *output;
    output = fopen("wave_equation.txt", "w");

    for (i =  0, x = 0.0; x < 0.5; x+= dx) {
        u1[i] = 2.0 * x;
        i++;
    }
    for (x = 0.5; x < 1.00001; x+= dx) {
        u1[i] = 2.0 * (1.0 - x);
        i++;
    }
    for (i = 0; i < n; i++) {
        fprintf(output,"%f\n", u1[i]);
    }
    u0[0] = 0.0;
    u0[n] = 0.0;
    for (i = 0; i < n; i++) {
        u0[i] = u1[i] + (dt * dt) * (u1[i+1] - 2 * u1[i] + u1[i-1]) / 2 / (dx * dx);
    }
    u2[0] = 0.0;
    u2[n] = 0.0;
    for (j = 0; j < JMAX; j++) {
        for (i = 1; i < n; i++) {
            u2[i] = 2 * u1[i] + u0[i] + (dt * dt) * (u1[i+1] - 2 * u1[i] + u1[i-1]) / (dx * dx);
        }
        if(j%20 == 0) {
            for (i = 0; i <= n; i++) {
                fprintf(output,"%f\n", u2[i]);
            }
        }
        for (i = 0; i <= n; i++) {
            u0[i] = u1[i];
            u1[i] = u2[i];
        }
    }

    free(u0);
    free(u1);
    free(u2);

    fclose(output);

    return 0;
}
