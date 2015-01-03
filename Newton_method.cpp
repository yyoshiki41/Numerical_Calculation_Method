#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define N 2      // The number of dimensions
#define K 1000   // The number of iterations
#define EPS 0.01 // Convergence condition

double __2n_minima (double x);

int main()
{
	// Initial points
	double x[N];
	// Enter From Keyboard
	for (int n = 0; n < N; n++) {
		cin >> x[n];
	}
	// Step width coefficient
	double c = 0.01;
	double f1, f2, j11, j12, j21, j22, dx1, dx2, norm;

	// Output file
	char filepath[256];
	sprintf(filepath, "%lf,%lf.txt", x[0], x[1]);
	ofstream fout;
	fout.open(filepath);
	fout << "k\tx1\tx2" << endl;

	for (int k = 1; k < K; k++) {
		fout << k << "\t";
		fout << x[0] << "\t";
		fout << x[1] << endl;

		f1 = __2n_minima(x[0]);
		f2 = __2n_minima(x[1]);

		// Hessian matrix
		j11 = 12 * x[0] * x[0] - 32;
		j12 = 0;
		j21 = 0;
		j22 = 12 * x[1] * x[1] - 32;

		dx1 = (j22 * f1 - j12 * f2) / (j11 * j22 - j12 * j21);
		dx2 = (-j21 * f1 + j11 * f2) / (j11 * j22 - j12 * j21);

		norm = sqrt(dx1 * dx1 + dx2 * dx2);
		if(norm < EPS) break;

		x[0] = x[0] - c * dx1;
		x[1] = x[1] - c * dx2;
	}

	return 0;
}

/*
 * Differential function
 */
double __2n_minima (double x)
{
	double f;
	f = 4 * pow(x, 3) - 32 * x + 5;
	return f;
}
