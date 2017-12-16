// ФункцияАккермана.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int akke(int n, int m);

int main()
{
	unsigned long int a, b, c;
	cin >> a;
	cin >> b;
	c = akke(a, b);
	cout << c<<"\n";
    return 0;
}

int akke(int m, int n)
{	
	if (m > 0 && n > 0)
		return akke(m - 1, akke(m, n - 1));
	else if (m > 0 && n == 0)
		return akke(m - 1, 1);	
	else if (m == 0)
		return n + 1;
}


