#include <stdio.h>
#include <malloc.h>

int prt(int len, int* food_times, int emt_cnt)
{
	int i;
	printf("-------------------------\n");
	printf("empty = [%d]\n", emt_cnt);
	for (i = 0; i < len; i++)
	{
		printf("[%d] ", food_times[i]);
	}
	printf("\n-------------------------\n");
	return 0;
}

int solution(int len, int* food_times, int k)
{
	int answer = 0;
	int offset = 0;
	int i = 0;
	int* emt_flg = NULL;
	int emt_cnt = 0;

	emt_flg = (int*)calloc(len, sizeof(int));

	for (i = 0; i < len; i++)
	{
		if (food_times[i] == 0)
		{
			emt_flg[i] = 1;
			emt_cnt++;
		}
	}

	for (i = 0; i < k;)
	{
		if (emt_cnt == len)
		{
			free(emt_flg);
			return -1;
		}

		if (offset == len) offset = 0;

		if (food_times[offset] > 0)
		{
			if (food_times[offset] == 1)
			{
				emt_flg[offset] = 1;
				emt_cnt++;
			}

			food_times[offset] -= 1;

			i++;
			prt(len, food_times, emt_cnt);
			system("PAUSE");
		}

		offset++;
	}

	if (emt_cnt == len)
	{
		free(emt_flg);
		return -1;
	}

	for (i = 0; i < len; i++)
	{
		if (offset == len) offset = 0;

		if (emt_flg[offset] == 0)
		{
			answer = offset + 1;
			break;
		}
	}

	free(emt_flg);

	return answer;
}

int main()
{
	int len = 3;
	int food_times[3] = { 3, 1, 2 };
	int k = 5;

	printf("%d\n", solution(len, food_times, k));
	return 0;
}
