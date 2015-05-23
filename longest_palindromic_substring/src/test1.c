/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/05/2015 08:36:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int longest_substr(char *str)
{
	int str_len = strlen(str);
	int max_len = 0;
	int i, j;

	/* 子串长度是奇数，[i - j], [i + j] */
	for(i = 0; i < str_len; i++)
	{
		for(j = 0; i - j >= 0 && i + j < str_len; j++)
		{
			if(str[i - j] == str[i + j])
			{
				if(max_len < 2 * j + 1)
				{
					max_len = 2 * j + 1;
				}
			}
			else
			{
				break;
			}
		}
	}

	/* 子串长度是偶数，[i - j], [i + j] */
	for(i = 0; i < str_len; i++)
	{
		for(j = 0; i - j >= 0 && i + j + 1 < str_len; j++)
		{
			if(str[i - j] == str[i + j + 1])
			{
				if(max_len < 2 * j + 2)
				{
					max_len = 2 * j + 2;
				}
			}
			else
			{
				break;
			}
		}
	}


	return max_len;
}

int main(void)
{
	char str[100];
	int len;

	while(1)
	{
		scanf("%s", str);
		len = longest_substr(str);
		printf("maxlen = %d\n", len);
	}

}
