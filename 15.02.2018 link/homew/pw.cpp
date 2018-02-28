long long pw(long long a, long long k, long long p) {
	long long res(1);
	while (k)
		if (k & 1)
			res = res * a % p, k--;
		else
			a = a * a % p, k >>= 1;
	return res % p;
}
