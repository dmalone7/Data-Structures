#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "tree23.h"

//FILE *debug;
int initial;

double distance(int x1, int x2, int y1, int y2, int z1, int z2)
{
	double dis;

	dis = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));

	return dis;
}

void indent23(int n)
{
	int i;

	for (i=0; i<n; i++)
	{
		fprintf(stdout, "%s", "  ");
	}
}

void print_tree23(struct node23 *node, int ht)
{
	if (node == NULL)
	{
		fprintf(stderr, "tree: NULL\n");
		return;
	}
	if (node->son1 == NULL)
	{
		fprintf(stdout, "(%d,%d,%d)\t%.1f\n", node->x, node->y, node->z, node->y1);
		return;
	}

	ht++;
	print_tree23(node->son1, ht);
	print_tree23(node->son2, ht);
	if (node->son3 != NULL)
		print_tree23(node->son3, ht);
}

int height23(struct node23 *node)
{
	int ht;

	if (node == NULL)
		return -1;

	ht = 0;
	while (node->son1 != NULL)
	{
		ht++;
		node = node->son1;
	}
	return(ht);
}

double min23(struct node23 *node)
{
	while (node->son1 != NULL)
	{
		node = node->son1;
	}
	return(node->y1);
}

struct node23 *locate_min23(struct node23 *node)
{
	if (node == NULL)
		return NULL;
	while (node->son1 != NULL)
	{
		node = node->son1;
	}
	return node;
}

double max23(struct node23 *node)
{
	while (node->son1 != NULL)
	{
		if (node->son3 != NULL)
			node = node->son3;
		else
			node = node->son2;
	}
	return node->y1;
}

struct node23 *locate_max23(struct node23 *node)
{
	if (node == NULL)
		return NULL;
	while (node->son1 != NULL)
	{
		if (node->son3 != NULL)
			node = node->son3;
		else
			node = node->son2;
	}
	return node;
}

struct node23 *avail23(void)
{
	struct node23 *node;

	node = (struct node23 *)malloc((size_t)sizeof(struct node23));
	if (node == NULL)
	{
		perror("avail23");
		return NULL;
	}

	node->son1 = NULL;
	node->son2 = NULL;
	node->son3 = NULL;

	return node;
}

void free23(struct node23 *p)
{
	if (p == NULL)
		return;
	free23(p->son1);
	free23(p->son2);
	free23(p->son3);
	free(p);
}

int valid23(struct node23 *node)
{
	if (node == NULL)
		return true;

	if (ckdepth23(node, height23(node)) == -1)
	{
		fprintf(stderr, "ERROR: Tree failed depth test\n");
		return false;
	}

	if (ckndx23(node) == -1)
	{
		fprintf(stderr, "ERROR: Tree failed index test\n");
		return false;
	}

	initial = true;
	if (ckorder23(node) == -1)
	{
		fprintf(stderr, "ERROR: Tree failed order test\n");
		return false;
	}

	return true;
}

