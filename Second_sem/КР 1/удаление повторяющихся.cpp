// удалениеповторяющихся.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;


int del_duplicates(int *arr, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{			
			if (arr[i] == arr[j])
			{
				for (k = j; k < n; k++)
				{
					arr[k] = arr[k + 1];
				}
				n -= 1;
				j -= 1;
			}
		}
	}	
	return n;
}

int main()
{
	int n;
	cin >> n;
	int*arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	n = del_duplicates(arr, n);
	int *finite_arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		finite_arr[i] = arr[i];
	}
	delete[]arr;
	for (int i = 0; i < n; i++)
	{
		cout << finite_arr[i] << " ";
	}
	delete[]finite_arr;
	return 0;
}