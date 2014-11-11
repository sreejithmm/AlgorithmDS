#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph *
createGraph (int nodes)
{
	int i=0;
	graph* gr = (graph*)malloc(sizeof(graph));
	gr->num=nodes;
	gr->ArrList = (graphArrList*)malloc(nodes*sizeof(graphArrList));
	for(i=0;i<nodes;i++)
	{
		gr->ArrList[i].head=NULL;
	}	

}
