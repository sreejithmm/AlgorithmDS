#include <stdio.h>
#include "graph.h"

int main()
{
    /* test */
	int i,j,k,l,m,n;
	graph* gr=NULL;
	while(1)
	{
		printf("\nTEST MENU\n");
		printf("*********\n");
		printf("1.Create and print a graph\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
				printf("Enter no of nodes\n");
				scanf("%d",&k);
				gr=(graph*)createGraph(k);
				addVertices(gr,0,1);
				addVertices(gr,0,4);
				addVertices(gr,1,2);
				addVertices(gr,1,3);
				addVertices(gr,1,4);
				addVertices(gr,2,3);
				addVertices(gr,3,4);

				printGraph(gr);
				printf("\nBFS\n");
				graph_doBFS(gr,0);
				printf("\nDFS\n");
				graph_doDFS(gr,0);

				graph_IsBipartite(gr,0);

				break;
		}

	}


    return 0;
}
