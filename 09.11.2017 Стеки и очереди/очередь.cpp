// очередь.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

struct node {
	int data;
	node* next;
};

struct queue {
	node* tail = NULL;

	~queue() {
		while (tail != NULL) {
			node* temp = tail;
			tail = tail->next;
			delete temp;
		}
	}

	void push(int new_data){
		node* temp = new node;
		temp->data = new_data;
		temp->next = tail;
		tail = temp;
	}

	int front() {
		if (tail == NULL) {
			printf("Queue is empty");
			return 0;
		}
		node *temp=tail;
		while (temp->next != NULL)
			temp = temp->next;
		return temp->data;
	}

	int _pop() {
		if (tail == NULL) {
			printf("Queue is empty\n");
			return 0;
		}
		if (tail->next == NULL) {
			int temp_data=tail->data;
			delete tail;
			tail = NULL;
			return temp_data;
		}
		node *temp = tail;
		while (temp->next->next != NULL)
			temp = temp->next;
		int temp_data=temp->next->data;
		delete temp->next;
		temp->next = NULL;
		return temp_data;
	}
};

int main()
{
	queue *q = new queue;
	int c, x;
	printf("Press -1 to exit \n Press 1 to add elem \n Press 2 to pop elem \n Press 3 to front elem \n");
	for (;;) {
		scanf_s("%d", &c);
		if (c < 0) {
			return 0;
		}
		switch (c) {
		case 1:
			scanf_s("%d", & x);
			q->push(x);
			break;
		case 2:
			printf("%d\n", q->_pop());
			break;
		case 3:
			printf("%d\n", q->front());
			break;
		}
	}
	return 0;
}
