#include <stdio.h>

int main()
{
	int n = 0, m = 0, k = 0;
	int num = 0;
	int i = 0, j = 0;
	int max = 0, premax = 0;
	int sum = 0;

	scanf("%d%d%d", &n, &m, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);

		if (num > max)
		{
			premax = max;
			max = num;
		}
		else if (num == max)
		{
			premax = max;
		}
	}

	for (i = 0; i < m; i++, j++)
	{
		if (j == k)
		{
			j = 0;
			sum += premax;
		}
		else
		{
			sum += max;
		}
	}

	printf("%d\n", sum);

	return 0;
}
