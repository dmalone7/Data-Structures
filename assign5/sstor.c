#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sstor.h"

struct sstor *init_sstor(int num) {
    struct sstor *p;

    p = malloc(SSTORSZ(num));
    if (p==NULL) {
	return(NULL);
    }
    p->sz = 0;
    p->maxsz = num;
    return(p);
}

int ins_sstor(char *data, struct sstor **p) {
    struct sstor *q;
    int index = (*p)->sz;
    
    //requires +1 for \0
    int len = strlen(data) + 1;

    if ((*p)->sz + len >= (*p)->maxsz) {
	q = realloc(*p, SSTORSZ((*p)->maxsz + len  + INCRSZ));
	if (q == NULL) {
	    return(-1);
        }
	q->maxsz += len + INCRSZ;
	*p = q;
    }
    strcpy(&((*p)->item[(*p)->sz]), data);

    (*p)->sz += len;
    return(index);
}
