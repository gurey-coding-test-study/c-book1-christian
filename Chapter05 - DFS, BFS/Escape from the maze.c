#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int type;
	int move_cnt;

	struct node* right;
	struct node* down;
	struct node* left;
	struct node* up;
} NODE;

void link_node(NODE* node_p, int h, int w)
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

void move(NODE* node, int cur_cnt)
{
	if (node->right != NULL && node->right->type == 1 && (node->right->move_cnt == 0 || node->right->move_cnt > cur_cnt + 1))
	{
		node->right->move_cnt = cur_cnt + 1;
		move(node->right, cur_cnt + 1);
	}

	if (node->down != NULL && node->down->type == 1 && (node->down->move_cnt == 0 || node->down->move_cnt > cur_cnt + 1))
	{
		node->down->move_cnt = cur_cnt + 1;
		move(node->down, cur_cnt + 1);
	}

	if (node->left != NULL && node->left->type == 1 && (node->left->move_cnt == 0 || node->left->move_cnt > cur_cnt + 1))
	{
		node->left->move_cnt = cur_cnt + 1;
		move(node->left, cur_cnt + 1);
	}

	if (node->up != NULL && node->up->type == 1 && (node->up->move_cnt == 0 || node->up->move_cnt > cur_cnt + 1))
	{
		node->up->move_cnt = cur_cnt + 1;
		move(node->up, cur_cnt + 1);
	}
}

void print_move(NODE* node_p, int h, int w)
{
	int i = 0, j = 0;

	printf("--------------------------------------------------\n");
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%3d", node_p[i * w + j].move_cnt);
		}
		printf("\n");
	}
}


int main()
{
	NODE* node_p = NULL;
	int h = 0, w = 0;
	char* input = NULL;
	int i = 0, j = 0;

	scanf("%d%d", &h, &w);

	input = (char*)calloc(w + 1, sizeof(char));
	node_p = (NODE*)calloc(h * w, sizeof(NODE));

	for (i = 0; i < h; i++)
	{
		scanf("%s", input);

		for (j = 0; j < w; j++)
		{
			node_p[i * w + j].type = input[j] - '0';
		}
	}

	free(input);

	link_node(node_p, h, w);

	node_p[0].move_cnt = 1;

	move(&node_p[0], 1);

	print_move(node_p, h, w);

	printf("result = [%d]\n", node_p[h * w - 1].move_cnt);

	return 0;
}
