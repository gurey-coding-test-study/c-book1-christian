#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	int i = 0, j = 0;
	int input = 0;
	int* min_temp = NULL;
	int* arr = NULL;
	int* sort = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));
	sort = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		min_temp = NULL;

		for (j = 0; j < n; j++)
		{
			if (arr[j] > 0)
			{
				if (min_temp == NULL) min_temp = &arr[j];
				else if (*min_temp > arr[j])
				{
					min_temp = &arr[j];
				}
			}
		}

		sort[i] = *min_temp;
		*min_temp = 0;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", sort[i]);
	}
	printf("\n");

	free(sort);
	free(arr);

	return 0;
}
