#include<cstdio>
#include<cstdio>
#include"quaternions.h"
#include"func.h"

quaternions &quaternions::operator+=(const quaternions &x)
{
	a+=x.a, b+=x.b, c+=x.c, d+=x.d;
	return *this;
}
quaternions &quaternions::operator*=(const quaternions &x)
{
	quaternions t(*this);
	a = t.a * x.a - t.b * x.b - t.c * x.c - t.d * x.d;
	b = t.a * x.b + t.b * x.a + t.c * x.d - t.d * x.c;
	c = t.a * x.c + t.c * x.a + t.d * x.b - t.b * x.d;
	d = t.a * x.d + t.d * x.a + t.b * x.c - t.c * x.b;
	return *this;
}
quaternions &quaternions::operator*=(const double x)
{
	a*=x; b*=x, c*=x, d*=x;
	return *this;
}
quaternions &quaternions::operator-=(const quaternions &x)
{
	a-=x.a; b-=x.b, c-=x.c, d-=x.d;
	return *this; 
}
double quaternions::abs()
{
	return a*a+b*b+c*c+d*d;
}
void quaternions::print(const char msg[]) 
{
	printf("%s%.4f %.4f %.4f %.4f\n", msg, a, b, c, d);
}
