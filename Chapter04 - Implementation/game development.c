#include <stdio.h>
#include <malloc.h>

int print_cur(int x, int y, int d, int w, int h, int *map, int *exp)
{
	int i = 0;
	printf("---------------------------------------\n");
	printf("cur : [%d] [%d] [%d]\n", x, y, d);
	for (i = 0; i < w * h; i++)
	{
		printf("%d", exp[i]);
		if (i % w == w - 1) printf("\n");
		else printf(" ");
	}
	printf("---------------------------------------\n");

	return 0;
}

int backstep_check(int* x, int* y, int d, int w, int h, int* map, int* exp)
{
	if (*x > 0 && map[w * (*y) + (*x - 1)] == 0 && exp[w * (*y) + (*x - 1)] == 0)
	{
		printf("backstep_check - left move possible\n");
		return 0;
	}
	if (*y < h - 1 && map[w * (*y + 1) + *x] == 0 && exp[w * (*y + 1) + *x] == 0)
	{
		printf("backstep_check - down move possible\n");
		return 0;
	}
	if (*x < w - 1 && map[w * (*y) + (*x + 1)] == 0 && exp[w * (*y) + (*x + 1)] == 0)
	{
		printf("backstep_check - right move possible\n");
		return 0;
	}
	if (*y > 0 && map[w * (*y - 1) + *x] == 0 && exp[w * (*y - 1) + *x] == 0)
	{
		printf("backstep_check - up move possible\n");
		return 0;
	}

	if (d == 0 && *y < h - 1 && map[w * (*y + 1) + *x] == 0)
	{
		printf("backstep_check - backstep down\n");
		(*y)++;
		return 0;
	}
	if (d == 1 && *x > 0 && map[w * (*y) + (*x - 1)] == 0)
	{
		printf("backstep_check - backstep left\n");
		(*x)--;
		return 0;
	}
	if (d == 2 && *y > 0 && map[w * (*y - 1) + *x] == 0)
	{
		printf("backstep_check - backstep up\n");
		(*y)--;
		return 0;
	}
	if (d == 3 && *x < w - 1 && map[w * (*y) + (*x + 1)] == 0)
	{
		printf("backstep_check - backstep right\n");
		(*x)++;
		return 0;
	}

	return -1;
}

int turn_and_go(int* x, int* y, int* d, int w, int h, int* map, int* exp)
{
	(*d)--;
	if (*d == -1) *d = 3;

	if (*d == 0 && *y > 0 && map[w * (*y - 1) + *x] == 0 && exp[w * (*y - 1) + *x] == 0)
	{
		printf("turn_and_go - go up\n");
		(*y)--;
	}
	else if (*d == 1 && *x < w - 1 && map[w * (*y) + (*x + 1)] == 0 && exp[w * (*y) + (*x + 1)] == 0)
	{
		printf("turn_and_go - go right\n");
		(*x)++;
	}
	else if (*d == 2 && *y < h - 1 && map[w * (*y + 1) + *x] == 0 && exp[w * (*y + 1) + *x] == 0)
	{
		printf("turn_and_go - go down\n");
		(*y)++;
	}
	else if (*d == 3 && x > 0 && map[w * (*y) + (*x - 1)] == 0 && exp[w * (*y) + (*x - 1)] == 0)
	{
		printf("turn_and_go - go left\n");
		(*x)--;
	}

	exp[w * (*y) + *x] = 1;

	return 0;
}

int main()
{
	int w = 0, h = 0;
	int x = 0, y = 0, d = 0;
	int cnt = 0;
	int* map = NULL;
	int* exp = NULL;
	int i = 0;

	scanf("%d%d", &h, &w);
	scanf("%d%d%d", &y, &x, &d);

	map = (int*)calloc(w * h, sizeof(int));
	exp = (int*)calloc(w * h, sizeof(int));

	for (i = 0; i < w * h; i++)
	{
		scanf("%d", &map[i]);
	}

	exp[w * y + x] = 1;

	while (1)
	{
		print_cur(x, y, d, w, h, map, exp);
		//system("PAUSE"); printf("\n");
		if (backstep_check(&x, &y, d, w, h, map, exp) != 0) break;
		turn_and_go(&x, &y, &d, w, h, map, exp);
	}

	for (i = 0; i < w * h; i++)
	{
		if (exp[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
