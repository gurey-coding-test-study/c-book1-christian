#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct space
{
	int close_flag;

	int type;
	int r;
	int c;
} SPACE;

int get_distance(SPACE house, int chk_cnt, SPACE* chicken)
{
	int distance = 0, distance_temp = 0;
	int i = 0;
	int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

	for (i = 0; i < chk_cnt; i++)
	{
		if (chicken[i].close_flag == 1) continue;

		if (house.r > chicken[i].r)
		{
			r1 = house.r;
			r2 = chicken[i].r;
		}
		else
		{
			r1 = chicken[i].r;
			r2 = house.r;
		}

		if (house.c > chicken[i].c)
		{
			c1 = house.c;
			c2 = chicken[i].c;
		}
		else
		{
			c1 = chicken[i].c;
			c2 = house.c;
		}

		distance_temp = (r1 - r2) + (c1 - c2);

		if (distance == 0 || distance > distance_temp) distance = distance_temp;
	}

	return distance;
}

int get_distance_sum(int n, SPACE** vil, int chk_cnt, SPACE* chicken)
{
	int distance_sum = 0;
	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (vil[i][j].type == 1)
			{
				distance_sum += get_distance(vil[i][j], chk_cnt, chicken);
			}
		}
	}
	return distance_sum;
}

void combination(int n, int m, SPACE** vil, int chk_cnt, SPACE* chicken, int dep, int cur_cnt, int* distance)
{
	int distance_temp = 0;

	if (dep == chk_cnt)
	{
		if (cur_cnt == m)
		{
			distance_temp = get_distance_sum(n, vil, chk_cnt, chicken);
			if (*distance == 0 || *distance > distance_temp) *distance = distance_temp;
		}

		return;
	}

	chicken[dep].close_flag = 0;
	combination(n, m, vil, chk_cnt, chicken, dep + 1, cur_cnt + 1, distance);

	chicken[dep].close_flag = 1;
	combination(n, m, vil, chk_cnt, chicken, dep + 1, cur_cnt, distance);
}

int main()
{
	int n = 0, m = 0;
	int i = 0, j = 0;

	SPACE** vil = NULL;
	SPACE* vil_temp = NULL;
	SPACE** dis = NULL;
	SPACE* dis_temp = NULL;
	SPACE* chicken = NULL;
	int chk_cnt = 0;
	int distance = 0;
	
	scanf("%d%d", &n, &m);

	vil = (SPACE**)calloc(n, sizeof(SPACE*));
	vil_temp = (SPACE*)calloc(n * n, sizeof(SPACE));
	dis = (SPACE**)calloc(n, sizeof(SPACE*));
	dis_temp = (SPACE*)calloc(n * n, sizeof(SPACE));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &vil_temp[i * n + j].type);
			if (vil_temp[i * n + j].type == 2) chk_cnt++;
			vil_temp[i * n + j].r = i;
			vil_temp[i * n + j].c = j;
		}

		vil[i] = &vil_temp[i * n];
		dis[i] = &dis_temp[i * n];
	}

	chicken = (SPACE*)calloc(chk_cnt, sizeof(SPACE));

	for (i = 0, j = 0; i < n * n; i++)
	{
		if (vil_temp[i].type == 2)
		{
			memcpy(&chicken[j], &vil_temp[i], sizeof(SPACE));
			j++;

			if (j == chk_cnt) break;
		}
	}


	combination(n, m, vil, chk_cnt, chicken, 0, 0, &distance);

	free(chicken);
	free(vil_temp);
	free(vil);
	free(dis_temp);
	free(dis);

	printf("result = %d\n", distance);

	return 0;
}
