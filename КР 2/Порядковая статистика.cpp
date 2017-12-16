// кр.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h" 

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int search(int *a, int k, int l, int r)
{
	int m, i = l, j = r, tmp;
	if (l == r) return a[r];
	m = a[(l + r) / 2];
	while (i < j) {
		while (a[i] < m) i++;
		while (a[j] > m) j--;
		if (i < j)
		{
			swap(a + i, a + j);
			i++; j--;
		}
	}
	if (k <= j) return search(a, k, l, j);
	else return search(a, k, j + 1, r);
}

int main()
{
	int n, m;
	printf("Enter size of array (size/7)\n");
	scanf_s("%d", &n);
	int *a = new int[(7 * n) + 1];
	for (int i = 0; i < 7 * n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	m = search(a, 4 * n, 0, 7 * n);
	printf("4k-stat = %d\n", m);
	return 0;
}