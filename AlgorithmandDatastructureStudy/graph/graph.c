#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph *
createGraph (int nodes)
{
  int i = 0;
  graph *gr = (graph *) malloc (sizeof (graph));
  gr->num = nodes;
  gr->ArrList = (graphArrList *) malloc (nodes * sizeof (graphArrList));
  for (i = 0; i < nodes; i++)
    {
      gr->ArrList[i].head = NULL;
    }
	return gr;
}

void
addVertices (graph * gr, int src, int dest)
{
  graphArrnode *node = NULL;

  if (gr == NULL)
    {
      return;
    }

  if (gr->num == 0)
    {
      return;
    }
  if (gr->ArrList == NULL)
    {
      gr->ArrList = (graphArrList *) malloc (gr->num * sizeof (graphArrList));
    }

  node = (graphArrnode *) malloc (sizeof (graphArrnode));
  node->dest = dest;
  node->next = gr->ArrList[src].head;
  gr->ArrList[src].head = node;

  node = (graphArrnode *) malloc (sizeof (graphArrnode));
  node->dest = src;
  node->next = gr->ArrList[dest].head;
  gr->ArrList[dest].head = node;



}

void
printGraph (graph * gr)
{
  int i;
  graphArrnode *temp;

  if (gr == NULL)
    {
      return;
    }
  if (gr->num == 0)
    {
      printf ("Nothing to print\n");
    }
  if (gr->ArrList == NULL)
    {
      printf ("ERR..No adjacency list found\n");
      return;
    }
  for (i = 0; i < gr->num; i++)
    {
      temp = gr->ArrList[i].head;
      printf ("\n");
      printf ("%d :", i);
      while (temp != NULL)
	{

	  printf ("%d ", temp->dest);
	  temp = temp->next;
	}
    }
  return;

}

myqueue* createQueue(int capa)
{
	myqueue* q = (myqueue*)malloc(sizeof(myqueue));
	int *arr = (int*)calloc(capa,sizeof(int));
	q->arr = arr;
	q->strtidx = 0;
	q->endidx= 0;
	q->cap = capa;
	q->size = 0;
	return q;

}

void enqueue(myqueue* q, int num)
{
	if(q==NULL)
		return;
	if(q->arr == NULL)
		return;

	if(q->size == q->cap)
	{
		printf("Queue full..return\n");
		return;
	}

	if(q->size == 0)
	{
		q->startidx=0;
		q->endidx = 0;
		q->size = 1;
	}

}

void graph_doBSF(graph* gr,int origin)
{
	int temp= 0;
	graphArrnode* node;
	myqueue* q;

	if(gr==NULL)
	{
		printf("Err!!Empty graph. \n");
		return;
	}
	if(gr->num == 0 || (origin >=gr->num))
	{
		printf("ERR!! no elements in graph\n");
		return;
	}

	q= createQueue(gr->num);
	int *arr=(int*)calloc(qr->num,sizeof(int));
	memset(arr,0,sizeof(int)*qr->num);
	enqueue(q,origin);
	arr[origin]=1;

	while(!isQueueEmpty())
	{
		temp = dequeue(q);
		printf("%d ",temp);
		node = gr->ArrList[temp].head;
		while(node!=NULL)
		{
			if(arr[node->dest] == 0)
				enqueue(q,node->dest);

		}

	}
	printf("\n");

	return;
	
}


