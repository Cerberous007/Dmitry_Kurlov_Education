#include<algorithm>
#include<iostream>
#include<mutex>

using namespace std;

mutex M;
int n = 1000;

void quickSort(int *arr, int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	M.lock();
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	M.unlock();
	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}


int main() {
	srand(23917);
	int *a = new int[n];
	for (int i = 0; i<n; ++i)
	{
		a[i] = rand();
	}
	thread T1(&quickSort, 0, n);
	thread T2(&quickSort, 0, n);
	T1.join();
	T2.join();
	for (int i = 0; i<n; i++) {
		if (a[i]>a[i + 1])
			cout << "a[" << i << "] > a[" << i + 1 << "] !!! \n";
	}
}
