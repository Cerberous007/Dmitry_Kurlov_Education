// atomic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cassert>
#include<thread>
#include<iostream>
#include<mutex>
using namespace std;

template<typename T>
class Atomic {
	std::mutex M;
	T data;
public:
	Atomic(const T &other = T()) : data(other) {}
	Atomic(const Atomic &other) : Atomic(other.data) {}
	T operator=(const T &other) {
		M.lock();
		data = other;
		M.unlock();
		return data;
	}
	T operator+=(const T &other) {
		M.lock();		
		data += other;
		M.unlock();
		return data;
	}
	T operator-=(const T &other) {
		M.lock();
		data -= other;
		M.unlock();
		return data;
	}
	operator T() {
		M.lock();
		T res(data);
		M.unlock();
		return res;
	}
};

Atomic<int> result = 0;

void foo() {
	for (int i = 0; i < 100000; ++i) {
		result += i;
	}
}

void bar() {
	for (int i = 0; i < 100000; ++i) {
		result -= i;
	}
}

int main()
{
	std::thread th1(foo);
	std::thread th2(bar);
	th1.join();
	th2.join();
	cout << result << endl;
	assert(result == 0);
	cout << "Done.\n";	
    return 0;
}

