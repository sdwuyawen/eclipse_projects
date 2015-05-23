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

	for(i = 0; i < len;)
	{
		if(infix[i] < '0' || infix[i] > '9')		//遇到运算符
		{
//			postfix[str_pos++] = ' ';

			//栈弹出处理，弹出栈中优先级大于等于当前运算符的运算符
			//若栈顶是(，只有遇到)时，才会弹出
			while(s.size() != 0 && mp[s.top()] >= mp[infix[i]])
			{
				/*
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
				}*/
				if(s.top() == '(')
				{
					if(infix[i] == ')')
					{
						s.pop();
					}
					break;
				}
				else
				{
					postfix[str_pos++] = s.top();
					s.pop();
				}
			}

			//右括号不入栈
			if(infix[i] != ')')
			{
				s.push(infix[i]);
			}

			i++;
		}
		else									//遇到数字
		{
			while(infix[i] >= '0' && infix[i] <= '9')
			{
				postfix[str_pos++] = infix[i++];
			}
			postfix[str_pos++] = ' ';			//不同数字间用' '间隔
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
	char c;
	int i = 0;

	while(scanf("%c", &c))
	{
		if(c == '\n')
		{
			break;
		}
		else if(c != ' ')
		{
			Infix[i++] = c;
		}
	}
//	scanf("%s", Infix);

	infix2postfix(Infix, Postfix);

	printf("%s\n", Postfix);

	return 0;
}

