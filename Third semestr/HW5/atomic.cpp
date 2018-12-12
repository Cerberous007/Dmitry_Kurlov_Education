// atomic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<mutex>
#include<iostream>

using namespace std;

template<typename T>
class Atomic {
	std::mutex M;	
		T data;
	public:
		T operator=(const T value) {
			M.lock();
			data = value;
			M.unlock();
			return data;
		}
		operator T() const noexcept {
			return data;
		}
};

int main()
{
	Atomic<int> a;
	a = 2;
	int d = a + 123442;
	printf("%d", d);
    return 0;
}