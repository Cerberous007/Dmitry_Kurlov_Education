class quaternions
{
	private:
	double a, b, c, d;
	public:
	quaternions() : a(0), b(0), c(0), d(0) {}
	quaternions(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}
	quaternions &operator+=(const quaternions &x);
	quaternions &operator*=(const quaternions &x);
	quaternions &operator*=(const double x);	
	quaternions &operator-=(const quaternions &x);
	double abs();	
	void print(const char msg[]);
};