// Задачасотрезками.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int n, k=0;
	printf("Enter number of segments\n");
	scanf_s("%d", &n);		
	pair<int, int>*arr = new pair<int, int>[n+1];
	printf("Enter coordinates\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);	
	stack<pair<int,int>>s;
	pair<int, int>now;
	for (; k < n; k++)
	{		
		if (s.empty())
		{
			s.push(arr[k]);
		}
		else
		{
			now = s.top();
			if (now.first <= arr[k].first&&arr[k].second <= now.second)
			{
				s.pop();
				s.push(arr[k]);
			}
			if (now.second < arr[k].first)
			{
				s.push(arr[k]);
			}
		}
	}
	printf("--------------\n");
	printf("%d\n", s.size());
	while (!s.empty())
	{
		printf("[%d, %d]", s.top().first, s.top().second);
		s.pop();
	}
    return 0;
}

