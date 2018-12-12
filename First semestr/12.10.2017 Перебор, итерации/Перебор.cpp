// Перебор.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void print(int d) {
	for (int r=d ; r < 10; ++r)
	{
		for (int c=0; c < 10; ++c)
		{
			for (int b=0; b < 10; ++b)
			{
				for (int g=0; g + b < 10 - (c + d) % 10; ++g)
				{
					for (int a=0; a < 10; ++a)
					{
						printf("%d%d%d5%d\n0%d%d%d%d\n%d%d%d5%d\n\n", a, b, c, d, g, d, d, r, a, b + g, c, r - (d > 0));
					}
				}
			}
		}
	}
}

int main() {
	print(0);
	print(9);
	return 0;
}
