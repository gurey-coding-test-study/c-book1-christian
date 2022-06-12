#include <stdio.h>

int main()
{
	int n = 0, k = 0;
	int cnt = 0;

	scanf("%d%d", &n, &k);

	while (1)
	{
		cnt++;

		if (n % k == 0)
		{
			n /= k;
		}
		else
		{
			n--;
		}

		if (n == 1) break;
	}

	printf("%d\n", cnt);

	return 0;
}