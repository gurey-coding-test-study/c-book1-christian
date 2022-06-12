#include <stdio.h>
#include <string.h>

int main()
{
	char l[2 + 1] = { 0, };
	int x = 0, y = 0;
	int cnt = 0;

	scanf("%s", l);

	x = l[0] - 'a' + 1;
	y = l[1] - '0';

	if (x > 2)
	{
		if (y != 1) cnt++;
		if (y != 8) cnt++;
	}
	if (x < 7)
	{
		if (y != 1) cnt++;
		if (y != 8) cnt++;
	}
	if (y > 2)
	{
		if (x != 1) cnt++;
		if (x != 8) cnt++;
	}
	if (y < 7)
	{
		if (x != 1) cnt++;
		if (x != 8) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
