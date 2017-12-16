// реализациярациональныхчисел.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {

	while (a != b) {
		if (a > b) {
			long tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}


int lcm(int a, int b) 
{
	return (a * b) / (gcd(a, b));
}

struct Quo
{
	int n;
	int m;
	void norm()
	{
		int d = gcd(n, m);
		n /= d;
		n /= d;
	}	
};
struct Quo(int N, int M) : n(N), m(M)
{
	{
		norm();
		if (m < 0)
			m *= -1, n *= -1;
	}
	void print() {
		if (m == 1)
			printf("%d", n);
		else
			printf("%d/%d", n, m);
	}
	struct Quo operator+(const Quo sec) {
		int l(lcm(m, sec.m));
		int x(l / m), y(l / sec.m);
		return Quo(n * x + sec.n * y, l);
	}
	Quo operator-(const Quo sec) {
		int l(lcm(m, sec.m));
		int x(l / m), y(l / sec.m);
		return Quo(n * x - sec.n * y, l);
	}
	Quo operator*(const Quo sec) {
		return Quo(n * sec.n, m * sec.m);
	}
	Quo operator/(const Quo sec) {
		return Quo(n * sec.m, m * sec.n);
	}
};


int main()
{
	int a, b, c, d;
	scanf_s("%d%d%d%d", &a, &b, &c, &d);
	Quo p(a, b), q(c, d);
	printf("p = ");
	p.print();
	printf(" q = ");
	q.print();
	printf("\np + q = ");
	(p + q).print();
	printf("\np - q = ");
	(p - q).print();
	printf("\np * q = ");
	(p * q).print();
	printf("\np / q = ");
	(p / q).print();

    return 0;
}

