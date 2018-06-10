#include <cstdio>
#include "const.h"

void read(bool po, int &n, int &m, double a[][MAXN]) 
{
	if (po)
		printf("Num of X = ");
	scanf("%d", &n);
	if (po)
		printf("Num of equations = ");
	scanf("%d", &m);
	if (po)
		puts("A[][]:");
	for (int i(0); i < m; ++i)
		for (int j(0); j < n; ++j)
			scanf("%lf", &a[i][j]);
	if (po)
		printf("B[]: ");
	for (int i(0); i < m; ++i)
		scanf("%lf", &a[i][n]);
}