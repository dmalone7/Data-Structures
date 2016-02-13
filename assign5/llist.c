#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sstor.h"
#include "llist.h"

struct llist *init_llist(void) {
    struct llist *l;

    l = malloc(sizeof(struct llist));
    if (l == NULL)
	return(NULL);
    
    l->strings = init_sstor(INITSZ);

    l->head = malloc(sizeof(struct lnode));
    if (l->head == NULL) {
	free(l);
	return(NULL);
    }
    l->tail = malloc(sizeof(struct lnode));
    if (l->tail == NULL) {
	free(l->head);
	free(l);
	return(NULL);
    }

    l->head->prev = NULL;
    l->tail->next = NULL;
    l->head->next = l->tail;
    l->tail->prev = l->head;
    return(l);
}

struct lnode *ins_llist(char *data, struct llist *ll) {
    struct lnode *p, *q;

    q = malloc(sizeof(struct lnode));
    if (q == NULL)
	return(NULL);


    p = ll->head->next;

    int index = ins_sstor(data, &(ll->strings));

    while (p->next != NULL && strcmp(data, &(ll->strings->item[p->item])) > 0)
	p = p->next;
    q->item = index;
    q->next = p;
    q->prev = p->prev;
    p->prev = q;
    q->prev->next = q;

    return(q);
}

void free_llist(struct llist *ll) {
    struct lnode *p;

    p = ll->head->next;
    while (p->next != NULL) {
	free(p->prev);
	p = p->next;
    }
    free(p->prev);
    free(p);
    free(ll->strings);
    free(ll);
}

void prt_llist(struct llist *ll) {
    struct lnode *p;

    p = ll->head->next;
    while (p->next != NULL) {
	printf("%s\n", &(ll->strings->item[p->item]));
	p = p->next;
    }
}

int valid_llist(struct llist *ll) {
    struct lnode *p;

    if (ll == NULL || ll->head == NULL || ll->tail == NULL || ll->head->next == NULL || ll->tail->prev == NULL || ll->head->prev != NULL || ll->tail->next != NULL) {
	return(0);
    }

    p = ll->head->next;
    while (p->next != NULL) {
	if (p->prev == NULL || p->prev->next != p || p->next->prev != p)
	    return(0);
	p = p->next;
    }
    if (p != ll->tail)
	return(0);
    return(1);
}

int del_llist(struct llist *ll, int num)
{
    int count = 0;
    struct lnode *p;

    p = ll->head;

    while (count < num)
    {
        if (p->next == NULL)
	    return -1;

	p = p->next;
	count++;
    }
    if (p->next == NULL)
	return -1;
    p->next->prev = p->prev;
    p->prev->next = p->next;

    free(p);

    return 0;
}
