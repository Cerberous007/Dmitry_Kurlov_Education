#include "func.h"
#include "const.h"

double a[MAXN][MAXN], x[MAXN];
int v[MAXN];

int main(int argc, const char *argv[]) {
	int n, m;
	read(parse_opt(argc, argv), n, m, a);
	int k, row, col;
	double rel;
	for (row = col = 0; row < m && col < n; ++col) {
		k = row;
		for (int i(row); i < m; ++i)
			if (abs(a[k][col]) < abs(a[i][col]))
				k = i;
		if (abs(a[k][col]) < EPS) {
			v[col] = -1;
			continue;
		}
		v[col] = row;
		if (k != row)
			for (int i(0); i <= n; ++i) {
				double t(a[k][i]);
				a[k][i] = a[row][i];
				a[row][i] = t;
			}
		for (int i(0); i < m; ++i)
			if (i != row) {
				rel = a[i][col] / a[row][col];
				for (int j(col); j <= n; ++j)
					a[i][j] -= a[row][j] * rel;
			}
		row++;
	}
	int ans(1);
	for (int i(0); i < n; ++i)
		if (v[i] < 0)
			x[i] = 0, ans = -1;
		else
			x[i] = a[v[i]][n] / a[v[i]][i];
	for (int i(0); i < m; ++i) {
		rel = 0;
		for (int j(0); j < n; ++j)
			rel += x[j] * a[i][j];
		if (abs(rel - a[i][n]) > EPS) {
			ans = 0;
			break;
		}
	}
	print_ans(ans, n, x);
	return 0;
}