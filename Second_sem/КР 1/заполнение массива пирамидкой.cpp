// заполнениемассивапирамидкой.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int comparison(int a, int b, int c);
int main()
{
	int n, i=0, j=0;
	cin >> n;
	int **arr = new int*[n];
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = comparison(i, j, n);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << arr[i][j]<<" ";
			if (arr[i][j] < 10)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
    return 0;
}
int comparison(int a, int b, int c)
{
	if (a <= b&&a<= c-1 -b&&a<= c - a)
	{
		return a+1;
	}
	if (b <= a&&b <= c-1 - a&&b <= c - b)
	{
		return b+1 ;
	}
	if (c - a <= a&&c - a <= b&&c - a <= c - b)
	{
		return c - a;
	}
	if (c - b <= a&&c - b <= b&&c - b <= c - a)
	{
		return c - b ;
	}
}


