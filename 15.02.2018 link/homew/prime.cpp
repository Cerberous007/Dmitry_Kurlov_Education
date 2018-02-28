bool prime(long long p) {
	bool res(true);
	for (long long d(2); res && d * d <= p; ++d)
		res &= p % d > 0;
	return res;
}
