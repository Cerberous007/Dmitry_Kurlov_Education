// races.cpp: определяет точку входа для консольного приложения.
//

//C мьютексами все четко работает!

#include "stdafx.h"
#include <cassert>
#include<thread>
#include<iostream>
#include<mutex>
using namespace std;

int result = 0;
mutex m;

void foo() {
	for (int i = 0; i < 1000000; ++i) {
		m.lock();
		result += i;
		m.unlock();
	}
}

void bar() {
	for (int i = 0; i < 1000000; ++i) {
		m.lock();
		result -= i;
		m.unlock();
	}
}

int main() {
	std::thread th1(foo);
	std::thread th2(bar);

	th1.join();
	th2.join();
	cout << result << endl;
	assert(result == 0);

	cout << "Done.\n";
}