/*
 * next_prime.c
 *
 *  Created on: May 8, 2015
 *      Author: wu
 */

#include <stdio.h>
#include <stdlib.h>
int next_prime(int val)
{
	int i;
	int not_prime = 0;

	if(val % 2 == 0)
	{
		val++;
	}

	for(; ; val += 2)
	{
		not_prime = 0;
		for(i = 3; i < val; i++)
		{
			if(val % i == 0)
			{
				not_prime = 1;
				break;
			}
		}
		if(not_prime == 0)
		{
			return val;
		}
	}
}


int main(void)
{
	int value;

	while(1)
	{
		scanf("%d", &value);
		printf("%d\n", next_prime(value));
	}

}

