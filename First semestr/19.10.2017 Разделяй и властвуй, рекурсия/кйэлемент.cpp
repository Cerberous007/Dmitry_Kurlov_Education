// кйэлемент.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>

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
	int s, m, i = l, j = r, tmp;
	if (l == r) return a[r];
	s = (l + r) / 2;
	m = a[s];
	while (i < j) {
		while (a[i] < m) i++;
		while (a[j] > m) j--;
		if (i < j)
		{
			swap(a+i, a+j);			
			i++; j--;
		}
	}
	if (k <= j) return search(a, k, l, j);
	else return search(a, k, j + 1, r);
}

int main()
{
	int n, k, res;
	printf("Array`s size\n");
	scanf_s("%d", &n);
	printf("enter K\n");
	scanf_s("%d", &k);
	int *arr = new int[n+1];	
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", arr + i);
	}
	printf("\n");
	res = search(arr, k, 0, n);
	/*for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(arr + i));
	}*/
	printf("a[K] = %d\n", res);
	delete[] arr;
	return 0;
}

