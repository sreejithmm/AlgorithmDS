#include <stdio.h>
#include "graph.h"

int main()
{
    /* test */
	int i,j,k,l,m,n;
	float len;
	graph* gr=NULL;
	while(1)
	{
		printf("\nTEST MENU\n");
		printf("*********\n");
		printf("1.Create and print a graph\n");
		printf("2.Create and get ShortestPath\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
				printf("Enter no of nodes\n");
				scanf("%d",&k);
				gr=(graph*)createGraph(k);
				addVertices(gr,0,1,0,0);
				addVertices(gr,0,4,0,0);
				addVertices(gr,1,2,0,0);
				addVertices(gr,1,3,0,0);
				addVertices(gr,1,4,0,0);
				addVertices(gr,2,3,0,0);
				addVertices(gr,3,4,0,0);

				printGraph(gr);
				printf("\nBFS\n");
				graph_doBFS(gr,0);
				printf("\nDFS\n");
				graph_doDFS(gr,0);

				graph_IsBipartite(gr,0);

				break;
			case 2:
				gr=(graph*)createGraph(5);
				addVertices(gr,0,1,1,1.0);
				addVertices(gr,0,2,1,2.0);
				addVertices(gr,1,3,1,1.0);
				addVertices(gr,2,4,1,1.0);
				addVertices(gr,3,4,1,2.0);

				printGraph(gr);
			len=getShortestPath(gr,0,4);
				printf("Shortest path from 0 to 4 is:%f\n",len);
				break;


		}

	}


    return 0;
}
