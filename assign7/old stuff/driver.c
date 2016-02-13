#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "tree23.h"

int main(int argc, char *argv[])
{
	struct node23 *tree;
	int num = 0;

	if (argc != 5)
	{
		perror(argv[1]);
		return -1;
	}

	FILE *fp;
	fp = fopen(argv[4], "r");

	int baseX = atoi(argv[1]);
	int baseY = atoi(argv[2]);
	int baseZ = atoi(argv[3]);

	double dis;
 	int x, y, z;

	tree = NULL;
	
	while (fscanf(fp, "(%d, %d, %d)\n", &x, &y, &z) == 3)
	{
		num++;
		dis = distance(baseX, x, baseY, y, baseZ, z);

		if (insert23(dis, x, y, z, &tree) == NULL)
		{
			fprintf(stderr, "Item %d is alread in the tree\n", x);
			num--;
		}
		print_tree23(tree, 0);

		fprintf(stderr, "Checking Tree - tree index = %d value = %.1f\n", num, dis);

		if (!valid23(tree))
		{
			print_tree23(tree, 0);
			return -1;
		}
	}
	
	//print_tree23(tree, 0);
	fprintf(stderr, "All trees correct\n");

	free(tree);

	fclose(fp);

	return 0;
}
