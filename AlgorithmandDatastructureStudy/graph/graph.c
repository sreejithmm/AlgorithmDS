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

void addVertices(graph* gr, int src, int dest)
{
	graphArrnode* node=NULL;

	if(gr==NULL)
	{
		return;
	}

	if(gr->num == 0)
	{
		return;
	}
	if(gr->ArrList == NULL)
	{
		gr->ArrList = (graphArrList*)malloc(gr->num*sizeof(graphArrList));
	}

	node = (graphArrnode*)malloc(sizeof(graphArrnode));
	node->dest = dest;
	node->next = gr->ArrList[src].head;
	gr->ArrList[src].head= node;
	
   	node = (graphArrnode*)malloc(sizeof(graphArrnode));
	node->dest = src;
	node->next = gr->ArrList[dest].head;
	gr->ArrList[dest].head= node;
	


}
