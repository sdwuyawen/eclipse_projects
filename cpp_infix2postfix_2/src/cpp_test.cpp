//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

using namespace std;

//#include <iostream>
#include <stack>
#include <map>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	stack<char> s;//定义一个栈
	map<int,int> mp;

	char str[1200] = {0};
	char str_postfix[1200] = {0};
	int str_pos = 0;
	char num_str[10] = {0};
	int num_value;

	int i = 0;
	int len = 0;

	int start = 0;
	int end = 0;

	//定义运算符优先级
	mp['+'] = 0;
	mp['-'] = 0;
	mp['*'] = 1;
	mp['/'] = 1;

	scanf("%s", str);
	len = strlen(str);

	for(i = 0; i < len; i++)
	{
		if(str[i] < '0' || str[i] > '9')		//遇到运算符
		{
			str_postfix[str_pos++] = ' ';
			//开始用栈处理
			while(s.size() != 0 && mp[s.top()] >= mp[str[i]])
			{
				str_postfix[str_pos++] = s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else									//遇到数字
		{
			str_postfix[str_pos++] = str[i];
		}
	}

	while(s.size() != 0)
	{
		str_postfix[str_pos++] = s.top();
		s.pop();
	}

	printf("%s\n", str_postfix);

	return 0;
}

