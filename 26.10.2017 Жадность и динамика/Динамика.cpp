// Динамика.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"math.h"

int decomp(int x)
{
	int sum=0;
	int *optDecomp = new int[x + 1];
	int *square = new int[x+2];
	int j = 0;
	for(; j*j<=x; ++j)
	{
		square[j] = j*j;
	}
	square[j] = j*j;
	for (int i = 0; i <= x; ++i)
	{
		optDecomp[i] = i;
	}	
	for (int i = 2; i <= x; ++i)
	{
		for (int k = 1; i >= square[k]; ++k)
		{
			optDecomp[i] = (optDecomp[i] < optDecomp[i - square[k]] + 1) ? optDecomp[i] : optDecomp[i - square[k]] + 1;
		}
	}
	for (int i = x; i > 0;)
	{
		for (int k = 1; i >= square[k]; ++k)
		{
			if (optDecomp[i-square[k]] == optDecomp[i] - 1)
			{
				printf("%d\n", square[k]);
				sum += k;
				i -= square[k];
			}
		}
	}
	delete[] optDecomp;
	delete[] square;
	return sum;
}



int main()
{
	int a;
	printf("Number >0\n");
	scanf_s("%d", &a);
	a = decomp(a);
	printf("%d sum ai\n", a);

    return 0;
}

