#include "const.h"

class gauss
{
	private:
	float a[MAX][MAX], x[MAX];
	int n, m, v[MAX];
	int calc();
	public:
	void read(int po);
	void write_ans();
};