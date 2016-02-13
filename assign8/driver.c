#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "heap.h"

int main (int argc, char *arv[]) 
{
	struct heap *hp;
	int input;
	char strInput[1024];
	char str[1024];

	hp = init_dlist(INITHSZ);
	if (hp == NULL )
	{
		printf("Error");
		return (-1);
	}

	while(scanf("%d\n", &input))
		insert_heap(&hp, input);
	 
	int num = hp->sz;

	while (fgets(strInput, 1024, stdin))
	{
	int read = sscanf(strInput, "%s %d", &str, &input);
    
		if (read == 2)
		{
			insert_heap(&hp, input);
		}
		else if (read == 1 && str[0] == 'b')
		{
			build_heap(hp, num);
		}
		else
		{
			int min = rmmin_heap(hp, &num);
			printf("%d\n", min);
		}
	}
    
	print_heap(hp, num);
	free(hp);
	return (0);
}

/*
int main(void)
{
	struct heap *h;
	h = init_dlist(INITHSZ);
	
	if (h == NULL)
	{
	        perror("Unable to malloc heap");
		return -1;
	}
		
	int input;
	while (scanf("%d\n", &input) == 1)
	{
		ins_dlist(input, &h);
		prt_dlist(h);
		printf("\n");
	}
	
	int num = h->sz;
	build_heap(h, num);
	if (valid_heap(h, num))
		printf("Valid heap\n");
	else
		printf("Invalid heap\n");
	
	char *str = NULL;
	char strin[1024];
	while (fgets(str, 1024, stdin))
	{
		sscanf(str, "%s %d", &strin, &input);
		
		if (strin[0] == 'i')
		{
			insert_heap(&h, input);
		}
		if (strin[0] == 'e')
		{
			int min = rmmin_heap(h, &num);
			//printf("%d\n", min);
		}
	}
	print_heap(h, num);
	
	return 0;	
}
*/
