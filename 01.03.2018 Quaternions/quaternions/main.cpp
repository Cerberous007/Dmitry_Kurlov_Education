#include<cstdio>
#include<cmath>
#include"quaternions.h"
#include"func.h"

int main()
{
	quaternions a(-1, -2, 5, 4), b(1, 1, 1, 3);
	a.print("a= ");
	b.print("b= ");
	printf("abs a: %.4f\n", sqrt(a.abs()));
	(a + b).print("a + b: ");
	(a - b).print("a - b: ");
	(a * b).print("a * b: ");
	(b * a).print("b * a: ");
	return 0;		
}