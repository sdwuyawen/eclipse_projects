#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(void)
{
	int T;
	int N;
	int M;
	int i;
	int j;
	int k;
	int m;
	int n;

	int str_ips[1000][4] = {{0}};
	int str_masks[50][4] = {{0}};

	int num_ip[4];
	int num_mask[4];

	unsigned int diff_nets[1000];
	unsigned int merge;
	unsigned int diff_num;

	unsigned int num;

	scanf("%d", &T);

	n = 0;
	for(m = 0; m < T; m++)
	{
		scanf("%d %d", &N, &M);

		for(i = 0; i < N; i++)
		{
			scanf("%d.%d.%d.%d", &str_ips[i][0], &str_ips[i][1], &str_ips[i][2], &str_ips[i][3]);
		}

		for(i = 0; i < M; i++)
		{
			scanf("%d.%d.%d.%d", &str_masks[i][0], &str_masks[i][1], &str_masks[i][2], &str_masks[i][3]);
		}

		printf("Case #%d:\n", ++n);
		//for every mask
		for(i = 0; i < M; i++)
		{
			memset(diff_nets, 0xFF, sizeof(diff_nets));
			diff_num = 0;

			//for every ip
			for(j = 0; j < N; j++)
			{
				merge = ((str_ips[j][0] & str_masks[i][0]) << 0)
							| ((str_ips[j][1] & str_masks[i][1]) << 8)
							| ((str_ips[j][2] & str_masks[i][2]) << 16)
							| ((str_ips[j][3] & str_masks[i][3]) << 24);

				for(k = 0; k < diff_num; k++)
				{
					if(merge == diff_nets[k])
					{
						break;
					}
				}

				//有相同的
				if(k < diff_num)
				{

				}
				else		//没有相同的
				{
					diff_nets[k] = merge;
					diff_num++;
				}
			}

			printf("%d\n", diff_num);
		}
	}


#if 0
	diff_count = 0;

	scanf("%d.%d.%d.%d", &num_ip[0], &num_ip[1], &num_ip[2], &num_ip[3]);
	scanf("%d.%d.%d.%d", &num_mask[0], &num_mask[1], &num_mask[2], &num_mask[3]);

//	printf("%d.%d.%d.%d\n", num_ip[0], num_ip[1], num_ip[2], num_ip[3]);
//	printf("%d.%d.%d.%d\n", num_mask[0], num_mask[1], num_mask[2], num_mask[3]);

	merge = ((num_ip[0] & num_mask[0]) << 0)
			| ((num_ip[1] & num_mask[1]) << 8)
			| ((num_ip[2] & num_mask[2]) << 16)
			| ((num_ip[3] & num_mask[3]) << 24);

//	printf("%d.%d.%d.%d\n", merge & 0xFF, (merge >> 8) & 0xFF, (merge >> 16) & 0xFF, (merge >> 24) & 0xFF);



//	scanf("%d %d", &N, &M);


	while(1)
	{

	}
#endif

	return 0;
}
