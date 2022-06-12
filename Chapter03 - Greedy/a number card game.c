#include <stdio.h>

int main()
{
	int n = 0, m = 0;
	int input_card = 0;
	int output_card = 0;
	int min = 0;
	int i = 0;

	scanf("%d%d", &n, &m);

	for (i = 0; i < n * m; i++)
	{
		scanf("%d", &input_card);

		if (i % m == 0)
		{
			min = input_card;
		}
		else
		{
			if (min > input_card) min = input_card;
		}

		if (i % m == m - 1)
		{
			if (output_card < min) output_card = min;
		}
	}

	printf("%d\n", output_card);

	return 0;
}