// задание1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int n, m;
	scanf_s("%d %d", &n, &m);
	int *a = new int[n*m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", a + i*m + j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", *(a + i*m + j));
		}
		printf("\n");
	}
	delete[] a;
    return 0;
}

