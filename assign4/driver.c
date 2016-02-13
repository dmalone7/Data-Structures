#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dlist.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    char text[1024];

    //check the command line
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return(-1);
    }

    //open file given on command line
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror(argv[1]);
        return(-1);
    }

    //initialize the dynamic list
    struct dlist *p;

    p = initDlist(INITSIZE);

    if(p == NULL)
    {
        perror("Unable to malloc dlist");
        return(-1);
    }

    //read each line then store it in the dynamic list
    while(fgets(text, 1024, fp) != NULL)
    {
        if( insDlist(text,&p) == -1)
        {
            perror("Unable to realloc dlist");
            return(-1);
        }

        //printf("DEBUG: Data inserted successfully.\n\n");
    }

    qsort(&(p->item), p->size, sizeof(p->item), stringCmp);

    // Deletes the 5th line in the dynamic list
    delDlist(p, 5);
    printDlist(p);

    return(0);
}