int ckorder23(struct node23 *node)
{
	int last = 0;

	if (node->son1 == NULL)
	{
		if (initial)
		{
			initial = 0;
			last = node->y1;
			return 0;
		}
		else
		{
			if (last < node->y1)
			{
				last = node->y1;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}

	if (ckorder23(node->son1))
		return -1;
	if (ckorder23(node->son2))
		return -1;
	if (node->son3 != NULL)
		if (ckorder23(node->son3))
			return -1;
	return 0;
}

int ckdepth23(struct node23 *node, int ht)
{
	if (node->son1 == NULL)
	{
		if (ht == 0)
			return 0;
		else
			return -1;
	}
	if (ckdepth23(node->son1, ht-1))
		return -1;
	if (ckdepth23(node->son2, ht-1))
		return -1;
	if (node->son3 != NULL)
		if (ckdepth23(node->son3, ht-1))
			return -1;
	return 0;
}

int ckndx23(struct node23 *node)
{
	if (node->son1 == NULL)
		return 0;
	if (max23(node->son1) >= node->y1)
		return -1;
	if (node->y1 > min23(node->son2))
		return -1;
	if (node->son3 != NULL)
	{
		if (max23(node->son2) >= node->y2)
			return -1;
		if (node->y2 > min23(node->son3))
			return -1;
	}
	if (ckndx23(node->son1))
		return -1;
	if (ckndx23(node->son2))
		return -1;
	if (node->son3 != NULL)
		if (ckndx23(node->son3))
			return -1;
	return 0;
}

struct node23 *search23(int x, struct node23 *node)
{
	if (node == NULL)
		return NULL;

	if (node->son1 == NULL)
		return NULL;

	while (node->son1->son1 != NULL)
	{
		if (x < node->y1)
			 node = node->son1;
		else
			if (node->son3 == NULL || x < node->y2)
				node = node->son2;
			else
				node = node->son3;
	}
	return node;
}

void coor23(struct node23 *root, int newX, int newY, int newZ)
{
	root->x = newX;
	root->y = newY;
	root->z = newZ;
}

struct node23 *insert23(double dis, int a, int b, int c, struct node23 **root)
{
	struct node23 *newroot;
	struct node23 *oldroot;
	struct node23 *leaf;
	struct node23 *split;
	double minback;

	// NULL tree
	if (*root == NULL)
	{
		*root = avail23();
		(*root)->y1 = dis;
		// coordinates
		coor23((*root), a, b, c);
		return *root;
	}
	if ((*root)->son1 == NULL)
	{
		if ((*root)->y1 == dis)
			return NULL;
		newroot = avail23();
		leaf = avail23();
		leaf->y1 = dis;
		//coordinates
		coor23(leaf, a, b, c);

		if (dis > (*root)->y1)
		{
			newroot->son1 = *root;
			newroot->y1 = dis;
			newroot->son2 = leaf;
		}
		else
		{
			newroot->son1 = leaf;
			newroot->y1 = (*root)->y1;
			newroot->son2 = *root;
		}
		*root = newroot;
		return leaf;
	}

	// General Case

	leaf = addson(dis, a, b, c, *root, &split, &minback);
	if (leaf == NULL)
		return NULL;

	if (split != NULL)
	{
		oldroot = *root;
		*root = avail23();
		(*root)->son1 = oldroot;
		(*root)->son2 = split;
		(*root)->son3 = NULL;
		(*root)->y1 = minback;
	}
	return leaf;
}

struct node23 *addson(double x, int a, int b, int c, struct node23 *node, struct node23 **split, double *low)
{
	struct node23 *leaf;
	struct node23 *nodeback;
	struct node23 *w;
	double lowback;
	int child;

	*split = NULL;

	if (node->son1 == NULL)
	{
		if (node->y1 == x)
			return NULL;
		*split = avail23();
		if (node->y1 <= x)
		{
			(*split)->y1 = x;
			*low = x;
			return *split;
		}
		else
		{
			(*split)->y1 = node->y1;
			(*split)->y2 = node->y2;
			node->y1 = x;
			*low = (*split)->y1;
			// coordinates
			coor23((*split), node->x, node->y, node->z);
			return node;
		}
	}

	if (x < node->y1)
	{
		child = 1;
		w = node->son1;
	}
	else
	{
		if (node->son3 == NULL || x < node->y2)
		{
			child = 2;
			w = node->son2;
		}
		else
		{
			child = 3;
			w = node->son3;
		}
	}

	leaf = addson(x, a, b, c, w, &nodeback, &lowback);
	if (leaf == NULL)
		return NULL;
	
	coor23(leaf, a, b, c);
	
	if (nodeback != NULL)
	{
		if (node->son3 == NULL)
		{
			if (child == 2)
			{
				node->son3 = nodeback;
				node->y2 = lowback;
			}
			else
			{
				node->son3 = node->son2;
				node->y2 = node->y1;
				node->son2 = nodeback;
				node->y1 = lowback;
			}
		}	
		else
		{
			(*split) = avail23();
			if (child == 3)
			{
				(*split)->son1 = node->son3;
				(*split)->son2 = nodeback;
				(*split)->son3 = NULL;
				(*split)->y1 = lowback;
				*low = node->y2;
				node->son3 = NULL;
			}
			else
			{
				(*split)->son2 = node->son3;
				(*split)->y1 = node->y2;
				(*split)->son3 = NULL;
				node->son3 = NULL;
			}
			if (child == 2)
			{
				(*split)->son1 = nodeback;
				*low = lowback;
			}
			if (child == 1)
			{
				(*split)->son1 = node->son2;
				*low = node->y1;
				node->son2 = nodeback;
				node->y1 = lowback;
			}
		}
	}

	return leaf;
}

