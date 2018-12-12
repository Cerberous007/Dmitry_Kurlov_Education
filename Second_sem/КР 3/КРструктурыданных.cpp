// КРструктурыданных.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h" 
#include "string.h"
#include <iostream>
using namespace std;



struct node {
	int time;
	char name[20];
	node* next = NULL;
};

struct list 
{
	node* head = NULL;

	~list() 
	{
		while (head != NULL) 
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void add_elem(int new_data, char* name) 
	{
		node* new_temp = new node;
		node* temp = head;
		node* prev = NULL;		
		if (head == NULL)
		{
			head = new_temp;
			head->time = new_data;
			strcpy_s(head->name, name);
			return;
		}
		while (temp!=NULL&&temp->time<new_data) 
		{
			prev = temp;
			temp = temp->next;
		}
		new_temp->time = new_data;	
		strcpy_s(new_temp->name, name);
		//scanf_s("%s", &new_temp->name);
		new_temp->next = temp;
		if (prev == NULL)
		{
			head = new_temp;
		}
		else
		{
			prev->next = new_temp;
		}
	}	

	bool del() 
	{
		node* temp = head;
		node* prev = NULL;
		while (temp!= NULL&&temp->time!=0) 
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp != NULL)
		{
			if (prev != NULL)
			{
				prev->next = temp->next;				
			}
			else
			{
				head = temp->next;
			}			
			cout << temp->name << " is completed\n";
			delete temp;
		}
		else return false;
		return true;				
	}

	bool del(int time)
	{
		node* temp = head;
		node* prev = NULL;
		while (temp != NULL&&temp->time != time)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp != NULL)
		{
			if (prev != NULL)
			{
				prev->next = temp->next;
			}
			else
			{
				head = temp->next;
			}
			cout << temp->name << " is deleted\n";
			delete temp;
		}
		else return false;
		return true;
	}

	void tick()
	{
		node* temp = head;		
		while (temp != NULL) 
		{
			temp->time--;
			temp = temp->next;
		}
		temp = head;		
		while(del());
	}

	void inprogress() 
	{
		node* temp = head;
		if (temp == NULL)
		{
			cout << "structure is empty\n";			
		}
		while (temp != NULL)
		{
			cout << temp->name <<" in progress\n"<< temp->time<< " time\n";
			temp = temp->next;
		}
	}

	bool search(int data)
	{
		node* temp = head;
		while (temp != NULL)
		{		
			if (data == temp->time)
			{
				return 1;
			}
			temp = temp->next;			
		}
		return 0;
	}
};

int main()
{
	list *l = new list;
	int xtime, c;
	char xname[20] = "";	
	printf("-1 - to exit\n 1 - add element\n 2 - one tick\n 3 - in progress\n 4 - delete elem (if elem available)\n 5 - search elem\n");
	for (;;)
	{		
		cout << "shoose operation\n";
		scanf_s("%d", &c);
		if (c < 0)
		{
			return 0;
		}
		switch (c)
		{
		case 1:
			cout << "Enter time (time>=1)\n";
			scanf_s("%d", &xtime);	
			if (xtime < 1)
			{
				cout << "Error\n";
				break;
			}
			cout << "Enter process`s name\n";
			cin >> xname ;					
			l->add_elem(xtime, xname);
			break;
		case 2:
			l->tick();
			break;
		case 3:
			l->inprogress();
			break;
		case 4:
			cout << "Enter time\n";
			cin >> xtime;
			l->del(xtime);
			break;
		case 5:
			cin >> xtime;
			if (l->search(xtime))
			{
				cout << "elem is available\n";
			}
			else
			{
				cout << "elem is unavailable\n";
			}
			break;
		}
	}
	return 0;
}

