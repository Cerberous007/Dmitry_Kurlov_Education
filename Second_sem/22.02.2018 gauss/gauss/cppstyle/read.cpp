#include<cstdio>
#include"gauss.h"

void gauss::read(int po)
{
	if(po)
		printf("Num of columns= ");
	scanf("%d", &n);
	if(po)
		printf("Num of linew= ");
	scanf("%d", &m);
	if(po)
		puts("A[][]:");
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%f", &a[i][j]);
	if(po)
		printf("B[]: ");
	for(int i=0; i<m; i++)
		scanf("%f", &a[i][n]);						
}