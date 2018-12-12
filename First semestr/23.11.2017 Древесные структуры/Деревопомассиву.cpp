// Деревопомассиву.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
using namespace std;

const int N(100);

struct node;
typedef node* pnode;

struct node
{
	int key;
	pnode left, right;
	node() {}
	node(int _key)
	{
		key=_key, left=NULL, right=NULL;
	}
	~node()
	{
		if (left)
			delete left;
		if (right)
			delete right;
	}
	pnode find(int k)
	{
		pnode t(this);
		while (t)
			if (t->key == k)
				return t;
			else
				t = t->key > k ? t->left : t->right;
		return NULL;
	}
};

pnode make(int l, int r, int a[]) 
{
	if (l > r)
		return NULL;
	pnode t=new node(a[(l + r) >> 1]);
	t->left = make(l, ((l + r) >> 1) - 1, a), t->right = make(((l + r) >> 1) + 1, r, a);
	return t;
}

int main()
{
	int n, a[N];
	scanf("%d", &n);
	for (int i(0); i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	pnode root(make(0, n - 1, a));
	return 0;
}