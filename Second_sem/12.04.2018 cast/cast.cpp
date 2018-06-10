// выавам.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Point
{
public:
	int x;
	int y;
	int z;
	Point()
	{
		x = y = z = 0;
	}
	Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	void Print()
	{
		cout << "X:" << x << "\tY:" << y << "\tZ:" << z << endl;
	}
};

int main()
{
	int c;

	ofstream fout;
	ifstream fin;
	string path = "Points.txt";

	Point pnt(0, 0, 23);

	puts("1: write\n2: read");
	cin >> c;
	
	switch (c)
	{
	case 1:
		
		fout.open(path, ofstream::app);
		if (!fout.is_open())
		{
			cout << "Error" << endl;
		}
		else
		{
			cout << "File is open" << endl;
			fout.write(reinterpret_cast<char *>(&pnt), sizeof(Point));
		}
		fout.close();
	case 2:
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Error" << endl;
		}
		else
		{
			cout << "File is open"<<endl;
			Point point;
			while(fin.read(reinterpret_cast<char*>(&point), sizeof(Point)))
			{
				point.Print();
			}			
		}
		fin.close();
	}


    return 0;
}

