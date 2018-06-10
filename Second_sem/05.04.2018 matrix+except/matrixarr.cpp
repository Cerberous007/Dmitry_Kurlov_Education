// matrixarr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

#ifndef EXCEPT
#include "sum.h"
const size_t s3(2), s4(5);
#else
#include "sum_except.h"
const size_t s3(3), s4(5);
#endif

const size_t s1(2), s2(5);

int main() {
	srand(time(NULL));
	matrix <int, s1, s2> a;
	matrix <int, s3, s4> b;
	matrix <int, s4, s3> c;
	matrix <double, 1, s1> v1;
	matrix <double, 1, s3> v2;
	a.random(), b.random(), c.random(), v1.random(), v2.random();

	a.print("A:");
	b.print("B:");
	c.print("C:");

	auto s = a + b;
	s.print("A + B:");

	auto r = a * c;
	r.print("A * C:");

	return 0;
}