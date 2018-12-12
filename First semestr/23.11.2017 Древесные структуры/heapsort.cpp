// heapsort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
using namespace std;

const int N(100);

inline void push_down(int size, int p, int a[]);
void sort(int size, int a[]);

int main() 
{
	int n, a[N];
	scanf("%d", &n);
	for (int i=0; i < n; ++i)
		scanf("%d", a + i);
	sort(n, a);
	for (int i=0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}

void push_down(int size, int p, int a[]) 
{
	int l, r;
	while ((p << 1) + 1 < size)
	{
		l = (p << 1) + 1, r = (p << 1) + 2;
		if ((r < size) && (a[l] < a[r]))
			l = r;
		if (a[p] >= a[l])
			break;
		swap(a[p], a[l]);
		p = l;
	}
}

void sort(int size, int a[])
{
	for (int i((size - 1) >> 1); i >= 0; --i)
		push_down(size, i, a);
	while (size) 
	{
		swap(a[0], a[size-- - 1]);
		for (int i((size - 1) >> 1); i >= 0; --i)
			push_down(size, i, a);
	}
}
