#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int cur_x = 1, cur_y = 1;
	int n = 0;
	int ch = 0;

	scanf("%d", &n);

	while (1)
	{
		ch = getchar();
		if (ch == EOF)
		{
			break;
		}

		switch (ch)
		{
			case 'L':
				if (cur_y != 1) cur_y--;
				break;
			case 'R':
				if (cur_y != n) cur_y++;
				break;
			case 'U':
				if (cur_x != 1) cur_x--;
				break;
			case 'D':
				if (cur_x != n) cur_x++;
				break;
		}

	}

	printf("%d %d\n", cur_x, cur_y);

	return 0;
}
