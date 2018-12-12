// deque.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


struct node {
	int data;
	node* next;
	node* prev;
};

struct dequeue {
	node* tail = NULL;
	node* head = NULL;
	

	~dequeue() {
		while (tail != NULL) {
			node* temp = tail;
			tail = tail->next;
			delete temp;
		}
	}

	void push_back(int new_data) {
		node* temp = new node;
		temp->data = new_data;
		temp->next = tail;
		temp->prev = NULL;
		tail = temp;
		if (head == NULL) {
			head = tail;
		}
		if (tail->next != NULL) {
			tail->next->prev = tail;
		}
	}

	void push_front(int new_data) {
		node* temp = new node;
		temp->data = new_data;
		temp->next = NULL;
		temp->prev = head;
		head = temp;
		if (tail == NULL) {
			tail = head;
		}
		if (head->prev != NULL) {
			head->prev->next = head;
		}
	}

	int back() {
		if (tail == NULL) {
			printf("DeQueue is empty");
			return 0;
		}
		return tail->data;
	}
	
	int front() {
		if (head == NULL) {
			printf("DeQueue is empty");
			return 0;
		}
		return head->data;	
	}

	int _pop_back() {
		if (tail == NULL) {
			printf("DeQueue is empty\n");
			return 0;
		}
		int temp_data = tail->data;
		if (tail->next != NULL) {
			tail = tail->next;
			delete tail->prev;
			tail->prev = NULL;
		}
		else {
			delete tail;
			tail = head = NULL;
		}
		return temp_data;
	}

	int _pop_front() {
		if (head == NULL) {
			printf("DeQueue is empty\n");
			return 0;
		}
		int temp_data = head->data;
		if (head->prev != NULL) {
			head = head->prev;
			delete head->next;
			head->next = NULL;
		}
		else {
			delete head;
			head = tail = NULL;
		}
		return temp_data;
	}
};

int main()
{
	dequeue *d = new dequeue();
	int c, x;
	printf("Press -1 to exit \n Press 1 to push_back \n Press 2 to push_front \n Press 3 to back elem \n Press 4 to front elem\n Press 5 to pop_back\n Press 6 to pop_front\n");
	for (;;) {
		scanf_s("%d", &c);
		if (c < 0) {
			return 0;
		}
		switch (c) {
		case 1:
			scanf_s("%d", &x);
			d->push_back(x);
			break;
		case 2:
			scanf_s("%d", &x);
			d->push_front(x);	
			break;
		case 3:
			printf("%d\n", d->back());
			break;
		case 4:
			printf("%d\n", d->front());
			break;
		case 5:
			printf("%d\n", d->_pop_back());
			break;
		case 6:
			printf("%d\n", d->_pop_front());
			break;
		}
	}
	return 0;
}

