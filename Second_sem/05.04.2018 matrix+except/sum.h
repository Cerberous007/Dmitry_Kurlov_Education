#pragma once

//matrix + matrix
template <typename T, size_t M, size_t N>
matrix <T, M, N> &operator+(matrix <T, M, N> &a, matrix <T, M, N> &b) 
{
	matrix <T, M, N> *res(new matrix <T, M, N>(a));
	for (size_t i(0); i < M; ++i)
		for (size_t j(0); j < N; ++j)
			(*res)[i][j] += b[i][j];
	return *res;
}

//vector + vector
template <typename T, size_t M>
matrix <T, 1, M> &operator+(matrix <T, 1, M> &a, matrix <T, 1, M> &b) 
{
	matrix <T, 1, M> *res(new matrix <T, 1, M>(a));
	for (size_t i(0); i < M; ++i)
		(*res)[i] += b[i];
	return *res;
}