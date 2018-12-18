#include <thread>
#include <chrono>
#include <cstdio>

using namespace std;

typedef future<int, IntFunc> FuncFuture;


template <typename T, class F>
class future {
	thread *t;
	T *data;	
	public:
	future() {
		F temp;
		data = new T();
		t = new thread(temp, data);
	}
	future(future &&other) : t(other.t), data(other.data) {}
	T &get() {
		t->join();
		return *data;
	}
	~future(){
		delete t;
		delete data;
	}
};

class IntFunc {
	public:
	void operator()(int *data) {
		this_thread::sleep_for(3s);
		*data = 2315;
	}
};                                       

void foo(FuncFuture &&x) {
	printf("%d", x.get());
}

int main() {
	FuncFuture f;
	puts("hochu dopusk!");
	foo(move(f));
	return 0;
}