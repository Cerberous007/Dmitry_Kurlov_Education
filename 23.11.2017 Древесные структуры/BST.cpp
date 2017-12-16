// BTS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


struct node;
typedef node* pnode;

struct node 
{
	int key, sum;
	pnode left, right;
	node() {}
	node(int _key)
	{
		key=_key, sum=_key, left=NULL, right=NULL;
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
	void split(pnode &l, pnode &r, int k) 
	{
		if (k < key) 
		{
			if (left)
				left->split(l, left, k);
			else
				l = NULL;
			r = this;
		}
		else 
		{
			if (right)
				right->split(right, r, k);
			else
				r = NULL;
			l = this;
		}
	}
	pnode insert(pnode nw)
	{
		split(nw->left, nw->right, nw->key);
		nw->sum += (nw->left ? nw->left->sum : 0) + (nw->right ? nw->right->sum : 0);
		return nw;
	}
};

int main() 
{
	int n;
	scanf("%d", &n);
	int a;
	pnode root=NULL;
	scanf_s("%d", &a);
	root = new node(a);
	for (int i=1; i < n; ++i) 
	{
		scanf_s("%d", &a);
		root = root->insert=new node(a);
	}
	printf("sum: %d", root->sum);
	return 0;
}