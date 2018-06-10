#pragma once
//matrix + matrix
template <typename T, size_t M, size_t N, size_t S, size_t L>
matrix <T, M, N> &operator+(matrix <T, M, N> &a, matrix <T, S, L> &b) 
{
	try
	{
		if (M != S || N != L)
			throw "Unavailable size";
		matrix <T, M, N> *res(new matrix <T, M, N>(a));
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				(*res)[i][j] += b[i][j];
		return *res;
	}
	catch (...)
	{
		printf("Unavailable size: [%dx%d] + [%dx%d]\n", M, N, S, L);
		return *(new matrix <T, M, N>(0));
	}
}

//vector + vector
template <typename T, size_t M, size_t N>
matrix <T, 1, M> &operator+(matrix <T, 1, M> &a, matrix <T, 1, N> &b) 
{
	try 
	{
		if (M != N)
			throw "Unavailable size";
		matrix <T, 1, M> *res(new matrix <T, 1, M>(a));
		for (size_t i(0); i < M; ++i)
			(*res)[i] += b[i];
		return *res;
	}
	catch (...)
	{
		printf("Unavailable size: [%dx%d] + [%dx%d]\n", 1, M, 1, N);
		return *(new matrix <T, 1, M>(0));
	}
}