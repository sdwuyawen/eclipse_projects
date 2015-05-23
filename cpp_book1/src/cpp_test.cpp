//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include "Sales_item.h"
//#include <stack>
//#include <map>

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

using namespace std;


int main(void)
{
	Sales_item book1, book2;

	cin >> book1 >> book2;

	cout << book1 + book2 << endl;

	/*
	cout << "Enter two numbers:" << endl;

	float val1 = 0;
	float val2 = 0;

	int value;
	int sum;

	cin >> val1 >> val2;

	cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << endl;

	sum = 0;
	while(cin >> value)
	{
		sum += value;
	}

	cout << sum << endl;
	*/

	return 0;
}

