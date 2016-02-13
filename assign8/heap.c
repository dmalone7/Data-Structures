#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "heap.h"

void print_heap(struct heap *dlist, int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		fprintf(stderr, "\t%d\t%d\n", i, dlist->item[i]);
	}
}

void build_heap(struct heap *dlist, int n)
{
	int r;
	
	for (r = n/2-1; r >= 0; r--)
	{
		siftdown(dlist, r, n);
	}
}

void siftdown(struct heap *dlist, int r, int n)
{
	int val, left, right;
	
	left = LEFT(r, n);
	right = RIGHT(r, n);
	while ((left != -1 && dlist->item[r] > dlist->item[left]) || (right != -1 && dlist->item[r] > dlist->item[right]))
	{
		val = dlist->item[r];
		if (right == -1 || dlist->item[left] <= dlist->item[right])
		{
			dlist->item[r] = dlist->item[left];
			dlist->item[left] = val;
			r = left;
		}
		else
		{
			dlist->item[r] = dlist->item[right];
			dlist->item[right] = val;
			r = right;
		}
		left = LEFT(r, n);
		right = RIGHT(r, n);
	}
}

void siftup(struct heap *dlist, int r, int n)
{
	int p, val;
	
	p = PARENT(r, n);
	while (p != -1 && dlist->item[p] > dlist->item[r])
	{
		val = dlist->item[p];
		dlist->item[p] = dlist->item[r];
		dlist->item[r] = val;
		r = p;
		p = PARENT(r, n);
	}
}

void insert_heap(struct heap **dlist, int data)
{
    ins_dlist(data, dlist);
    siftup((*dlist),(*dlist)->sz-1, (*dlist)->sz);
}

int valid_heap(struct heap *dlist, int n)
{
	int r, left, right;
	
	for (r = 0; r <= n/2-1; r++)
	{
		left = LEFT(r, n);
		right = RIGHT(r, n);
		if (left != -1 && dlist->item[r] < dlist->item[left])
			return 0;
		if (right != -1 && dlist->item[r] < dlist->item[right])
			return 0;
	}
	return 1;
}
/*
int rmmin_heap(struct heap *dlist)
{
    int min;
    min = dlist->item[0];
        
	dlist->item[0] = dlist->item[dlist->sz-1];
    dlist->sz--;
    dlist->item[dlist->sz] = min;

    //printf("(%d,%d)\n" ,dlist->data[0],min);
    siftdown(dlist, 0, dlist->sz);

    return(min);
}
*/
int rmmin_heap(struct heap *dlist, int *n)
{
	int min;
	
	dlist->sz--;
	min = dlist->item[0];
	dlist->item[0] = dlist->item[dlist->sz];
	dlist->item[dlist->sz] = min;
	//printf("(%d,%d)\n", dlist->item[0], min);
	siftdown(dlist, 0, dlist->sz);
	return min;
}

struct heap *init_dlist(int num)
{
	struct heap *p;
	
	p = malloc(DLISTSZ(num));
	if (p == NULL)
		return NULL;
	p->sz = 0;
	p->maxsz = num;
	return p;
}

void prt_dlist(struct heap *p)
{
	int i;
	
	for (i = 0; i < p->sz; i++)
	{
		printf("%d\n", p->item[i]);
	}
}

int ins_dlist(int data, struct heap **p)
{
	struct heap *q;
	
	if ((*p)->sz == (*p)->maxsz)
	{
		q = realloc(*p, DLISTSZ((*p)->maxsz + INCRHSZ));
		if (q == NULL)
			return -1;
		q->maxsz += INCRHSZ;
		*p = q;
	}
	
	(*p)->item[(*p)->sz++] = data;
	return 0;
}
