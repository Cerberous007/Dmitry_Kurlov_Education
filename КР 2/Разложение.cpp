// кр2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int decomp(int x)
{
	int sum = 0, j=0;
	int *optDecomp = new int[x + 6];
	int *cube_4 = new int[x + 2];	
	for (; j*j*j+4 <= x; j++)
	{
		cube_4[j] = j*j*j+4;
	}	
	cube_4[j] = j*j*j + 4;
	//memset(optDecomp, 127, sizeof optDecomp);
	optDecomp[0] = 0;
	optDecomp[1] = -1;
	optDecomp[2] = -1;
	optDecomp[3] = -1;
	optDecomp[4] = 1;
	optDecomp[5] = 1;
	for (int i = 6; i <= x; i++)
		optDecomp[i] = x;
	for (int i = 6; i <= x; i++)
	{
		bool flag = true;
		for (int k = 0; i >= cube_4[k]; k++)
		{
			if ((optDecomp[i] > optDecomp[i - cube_4[k]] + 1)&&optDecomp[i - cube_4[k]]!=-1)
			{
				optDecomp[i] = optDecomp[i - cube_4[k]] + 1;
				flag = false;
			}
		}
		if (flag)
			optDecomp[i] = -1;
	}
	if(optdecomp[x]==-1)
	{
		delete[] optDecomp;
		delete[] cube_4;
		return -1;
	}
	for (int i = x; i > 0;)
	{
		for (int k = 0; i >= cube_4[k]; k++)
		{
			if (optDecomp[i - cube_4[k]] == optDecomp[i] - 1)
			{
				printf("%d\n", cube_4[k]);
				sum += k;
				i -= cube_4[k];
			}
		}
	}
	delete[] optDecomp;
	delete[] cube_4;
	return sum;
}



int main()
{
	int a;	
	for (int i = 0; i < 20; i++)
	{
		printf("razlogenie i = %d\n", i);
		a = decomp(i);
		if (a != -1)
			printf("%d sum ai\n", a);
		else		
			printf("net razlogeni\n");		
	}
	return 0;
}

