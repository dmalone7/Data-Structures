#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "btree.h"

int main(void) {
    int x;
    struct node *n;

    n = NULL;

    while (scanf("%d", &x) == 1) {
	if (ins_tree(x, &n) == NULL) {
	    perror("Unable to Insert into llist");
	    exit(-1);
	}
    }
    prt_tree(n);
    printf("\n");

    int h = height(n);
    printf("height = %d\n\n", h);

    int w = width(n);
    printf("width = %d\n\n", w);

    if (reverse(n) != 0)
    {
	fprintf(stderr, "Could not reverse btree");
        
    }
    else
	prt_tree(n); 

    free_tree(n);
    exit(0);
}
