// sharedptrintr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



class Data 
{
private:
	int x, cnt;
	Data(int _x) : x(_x), cnt(1) {}
	friend class ptr;
};

class ptr 
{
public:
	Data *d;
	ptr() : d(NULL) {}
	ptr(int x) : d(new Data(x)) {}
	ptr(const ptr &p) : d(p.d)
	{
		if (d)
			d->cnt++;
	}
	~ptr()
	{
		if (d) 
		{
			d->cnt--;
			if (!d->cnt)
				delete d;
		}
	}
	ptr &operator=(const ptr &p) 
	{
		if (d) 
		{
			d->cnt--;
			if (!d->cnt) 
			{
				delete d;
				d = NULL;
			}
		}
		d = p.d;
		if (d)
			d->cnt++;
		return *this;
	}
	int &operator*() 
	{
		if (d)
			return d->x;
	}
};

int main() 
{
	ptr p1(200), p2;
	p2 = p1;
	printf("p1: %d\np2: %d\n", *p1, *p2);
	*p2 = 3;
	printf("p1: %d\np2: %d\n", *p1, *p2);
	printf("p2: %d\n", *p2);
	p2 = ptr(15);
	printf("p2: %d\n", *p2);
	return 0;
}
