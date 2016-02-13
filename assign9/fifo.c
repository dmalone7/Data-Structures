#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fifo.h"

void print_fifo(struct fifo *f)
{
	int i;

	if (f->sz == 0)
	{
		fprintf(stdout, "Empty Fifo\n");
		return;
	}

	fprintf(stdout, "--Fifo--\n");
	if (f->tail >= f->head)
	{
		for (i = f->head; i < f->maxsz; i++)
		{
			fprintf(stdout, "   %d\n", f->data[i]);
		}
		
	}
	else
	{
		for (i = 0; i <= f->tail; i++)
		{
			fprintf(stdout, "   %d\n", f->data[i]);
		}
		for (i = 0; i <= f->tail; i++)
		{
			fprintf(stdout, "   %d\n", f->data[i]);
		}
	}
}

struct fifo *init_fifo(int num)
{
	struct fifo *f;

	f = malloc((size_t)FIFOSZ(num));
	if (f == NULL)
	{
		perror("Malloc error");
		return(NULL);
	}

	f->sz = 0;
	f->maxsz = num;
	f->head = 0;
	f->tail = -1;
	return(f);
}

int insert_fifo(int x, struct fifo **f)
{
	struct fifo *tf;
	int oldmaxsz, size;

	if ((*f)->sz == (*f)->maxsz)
	{
		size = FIFOSZ((*f)->maxsz+INCRFIFOSZ);
		tf = realloc(*f, (size_t)size);
		if (tf == NULL)
		{
			perror("Realloc error");
			return(-1);
		}
		*f = tf;
		oldmaxsz = (*f)->maxsz;
		(*f)->maxsz += INCRFIFOSZ;

		if ((*f)->head)
		{
			size = (oldmaxsz - (*f)->head)*sizeof(int);
			memmove((*f)->data+(*f)->head+INCRFIFOSZ, (*f)->data+(*f)->head, size);
			(*f)->head += INCRFIFOSZ;
		}
	}

	if ((*f)->tail == (*f)->maxsz-1)
	{
		(*f)->tail = 0;
	}
	else
	{
		(*f)->tail++;
	}
	(*f)->data[(*f)->tail] = x;
	(*f)->sz++;
	return(0);
}

int extract_fifo(int *x, struct fifo *f)
{
	if (f->sz == 0)
	{
		return(-1);
	}
	f->sz--;
	*x = f->data[f->head];
	if (f->head == f->maxsz-1)
	{
		f->head = 0;
	}
	else
	{
		f->head++;
	}
	return(0);
}
