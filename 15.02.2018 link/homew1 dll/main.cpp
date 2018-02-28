#include <cstdio>
#include"win64.h"
#include "func.h"

int main() {
	long long p, a, s, z, y, t, b, c;
	int i, n, e;
	bool f;
	do {
		printf("p = ");
		scanf(I64d, &p);
		f = prime(p);
		if (!f)
			printf("p is not odd prime!\n");
	} while (!f);
	for (z = 3; (z < p) && leg_symb(z, p); ++z);
	do {
		printf("a = ");
		scanf(I64d, &a);
		f = leg_symb(a,p);
		if (!f)
			printf("a is not quadratic residue!\n");
	} while (!f);
	for (e = 1; !((p - 1) % (1 << e)); ++e);
	s = (p - 1) / (1 << --e);
	y = pw(a, (s + 1) >> 1, p), t = pw(a, s, p);
	printf("e = %d, s = " I64d "\nz = " I64d "\ny = " I64d ", t = " I64d "\n\n", e, s, z, y, t);
	long long tt;
	n = e, c = pw(z, s, p);
	while (t != 1) {
		tt = t;
		for (i = 0; tt != 1; ++i)
			tt = (tt * tt) % p;
		printf("t != 1, i = %d\n", i);
		b = pw(c, 1 << (n - 1 - i), p);
		y = y * b % p, c = b * b % p,  n = i;
		t = t * c % p;
		printf("b = " I64d "\ny = " I64d ", c = " I64d ", t = " I64d ", n = %d\n--------------------\n", b, y, c, t, n);
	}
	printf("t = 1 => x := +-y = " I64d ", " I64d, y, p - y);
	return 0;
}