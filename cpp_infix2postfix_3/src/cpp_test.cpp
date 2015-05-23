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

/*
 * 中缀表达式转后缀表达式
 * */
int infix2postfix(char *infix, char *postfix)
{
	stack<char> s;//定义一个栈
	map<int,int> mp;

	int str_pos = 0;

	int i = 0;
	int len = 0;

	//定义运算符优先级
	mp[')'] = -1;
	mp['+'] = 0;
	mp['-'] = 0;
	mp['*'] = 1;
	mp['/'] = 1;
	mp['('] = 2;

	len = strlen(infix);

	for(i = 0; i < len; i++)
	{
		if(infix[i] < '0' || infix[i] > '9')		//遇到运算符
		{
//			postfix[str_pos++] = ' ';

			//栈弹出处理
			while(s.size() != 0 && mp[s.top()] >= mp[infix[i]])
			{
				if(s.top() == '(' && infix[i] == ')')
				{
					s.pop();
					break;
				}
				else
				{
					if(s.top() != '(')
					{
						postfix[str_pos++] = s.top();
						s.pop();
					}
					else
					{
						break;
					}
				}
			}

			//右括号不入栈
			if(infix[i] != ')')
			{
				s.push(infix[i]);
			}
		}
		else									//遇到数字
		{
			postfix[str_pos++] = infix[i];
		}
	}

	//弹出栈中所有运算符
	while(s.size() != 0)
	{
		postfix[str_pos++] = s.top();
		s.pop();
	}

	return 0;
}

char Infix[1200] = {0};
char Postfix[1200] = {0};

int main(void)
{
	scanf("%s", Infix);

	infix2postfix(Infix, Postfix);

	printf("%s\n", Postfix);

	return 0;
}

