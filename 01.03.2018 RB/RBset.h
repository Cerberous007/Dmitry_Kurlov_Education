#include <cstdlib>

class RBset;
typedef RBset *pset;

class RBset {
	private:
	double key;
	bool color;
	pset left, right, parent;
	pset grandparent();
	pset uncle();
	pset sibling();
	pset rotate_left();
	pset rotate_right();
	pset insert1();
	pset insert2();
	pset insert3();
	pset erase1();
	friend void clear(pset);
	friend void print(pset, int, int);
	friend RBset operator+(RBset, RBset);
	friend RBset operator*(RBset, RBset);
	public:
	RBset(const RBset &t);
	RBset(double _key, bool _color) : key(_key), color(_color), left(NULL), right(NULL), parent(NULL) {}
	RBset(double _key) : RBset(_key, true) {}
	RBset() : RBset(0) {}
	~RBset();
	pset insert(double k);
	pset erase(double k);
	pset check(double k);
};