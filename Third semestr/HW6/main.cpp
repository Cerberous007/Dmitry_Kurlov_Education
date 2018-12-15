#include <condition_variable>
#include <cstdio>
#include <queue>
#include <mutex>
#include <string>
#include <fstream>
#include <thread>

using namespace std;

class DATA {
	public:
	int prior;
	string str;
	DATA() : prior(rand()) {}
	DATA(const int prior) : prior(prior) {}
};

bool operator<(const DATA&, const DATA&);

ifstream f;
priority_queue <DATA> data;
mutex M, mterm;
condition_variable Cond;
bool term(false);

bool more_data();
DATA prepare();
void process(DATA&);

void prep() {
	DATA temp;
	while (more_data()) {
		temp = prepare();
		M.lock();
		data.push(temp);
		Cond.notify_all();
	}
	mterm.lock();
	term = true;
	mterm.unlock();
}

void proc() {
	DATA temp;
	while (true) {
		//TODO unique_lock<mutex>(M);
		Cond.wait(M, [](){return !data.empty();});
		temp = data.top();
		data.pop();
		M.unlock();
		process(temp);
		mterm.lock();
		if (term)
			break;
		mterm.unlock();
	}
}

int main() { 
	f.open("in.txt");
	thread T1(&prep);
	size_t trs(5);
	scanf("%llu", &trs);
	thread *TA[trs];
	for (size_t k(0); k < trs; ++k)
		TA[k] = new thread(&proc);
	return 0;
}

bool operator<(const DATA &a, const DATA &b) {
	return a.prior < b.prior;
}

bool more_data() {
	return !f.eof();
} 

DATA prepare() {
	DATA d(rand() % 100 - 23); //IT'S IMPORTANT!
	f >> d.str;
	return d;
}

void process(DATA &d) {
	printf("%s\n", d.str.c_str());
}