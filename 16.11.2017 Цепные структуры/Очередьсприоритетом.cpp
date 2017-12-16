// Очередьсприоритетом.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <cstdio>

struct node 
{
	int data;
	node *next;
	node()
	{
		next=NULL;
	}
	node(int x, node *n)
	{
		data=x, next=n;
	}
};

struct Queue 
{
	node *tail;
	Queue()
	{
		tail=NULL;
	}
	~Queue() 
	{
		node *temp;
		while (tail != NULL) 
		{
			temp = tail;
			tail = tail->next;
			delete temp;
		}
	}
	void insert(int x)
	{
		if(tail == NULL)		
				tail = new node(x, NULL);		
		else
		{
			if (tail->data > x)
			{
				tail = new node(x, tail);
			}
			else
			{
				node *temp(tail);
				while (temp->next != NULL && temp->next->data <= x)
					temp = temp->next;
				if (temp->next == NULL)
					temp->next = new node(x, NULL);
				else
					temp->next = new node(x, temp->next);
			}
		}
	}
};

int main() {
	int n, x;
	scanf_s("%d", &n);
	Queue *q = new Queue();
	for (int i(0); i < n; ++i) {
		scanf_s("%d", &x);
		q->insert(x);
	}
	for (node *i(q->tail); i != NULL; i = i->next)
		printf("%d ", i->data);
	return 0;
}

