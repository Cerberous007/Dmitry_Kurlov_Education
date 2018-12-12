// Задачасрюкзаком.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>

using namespace std;

bool lss(pair <int, int> &a, pair <int, int> &b);

int main() {
	int n, w;
	pair <int, int> ; //weight, cost
	scanf_s("%d", &n);
	pair<int, int>*a = new pair<int, int>[n];
	scanf_s("%d", &w);
	for (int i=0; i < n; ++i)
		scanf_s("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n, &lss);
	double ans=0;
	for (int i=0; w && i < n; ++i)
		if (w >= a[i].first)
			w -= a[i].first, ans += a[i].second;
		else {
			ans += (double)w / a[i].first * a[i].second;
			break;
		}
		printf("%.2lf", ans);
		return 0;
}

bool lss(pair <int, int> &a, pair <int, int> &b) {
	return (double)a.second / a.first > (double)b.second / b.first;
}
