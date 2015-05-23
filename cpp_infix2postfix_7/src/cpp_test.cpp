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
			while(s.size() != 0 && mp[infix[i]] <= mp[s.top()])
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

	postfix[str_pos] = 0x00;

	return 0;
}

/*
 * 计算后缀表达式的值*/
int calcu_postfix(char *postfix)
{
	stack<int> s_num;

	int i = 0;
	int len = strlen(postfix);

	char str_num[10] = {0};
	int num_pos = 0;

	int a;
	int b;
	int c;

	int ret;

	/*
	 * 遇到数字则压栈
	 * 遇到运算符则取出栈中两个元素，按照运算符运算后，把结果压栈
	 * */
	for(i = 0; i < len; )
	{
		if(postfix[i] >= '0' && postfix[i] <= '9')
		{
			num_pos = 0;
			while(postfix[i] >= '0' && postfix[i] <= '9')
			{
				str_num[num_pos++] = postfix[i++];
			}
			str_num[num_pos] = 0x00;
			i ++;				//scape the space after a num

			s_num.push(atoi(str_num));
		}
		else				//是运算符
		{
			if(s_num.size() > 0)
			{
				b = s_num.top();
				s_num.pop();
			}
			else
			{
				printf("error 1");
				return 0;
			}

			if(s_num.size() > 0)
			{
				a = s_num.top();
				s_num.pop();
			}
			else
			{
				printf("error 2");
				return 0;
			}

			switch(postfix[i])
			{
				case '+':
						c = a + b;
						break;
				case '-':
						c = a - b;
						break;
				case '*':
						c = a * b;
						break;
				case '/':
						c = a / b;
						break;
				default:
						break;
			}

			s_num.push(c);

			i++;
		}
	}

	if(s_num.size() > 0)
	{
		ret = s_num.top();
	}
	else
	{
		printf("error 3");
		return 0;
	}

	return ret;
}

char Infix[1200] = {0};
char Postfix[1200] = {0};

int main(void)
{
	char c;
	int i = 0;
	int result = 0;

	while(1)
	{
		i = 0;
		while(scanf("%c", &c))
		{
			if(c == '\n')
			{
				break;
			}
			else if(c != ' ')		//去掉输入中的空格
			{
				Infix[i++] = c;
			}
		}
		Infix[i] = 0x00;

	//	scanf("%s", Infix);

		infix2postfix(Infix, Postfix);
		result = calcu_postfix(Postfix);

		printf("%s \n= %d\n", Postfix, result);
	}

	return 0;
}

