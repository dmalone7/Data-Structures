#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graph.h"

int main(int argc, char *argv[])
{
	struct graph *g;
	int u, v;

	g = init_graph(INITGRSZ);
	if (g == NULL)
	{
		fprintf(stderr, "Error: unable to malloc graph\n");
		return(-1);
	}

	scanf("Nodes: %d Edges: %d\n", &u, &v);

	int i;
	for (i = 0; i < u; i++)
	{
		if (insert_vertex(i, &g) < 0)
		{
			fprintf(stderr, "Error: Unable to insert vertex %d\n", i);
			return(-1);
		}
	}

	while (scanf("%d %d\n", &u, &v) == 2)
	{
		if (insert_edge(u, v, g) < 0)
		{
			fprintf(stderr, "Error: Unable to insert edge %d %d\n", u, v);
			return(-1);
		}
	}

	printf("Printing graph\n");
	print_graph(g);

	printf("Printing Depth First Traversal\n");
	dftraversal(g);

	printf("Printing Breadth First Traversal\n");
	bftraversal(g);

	printf("Freeing graph\n");
	free_graph(g);
	printf("Graph freed\n");

	return(0);
}
