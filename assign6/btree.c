#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "btree.h"

void prt_tree(struct node *tree) {

    if (tree==NULL) {
	printf("Null Tree\n");
	return;
    }

    p_tree(tree, 0);
}

void p_tree(struct node *t, int h) {
    int i;

    if (t==NULL)
	return;
    for (i = 0; i < h; i++) {
	printf("  ");
    }
    printf("node: %d\n", t->item);
    p_tree(t->left, h+1);
    p_tree(t->right, h+1);
}

struct node *ins_tree(int data, struct node **tree) {
    struct node **p, *q;

    p=tree;
    while (*p != NULL) {
	if ((*p)->item == data)
	    return(*p);
	if (data < (*p)->item)
	    p = &((*p)->left);
	else
	    p = &((*p)->right);
    }
    q = malloc(sizeof(struct node));
    if (q==NULL)
	return(NULL);
    *p = q;
    q->item = data;
    q->left = NULL;
    q->right = NULL;
    return(q);
}

void delete_tnode(struct node **p) {
    struct node *q, *t, **s;

    q = *p;
    if (q->left == NULL && q->right == NULL)
	*p = NULL;
    else if (q->left == NULL)
	*p = q->right;
    else if (q->right == NULL)
	*p = q->left;
    else {
	s = &(q->left);
	while ((*s)->right != NULL)
	    s = &((*s)->right);
	t = *s;
	*s = t->left;
	t->right = q->right;
	t->left = q->left;
	*p = t;
    }
    free(q);
}

int del_tree(int data, struct node **tree) {
    struct node **p;

    while (*p != NULL && (*p)->item != data) {
	if (data < (*p)->item)
	    p = &((*p)->left);
	else
	    p = &((*p)->right);
    }
    if (*p==NULL);
	return(-1);
    delete_tnode(p);
    return(0); 
}

void free_tree(struct node *tree) {
    if (tree==NULL)
	return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

void tprt(struct node *tree, char *order) {

    if (tree == NULL) {
	printf("Null Tree\n");
	return;
    }
    if (strcmp(order, "nlr") && strcmp(order, "lnr") && strcmp(order, "lrn")) {
	fprintf(stderr, "Unknown traversal order %s (not nlr or lnr or lrn)\n", order);
	fprintf(stderr, "  Defaulting to lnr\n");
	order = "lnr";
    }
    tp(tree, order, 0);
}

void tp(struct node *t, char *order, int h) {
    int i;

    if (t==NULL)
	return;
    for (i = 0; i < h; i++) {
	printf("  ");
    }
    if (order[0] == 'n')
	printf("%d\n", t->item);
    tp(t->left, order, h+1);
    if (order[1] == 'n')
	printf("%d\n", t->item);
    tp(t->right, order, h+1);
    if (order[2] == 'n')
	printf("%d\n", t->item);
}

int height(struct node *t)
{
    int lefth, righth;
    lefth = righth = 0;

    if (t == NULL)
	return -1;
    if (t->left == NULL && t->right == NULL)
	return 1;
    if (t->left != NULL)
	lefth = height(t->left);
    if (t->right != NULL)
	righth = height(t->right);

    if (lefth > righth)
	return lefth + 1;
    else
	return righth + 1;
}

int width(struct node *tree)
{
    if (tree == NULL)
	return 0;
    
    int* array = malloc(sizeof(int)*height(tree));
    int depth = 0;
    array[depth]++;
    
    wid_hlp(tree->left, depth+1, array);
    wid_hlp(tree->right, depth+1, array);
	
    int max = 0;
    int i;
    for(i = 0; i < height(tree); i++)
    {
	if(array[i] > max)
	    max = array[i];
    }
    free(array);
    
    return max;
}

void wid_hlp(struct node *t, int d, int* a)
{
    if (t == NULL)
	return;
    a[d]++;
    wid_hlp(t->left, d+1, a);
    wid_hlp(t->right, d+1, a);
}

/*
int width(struct node *t)
{
    if (t == NULL)
	return 0;

    
}
*/

int reverse(struct node *t)
{
    struct node *tmp;

    if (t == NULL)
	return -1;

    tmp = t->left;    
    t->left = t->right;
    t->right = tmp;

    reverse(t->left);
    reverse(t->right);

    return 0;
}
