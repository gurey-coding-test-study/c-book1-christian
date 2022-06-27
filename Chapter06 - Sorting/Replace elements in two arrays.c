#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) return -1;

	if (num1 > num2) return 1;

	return 0;
}

int main()
{
	int* arr_a = NULL, * arr_b = NULL;
	int sum = 0;
	int min = 0, max = 0;
	int n = 0, k = 0;
	int i = 0;

	scanf("%d%d", &n, &k);

	arr_a = (int*)calloc(n, sizeof(int));
	arr_b = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr_a[i]);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr_b[i]);
	}

	for (i = 0; i < k; i++)
	{
		qsort(arr_a, n, sizeof(int), compare);
		qsort(arr_b, n, sizeof(int), compare);

		min = arr_a[0];
		max = arr_b[n - 1];

		if (min >= max) break;

		arr_a[0] = max;
		arr_b[n - 1] = min;
	}

	for (i = 0; i < n; i++)
	{
		sum += arr_a[i];
	}

	printf("%d\n", sum);

	free(arr_a);
	free(arr_b);

	return 0;
}
