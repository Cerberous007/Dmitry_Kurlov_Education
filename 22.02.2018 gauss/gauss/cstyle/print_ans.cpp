#include <cstdio>

void print_ans(int ans, int n, double x[]) {
	if (ans) {
		puts(ans > 0 ? "one sol:" : "many solut, example:");
		for (int i(0); i < n; ++i)
			printf("%.3lf ", x[i]);
	} else
		puts("not solut");
}