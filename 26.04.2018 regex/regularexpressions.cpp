// regularexpressions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<regex>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main()
{
	int c=0;

	regex rx("http:.*");

	string s;
	ifstream in1("input.txt");

	list<string> l;

	while (in1 >> s)
	{
		if (regex_match(s.begin(), s.end(), rx))
		{
			s.insert(4, "s");
		}
		l.push_front(s);
		c++;
	}
	in1.close();

	ofstream res("result.txt");
	for (int i = 0; i < c; i++)
	{
		res << l.front() << endl;
		l.pop_front();
	}
	return 0;
}

