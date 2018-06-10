#pragma once
const int MOD(25);

template <typename T, size_t M, size_t N>
class matrix 
{
private:
	T **data;
public:
	matrix() : data(new T*[M])
	{
		for (size_t i(0); i < M; ++i)
			data[i] = new T[N];
	}
	matrix(const T &value) : matrix()
	{
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] = value;
	}
	matrix(matrix &t) : matrix() 
	{
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] = t[i][j];
	}
	template <typename U>
	matrix(matrix <U, M, N> &t) : matrix()
	{
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] = t[i][j];
	}
	~matrix()
	{
		for (size_t i(0); i < M; ++i)
			delete[] data[i];
	}
	T*& operator[](const size_t i)
	{
		return data[i];
	}
	template <typename U>
	matrix <T, M, N> &operator=(matrix <U, M, N> &t)
	{
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] = t[i][j];
		return *this;
	}
	matrix <T, M, N> &operator*=(const T &x) 
	{
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] *= x;
		return *this;
	}
	void random() {
		for (size_t i(0); i < M; ++i)
			for (size_t j(0); j < N; ++j)
				data[i][j] = rand() % MOD;
	}
	void print(const char *message = "")
	{
		puts(message);
		for (size_t i(0); i < M; ++i) {
			for (size_t j(0); j < N; ++j)
				std::cout << data[i][j] << ' ';
			std::cout << '\n';
		}
	}
};

//Specialization for vector
template <typename T, size_t M>
class matrix <T, 1, M>
{
private:
	T *data;
public:
	matrix() : data(new T[M]) {}
	matrix(const T &value) : matrix()
	{
		for (size_t i(0); i < M; ++i)
			data[i] = value;
	}
	matrix(matrix &t) : matrix() 
	{
		for (size_t i(0); i < M; ++i)
			data[i] = t[i];
	}
	template <typename U>
	matrix(matrix <U, 1, M> &t) : matrix()
	{
		for (size_t i(0); i < M; ++i)
			data[i] = t[i];
	}
	~matrix() {
		delete[] data;
	}
	T& operator[](const size_t i) 
	{
		return data[i];
	}
	template <typename U>
	matrix <T, 1, M> &operator=(matrix <U, 1, M> &t)
	{
		for (size_t i(0); i < M; ++i)
			data[i] = t[i];
		return *this;
	}
	matrix <T, 1, M> &operator*=(const T &x)
	{
		for (size_t i(0); i < M; ++i)
			data[i] *= x;
		return *this;
	}
	void random()
	{
		for (size_t i(0); i < M; ++i)
			data[i] = rand() % MOD;
	}
	void print(const char *message = "")
	{
		puts(message);
		for (size_t i(0); i < M; ++i)
			std::cout << data[i] << ' ';
		putchar('\n');
	}
};

//matrix * matrix
template <typename T, size_t M, size_t N, size_t S>
matrix <T, M, S> &operator*(matrix <T, M, N> &a, matrix<T, N, S> &b) {
	matrix <T, M, S> *res(new matrix <T, M, S>(0));
	for (size_t i(0); i < M; ++i)
		for (size_t j(0); j < S; ++j)
			for (size_t k(0); k < N; ++k)
				(*res)[i][j] += a[i][k] * b[k][j];
	return *res;
}

//vector * matrix
template <typename T, size_t M, size_t N>
matrix <T, 1, N> &operator*(matrix <T, 1, M> &a, matrix<T, M, N> &b) {
	matrix <T, 1, N> *res(new matrix <T, 1, N>(0));
	for (size_t i(0); i < N; ++i)
		for (size_t j(0); j < M; ++j)
			(*res)[i] += a[i] * b[j][i];
	return *res;
}

//vector * vector
template <typename T, size_t M>
T operator*(matrix <T, 1, M> &a, matrix<T, 1, M> &b) {
	T res(0);
	for (size_t i(0); i < M; ++i)
		(*res)[i] += a[i] * b[i];
	return res;
}