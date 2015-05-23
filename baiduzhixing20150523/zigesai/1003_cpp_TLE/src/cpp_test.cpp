/*
 * =====================================================================================
 *
 *       Filename:  011.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/14/2015 08:55:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
//#include <vector>
//#include <stack>
#include <map>
//#include <string>
#include <sstream>				//stringstream类型的头文件

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>



int main(void)
{
	int T;
	int N,M;

	int i;
	int j;
	int k;
	int cases = 0;

	int pos;
	int pos_new;

	unsigned char a, b, c, d;
	unsigned char A, B, C, D;

	string num[4];

	string str_ips[1000];
	string str_masks[50];
	string str_nets[1000];
	stringstream sstream;

	map<string, int> word_count;

	string s;
	string ss;

	int diff_count = 0;


	cin >> T;

	while(T--)
	{
		cin >> N >> M;

		for(i = 0; i < N; i++)
		{
			cin >> str_ips[i];
		}

		for(i = 0; i < M; i++)
		{
			cin >> str_masks[i];
		}

		cout << "Case #" << ++cases << endl;

		for(j = 0; j < M; j++)
		{
			s = str_masks[j];

			pos = 0;
			pos_new = 0;
			i = 0;
			while((pos_new = s.find(".", pos)) != s.npos)
			{
				num[i++] = s.substr(pos, pos_new - pos);
				pos = ++pos_new;
			}
			num[i] = s.substr(pos, s.length() - pos);

			A = atoi(num[0].c_str());
			B = atoi(num[1].c_str());
			C = atoi(num[2].c_str());
			D = atoi(num[3].c_str());

//			cout << A << " " << B << " " << C << " " << D << " " << endl;


			diff_count = 0;

			word_count.erase(word_count.begin(),word_count.end());
			for(i = 0; i < N; i++)
			{
				s = str_ips[i];

				pos = 0;
				pos_new = 0;
				k = 0;
				while((pos_new = s.find(".", pos)) != s.npos)
				{
					num[k++] = s.substr(pos, pos_new - pos);
					pos = ++pos_new;
				}
				num[k] = s.substr(pos, s.length() - pos);

				a = atoi(num[0].c_str());
				b = atoi(num[1].c_str());
				c = atoi(num[2].c_str());
				d = atoi(num[3].c_str());

	//			printf("a = %d,b = %d, c = %d, d = %d\n", a, b, c, d);

	//			cout << a << " " << b << " " << c << " " << d << " " << endl;

				s = "";
				sstream.str("");
				sstream.clear();
				sstream << (a & A);
				sstream >> ss;
				s += ss;
				s += ".";

				sstream.str("");
				sstream.clear();
				sstream << (b & B);
				sstream >> ss;
				s += ss;
				s += ".";

				sstream.str("");
				sstream.clear();
				sstream << (c & C);
				sstream >> ss;
				s += ss;
				s += ".";

				sstream.str("");
				sstream.clear();
				sstream << (d & D);
				sstream >> ss;
				s += ss;

	//			cout << s << endl;
	//			进行映射

				pair<map<string,int>::iterator, bool> ret = word_count.insert(make_pair(s, 1));

				if(!ret.second)
				{
					++ret.first->second;
				}
				else
				{
					diff_count++;
				}
			}

			cout << diff_count << endl;
		}
	}





//	cout << N << " " << M;

	return 0;
}
