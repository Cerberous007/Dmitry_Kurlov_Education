#include"func.h"
bool leg_symb(long long a, long long p) {
	a = pw(a, (p - 1) >> 1, p);
	return (a == 1);
}
