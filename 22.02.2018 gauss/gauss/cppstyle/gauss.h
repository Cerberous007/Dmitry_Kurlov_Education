#include "const.h"

class guss
{
	private:
	float a[MAX][MAX], x[MAX];
	int n, m, v[MAX];
	int calc();
	public:
	void read(int po);
	void write_ans();
}