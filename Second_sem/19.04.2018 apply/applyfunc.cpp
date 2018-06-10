// applyfunc.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

using namespace std;

template <typename T>
void apply(void(*f)(T&), T &x) 
{
	f(x);
}

template <typename T, size_t S>
void apply(void(*f)(T&), T a[]) 
{
	for (size_t i(0); i < S; ++i)
		apply<T>(f, a[i]);
}

template <typename T, typename U>
void apply(void(*f)(T&), U &x) 
{
	for (auto &it : x)
		apply<T>(f, it);
}

template<typename T>
void gen_rand(T &x) 
{
	x = rand() % 150 + rand() * 1.0 / rand();
}

template<typename T>
void print(T &x) 
{
	cout << x << ' ';
}

vector <int> v(10);
list <int> l(5);

int main() {
	srand(time(NULL));
	cout << fixed << setprecision(1);
	puts("Random generate");

	puts("Single element:");
	int x;
	apply<int>(&gen_rand, x);
	apply<int>(&print, x);

	puts("\nArray double[10]:");
	double a[10];
	apply<double, 10>(&gen_rand, a);
	apply<double, 10>(&print, a);

	puts("\nList<int>(5):");
	list <int> l(5);
	apply<int, list<int> >(&gen_rand, l);
	apply<int, list<int> >(&print, l);

	puts("\nVector<double>(15):");
	vector <double> v(15);
	apply<double, vector<double> >(&gen_rand, v);
	apply<double, vector<double> >(&print, v);
	return 0;
}

