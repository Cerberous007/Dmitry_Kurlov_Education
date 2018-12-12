// сортировкабез.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b; 
	*b = t;
	//printf_s("%d %d\n", *a, *b);
}

void quicksort(int *arr, int len)
{	
	int t;	
	int i = 0, j = len-1, randElem = *(arr+len / 2);
	do
	{
		while (*(arr + i) < randElem&& i < j)
		{
			i++;
		}
		while (*(arr + j) > randElem&& i < j)
		{
			j--;
		}
		if (i <= j)
		{
			//swap(arr + i, arr + j);
			t = *(arr + i); 
			*(arr + i) = *(arr + j);
			*(arr + j) = t;
			i++; j--;
		}
	}while (i < j);
					
	if(j>0)	quicksort(arr, j);
	if(len>i) quicksort(arr + i, len - i);
}	



int main()
{
	int n;
	scanf_s("%d", &n);
	int *arr = new int[n];
	printf("Without dublicates, pls\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", arr + i);
	}
	printf("\n");
	quicksort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(arr + i));
	}
	delete[] arr;
    return 0;
}

