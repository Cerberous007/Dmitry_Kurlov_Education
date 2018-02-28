struct pair_vectors
{
	int a, b, c, d;
	int d_p()
	{
		return a*c+b*d;
	}
	int c_p()
	{
		return a*d-b*c;
	}
};