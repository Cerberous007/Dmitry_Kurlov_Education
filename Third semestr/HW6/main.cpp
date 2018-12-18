#include <condition_variable>
#include <mutex>
#include <thread>
#include <fstream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct DATA {
	size_t prior;
	string str;
	DATA(const size_t p = rand()) : prior(p), str("") {}
};

bool operator<(const DATA&, const DATA&);

ifstream infile;
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
		unique_lock<mutex> mtmp(M);
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
		unique_lock<mutex> mtmp(M);
		Cond.wait(mtmp, [](){return !data.empty();});
		temp = data.top();
		data.pop();
		M.unlock();
		process(temp);
		if (term && data.empty())
			break;
	}
}

int main() {
	srand(23917);
	infile.open("in.txt");
	size_t trs;
	scanf("%llu", &trs);
	thread t1(&prep), *ta[trs];
	for (size_t i(0); i < trs; ++i)
		ta[i] = new thread(&proc);
	t1.join();
	infile.close();
	for (size_t i(0); i < trs; ++i)
		ta[i]->join();
	return 0;
}

bool operator<(const DATA &a, const DATA &b) {
	return a.prior < b.prior;
}

bool more_data() {
	return !infile.eof();
}

DATA prepare() {
	DATA tmp;
	infile >> tmp.str;
	return tmp;
}

void process(DATA &tmp) {
	puts(tmp.str.c_str());
}