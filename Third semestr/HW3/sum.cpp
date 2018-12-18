// sum.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<thread>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

typedef std::thread *pthread;

inline void Time(const char *msg);
inline void parallel_add(double*, size_t);
inline void serial_add(double*, size_t);
void sum(double*, size_t, double*);

double Rand() {
	return rand() % 239 * 1. / (rand() % 239 + 1);
}

void rand_array(double *a, double n) {
	Time("Generation begin:");
	for (int i = 0; i < n; i++) {
		a[i] = Rand();
	}
	Time("Generation end:");
}

inline void Time(const char *msg) {
	static size_t t(0);
	std::cout << msg << (float)(clock() - t) / CLK_TCK << '\n';
	t = clock();
}

void sum(double *a, size_t step, double *res) {
	for (size_t i(0); i < step; ++i)
		*res += a[i];
}

void serial_add(double *a, size_t n, size_t cnt) {
	double sum = 0;
	Time("Serial add begin:");
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	Time("Serial add end:");
	printf("Sum = %lf\n", sum);
}

void parallel_add(double *a, size_t n, size_t cnt) {
	size_t step((n + 19) / 20); //optimal on my laptop 
	size_t size = n / step + (n % step ? 1 : 0);
	pthread *Thrs = new pthread[size];
	double *res = new double[size];
	double ans(0);
	Time("Parallel add begin:");	
	for (size_t i = 0, k = 0; k < n; ++i, k += step) {
		res[i] = 0;
		Thrs[i] = new std::thread(&sum, a + k, min(step, n - k), res + i);
	}
	ans = 0;
	for (size_t i(0); i < size; ++i) {
		Thrs[i]->join();
		ans += res[i];
	}	
	printf("Sum = %lf\n", ans);
	Time("Parallel add end:");
	delete res;
	delete Thrs;
}


int main()
{
	srand(time(NULL));
	//ofstream fout;
	//fout.open("in.txt");
	long long int n = 200000000;
	double *arr = new double[n];
	rand_array(arr, n);
	/*for (int i = 0; i < n; i++)
		fout << arr[i];
	fout.close();*/
	serial_add(arr, n);
	parallel_add(arr, n);
	delete arr;
    return 0;
}
