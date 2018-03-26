#include <algorithm>
#include <cmath>
#include "gauss.h"

using namespace std;

int gauss::calc()
 {
	int k, row, col;
	double rel;
	for (row = col = 0; row < m && col < n; ++col) 
	{
		k = row;
		for (int i=row; i < m; ++i)
			if (abs(a[k][col]) < abs(a[i][col]))
				k = i;
		if (abs(a[k][col]) < EPS)
		{
			v[col] = -1;
			continue;
		}
		v[col] = row;
		if (k != row)
			swap(a[k], a[row]);
		for (int i=0; i < m; ++i)
			if (i != row) {
				rel = a[i][col] / a[row][col];
				for (int j(col); j <= n; ++j)
					a[i][j] -= a[row][j] * rel;
			}
		row++;
	}
	int res(1);
	for (int i=0; i < n; ++i)
		if (v[i] < 0)
			x[i] = 0, res = -1;
		else
			x[i] = a[v[i]][n] / a[v[i]][i];
	for (int i(0); i < m; ++i) 
	{
		rel = 0;
		for (int j(0); j < n; ++j)
			rel += x[j] * a[i][j];
		if (abs(rel - a[i][n]) > EPS)
		{
			res = 0;
			break;
		}
	}
	return res;
}