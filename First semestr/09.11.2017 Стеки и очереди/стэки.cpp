// стэкиочередь.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

struct stack {
	node* head = NULL;


	void push(int new_data) {
		node* temp = new node;
		temp->data = new_data;
		temp->next = head;
		head = temp;
	}

	int front()	{
		if(head==NULL){
			cout << "Stack is empty"<<endl;
			return 0;
		}
		return head->data;
	}

	int _pop() {
		if (head == NULL) {
			cout << "Stack is empty" << endl;
			return 0;
		}
		node* temp = head;
		head = head->next;
		int temp_data = temp->data;		
		delete temp;
		return temp_data;
	}
		

	~stack()
	{
		while (head != NULL) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main()
{
	stack *s = new stack;
	int c, x;
	cout << "Press -1 to exit \n Press 1 to add elem \n Press 2 to pop elem \n Press 3 to front elem \n";
	for (;;) {
		cin >> c;
		if (c < 0){
			return 0;
		}
		switch (c) {
		case 1:
			cin >> x;
			s->push(x);
			break;
		case 2:
			s->_pop();
			break;
		case 3:
			printf("%d\n", s->front());
			break;
		}
	}
    return 0;
}

