//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
//#include <stack>
//#include <map>

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

using namespace std;


int main(void)
{
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

	return 0;
}

