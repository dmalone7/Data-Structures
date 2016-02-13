#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graph.h"

int main(int argc, char *argv[])
{
	struct graph *g;
	int u, v;
	FILE *fp;

	if (argc != 2)
	{
		perror(argv[1]);
		return(-1);
	}

	g = init_graph(INITGRSZ);

	if (g == NULL)
	{
		fprintf(stderr, "Error: unable to malloc graph\n");
		return(-1);
	}

	fp = fopen(argv[1], "r");
	fscanf(fp, "Nodes: %d Edges: %d\n", &u, &v);

	int i;
	for (i = 0; i < u; i++)
	{
		if (insert_vertex(i, &g))
		{
			fprintf(stderr, "Error: Unable to insert vertex %d\n", i);
			return(-1);
		}
	}

	while (fscanf(fp, "%d %d\n", &u, &v) == 2)
	{
		if (insert_edge(u, v, g) < 0)
		{
			fprintf(stderr, "Error: Unable to insert edge %d %d\n", u, v);
			return(-1);
		}
	}

	while(scanf("%d %d", &u, &v) == 2)
	{
		if(prtsrtpath(g, u, v))
		{
			fprintf(stderr, "Error: Unable to print shortest path %d %d\n", u, v);
			return(-1);
		}
	}

	free_graph(g);
	fclose(fp);

	return(0);
}
