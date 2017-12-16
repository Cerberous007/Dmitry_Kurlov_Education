// string.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>

struct String
{
	char *data;
	int len;	
	String(char *s)
	{ 
		data =new char[strlen(s) + 1];
		len=strlen(s);
		memcpy(data, s, len + 1);
	}
	~String() {
		delete[] data;
	}
	String(String &s)
	{
		data = new char[s.len + 1];
		len=s.len;
		memcpy(data, s.data, len + 1);
	}
	void print() 
	{
		printf("%s\n", data);
	}
	int getlen()
	{
		return len;
	}
	String operator=(String &s)
	{
		delete[] data;
		data = new char[s.len + 1], len = s.len;
		memcpy(data, s.data, len + 1);
		return *this;
	}	
};

int main() {
	String s="my";
	String d = "favouriteproga!";
	printf("Len(s) = %d, s = ", s.getlen());
	s.print();
	printf("Len(d) = %d, d = ", d.getlen());
	d.print();	
	printf("d = ");
	d.print();	
	return 0;
}

