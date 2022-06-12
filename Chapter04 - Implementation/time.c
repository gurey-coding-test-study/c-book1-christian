#include <stdio.h>
#include <string.h>

int main()
{
	int n = 0;
	int cnt = 0;
	int cnt_60s = 0, cnt_60m = 0;
	int i = 0;
	char tmp[2 + 1] = { 0, };
	char* ptr = NULL;

	for (i = 0; i < 60; i++)
	{
		sprintf(tmp, "%-02d", i);

		if ((ptr = strchr(tmp, '3')) != NULL)
		{
			cnt_60s++;
		}
	}

	cnt_60m = cnt_60s * 60 + (60 - cnt_60s) * cnt_60s;

	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		if (i == 3)
		{
			cnt += 60 * 60;
		}
		else
		{
			cnt += cnt_60m;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
