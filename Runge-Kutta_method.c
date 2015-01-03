#include <stdio.h>

#define h 0.01 // 刻み幅
double f1(double t, double x1, double x2);
double f2(double t, double x1, double x2);
double dx(double k1, double k2, double k3, double k4);

int main()
{
	double t;
	double x1, x2;
	double k11, k12, k21, k22, k31, k32, k41, k42;

	FILE *output;
	output = fopen("Runge-Kutta_method.txt", "w");
	x1 = x2 = 0.0;

	for (t = 0.0; t <= 10; t += h) {
		k11 = h * f1(t, x1, x2);
		k12 = h * f2(t, x1, x2);
		k21 = h * f1(t + h / 2.0, x1 + k11 / 2.0, x2 + k12 / 2.0);
		k22 = h * f2(t + h / 2.0, x1 + k11 / 2.0, x2 + k12 / 2.0);
		k31 = h * f1(t + h / 2.0, x1 + k21 / 2.0, x2 + k22 / 2.0);
		k32 = h * f2(t + h / 2.0, x1 + k21 / 2.0, x2 + k22 / 2.0);
		k41 = h * f1(t + h / 2.0, x1 + k31, x2 + k32);
		k42 = h * f2(t + h / 2.0, x1 + k31, x2 + k32);

		fprintf(output,"%lf\t%10.6f\t%10.6f\n", t, x1, x2);
		x1 += dx(k11, k21, k31, k41);
		x2 += dx(k12, k22, k32, k42);
	}

	fclose(output);

	return 0;
}

double f1(double t, double x1, double x2) {
	double d;
	d = x2;
	return d;
}
double f2(double t, double x1, double x2) {
	double d;
	d = 2 * x1 + x2 + 8;
	return d;
}
double dx(double k1, double k2, double k3, double k4) {
	double dx;
	dx = (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
	return dx;
}
