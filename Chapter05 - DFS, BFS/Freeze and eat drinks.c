#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int type;	// 0 = open , 1 = close
	int h;		// 0 ~
	int w;		// 0~
	int visit;

	struct node *right;
	struct node *down;
	struct node *left;
	struct node *up;
} NODE;

void link_node(NODE *node_p, int h, int w)
{
	int i = 0, j = 0;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (j < w - 1) node_p[i * w + j].right = &node_p[i * w + j + 1];
			if (i < h - 1) node_p[i * w + j].down = &node_p[(i + 1) * w + j];
			if (j > 0) node_p[i * w + j].left = &node_p[i * w + j - 1];
			if (i > 0) node_p[i * w + j].up = &node_p[(i - 1) * w + j];
		}
	}
}

void visit(NODE *node)
{
	node->visit = 1;

	if (node->right != NULL && node->right->type == 0 && node->right->visit == 0)
	{
		visit(node->right);
	}

	if (node->down != NULL && node->down->type == 0 && node->down->visit == 0)
	{
		visit(node->down);
	}

	if (node->left != NULL && node->left->type == 0 && node->left->visit == 0)
	{
		visit(node->left);
	}

	if (node->up != NULL && node->up->type == 0 && node->up->visit == 0)
	{
		visit(node->up);
	}
}

void print_visit(NODE *node_p, int h, int w, int cnt)
{
	int i = 0, j = 0;
	printf("----------------------------------------------------\n");
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%d", node_p[i * w + j].visit);
		}
		printf("\n");
	}
	printf("cnt = %d\n", cnt);
	getchar();
}

int main()
{
	NODE *node_p = NULL;
	int h = 0, w = 0;
	char *input = NULL;
	int i = 0, j = 0;
	int cnt = 0;

	scanf("%d%d", &h, &w);

	input = (char *) calloc(w + 1, sizeof(char));
	node_p = (NODE *) calloc(h * w, sizeof(NODE));

	for (i = 0; i < h; i++)
	{
		scanf("%s", input);

		for (j = 0; j < w; j++)
		{
			node_p[i * w + j].type = input[j] - '0';
			node_p[i * w + j].h = i;
			node_p[i * w + j].w = j;
		}
	}

	free(input);

	link_node(node_p, h, w);

	for (i = 0; i < h * w; i++)
	{
		if (node_p[i].type == 0 && node_p[i].visit == 0)
		{
			visit(&node_p[i]);
			cnt++;
			// print_visit(node_p, h, w, cnt);
		}
	}

	free(node_p);

	printf("result = [%d]\n", cnt);

	return 0;
}
