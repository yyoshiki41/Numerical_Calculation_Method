#include <stdio.h>

#define n 3  // 求める連立方程式の解の数
#define n1 4 // 求める連立方程式の解の数＋１

int main(void)
{
	int i, j, k;
	double a[n1][n1] = {
		{0, 0, 0, 0}, // 行列成分と整合性を取るため
		{0, 3, 6, 2},
		{0, 2, 1, -1},
		{0, 4, 3, 8},
	};
	double b[n1] = {0, 4, -3, 1};
	double x[n1], w, m, s;

	// 求める連立1次方程式を行列で表す
	printf("\nA | b\n");
	for(j = 1; j < n1 ; j++) {
		for(i = 1; i < n1; i++) {
			printf("% 5.2f ", a[j][i]);
		}
		printf(" | % 5.2f\n", b[j]);
	}

	// Forward elimination (前進消去)
	for(k = 1; k <= n - 1; k++) {
		w = 1 / a[k][k];
		for(i = k + 1; i <= n; i++) {
			m = a[i][k] * w;
			/*
			 * 行列の成分が0になる様子を見る
			 * 実際に計算に用いる場合は効率を考えて
			 * for(j=k+1;j<=n;j++)
			 * とする.
			 */
			for(j = 1; j <= n; j++) {
				a[i][j] -= m * a[k][j];
			}

			b[i] -= m * b[k];
		}

		// for debug (処理中の連立方程式を出力)
		printf("\nA | b\n");
		for(j = 1; j < n1; j++) {
			for(i = 1; i < n1; i++) {
				printf("% 5.2f ", a[j][i]);
			}
			printf(" | % 5.2f\n", b[j]);
		}
	}

	// Backward substitution (後退代入)
	x[n] = b[n] / a[n][n];
	for(k = n - 1; k >= 1; k--) {
		s = 0;
		for(j = k + 1; j <= n; j++) {
			s += a[k][j] * x[j];
		}

		x[k] = (b[k] - s) / a[k][k];
	}

	// 解を出力
	printf("\n");
	for(i = 1; i <= n; i++) {
		printf("x[%d] = %f \n", i, x[i]);
	}

	return 0;
}
