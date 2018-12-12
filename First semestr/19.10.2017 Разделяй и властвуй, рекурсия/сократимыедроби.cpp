// сократимыедроби.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


long phi(long x);

int main()
{
	long n;
	scanf_s("%I32d", &n);
	printf("%I32d", n - phi(n) - 1);
	return 0;
}

 long phi( long x) 
 {
	long res=x;
	for (long d=2; d * d <= x; ++d)
		if (!(x % d)) 
		{
			while (!(x % d))
				x /= d;
			res -= res / d;
		}
	if (x > 1)
		res -= res / x;
	return res;
}

