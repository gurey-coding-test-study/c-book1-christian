#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[100];
	int score;
} STUDENT;

int compare(const void* a, const void* b)
{
	int num1 = ((STUDENT*)a)->score;
	int num2 = ((STUDENT*)b)->score;

	if (num1 < num2) return -1;

	if (num1 > num2) return 1;

	return 0;
}

int main()
{
	STUDENT* std = NULL;
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	std = (STUDENT*)calloc(n, sizeof(STUDENT));

	for (i = 0; i < n; i++)
	{
		scanf("%s%d", std[i].name, &std[i].score);
	}

	qsort(std, n, sizeof(STUDENT), compare);

	for (i = 0; i < n; i++)
	{
		printf("%s ", std[i].name);
	}

	printf("\n");
	
	free(std);

	return 0;
}
