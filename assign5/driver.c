#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "llist.h"

int sreplace(char newc, char oldc, char *s);

int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[1024];
    struct llist *ll;

    if (argc != 2) 
    {
	fprintf(stderr, "Incorrect number of arguments\n");
	return -1;
    }

    fp = fopen(argv[1], "r");

    if ((int)fp == NULL)
    {
	fprintf(stderr, "Unable to open file\n");
	return -1;
    }

    ll = init_llist();

    if (ll == NULL)
    {
	fprintf(stderr, "Unable to Initialize llist\n");
	return -1;
    }

    while (fgets(buf, 1023, fp) != NULL)
    {
	if(sreplace('\0', '\n', buf) != 0)
	{
	    perror("Unable to replace newline character");
	    exit(-1);
	}

	if (ins_llist(buf, ll) == NULL)
	{
	    perror("Unable to Instrt into llist");
	    exit(-1);
	}
    }

    if (del_llist(ll, 5) == -1)
	perror("Unable to delete 5th item in llist");

    prt_llist(ll);
    free_llist(ll);

    fclose(fp);

    return(0);
} 

int sreplace(char newc, char oldc, char *s)
{
    int count = 0;

    if (s == NULL)
	return -1;

    while (*s != '\0')
    {
	if (*s == oldc)
	{
	    *s = newc;
	    count++;
	}
	s++;
    }

    return(0);
}
