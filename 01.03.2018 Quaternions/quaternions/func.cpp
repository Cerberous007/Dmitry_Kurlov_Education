#include"quaternions.h"
#include"func.h"

quaternions operator+(quaternions a,const quaternions &b)
{
	a+=b;
	return a;
}
quaternions operator*(quaternions a,const quaternions &b)
{
	a*=b;
	return a;
}
quaternions operator*(quaternions a, const double b)
{
	a*=b;
	return a;
}
quaternions operator*(const double a, quaternions b)
{
	return a*b;
}
quaternions operator-(quaternions a,const quaternions &b)
{
	a-=b;
	return a;
}