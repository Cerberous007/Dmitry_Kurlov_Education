// количествопутей.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

const int st[6][2] = { { 1, 0 },{ 2, 0 },{ 1, 1 },{ 2, 2 },{ 0, 1 },{ 0, 2 } };

int main() 
{
	int n, m, sx, sy, fx, fy, a[100][100], d[100][100];
	memset(d, 0, sizeof d);
	scanf_s("%d%d%d%d%d%d", &n, &m, &sx, &sy, &fx, &fy);	
	for (int i = 2; i < n + 2; ++i)
		for (int j = 2; j < m + 2; ++j)
			d[i][j] = 0;
	for (int i=2; i < n + 2; ++i)
		for (int j=2; j < m + 2; ++j)
			scanf_s("%d", &a[i][j]);
	d[++sx][++sy] = 1, fx++, fy++;
	for (int i=sx; i <= fx; ++i)
		for (int j=sy; j <= fy; ++j) 
		{
			if (!a[i][j])
			{
				d[i][j] = 0;
				continue;
			}
			for (int k=0; k < 6; ++k)
				d[i + st[k][0]][j + st[k][1]] += d[i][j];
		}
	printf("%d", d[fx][fy]);
	return 0;
}