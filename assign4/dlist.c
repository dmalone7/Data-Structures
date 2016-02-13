#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

struct dlist *initDlist(int num)
{
    struct dlist *p;

    p = malloc( DLISTSIZE(num) );

    if(p == NULL)
        return(NULL);

    p->size = 0;
    p->maxSize = num;
    return(p);
}

int insDlist(char data[], struct dlist **p)
{
    struct dlist *q;

    if ((*p)->size == (*p)->maxSize)
    {
        q = malloc(DLISTSIZE((*p)->maxSize + INCRSIZE));
        if(q == NULL)
            return(-1);
	q = *p;
        q->maxSize += INCRSIZE;
        *p = q;
    }

    int i;

    //adding data to the list
    for(i = 0; i < 1024; i++)
        (*p)->item[(*p)->size][i] = data[i];

    (*p)->size++;

    return(0);
}

int delDlist(struct dlist *p, int num)
{
    if (p->size < num) {
	fprintf(stderr, "Dynamic List size:\t%d\nCannot remove string number: \t%d\n", p->size, num);
	return(0);
    }

    int i = num-1;

    while (i < p->size) {
	int j = 0;
	
	while (j<1024) {
	    p->item[i][j] = p->item[i+1][j];
	    j++;
	}
	i++;
    }

    p->size--;

    return(0);    
}

void printDlist(struct dlist *p)
{
    int i;
    for(i = 0; i <= p->size-1; i++)
        printf("%s", p->item[i]);
}

int stringCmp(const void* a, const void* b)
{
    const char *ia = (const char *)a;
    const char *ib = (const char *)b;
    return strncmp(ia, ib, 1023);
}
