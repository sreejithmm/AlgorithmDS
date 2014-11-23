#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>
#include <string.h>

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
	q->front = 0;
	q->rear= capa-1;
	q->cap = capa;
	q->size = 0;
	return q;

}
int isQueueEmpty(myqueue* q)
{
	int t=0;
	if(q)
	{
		if(q->size == 0)
			t=1;
	}
	return t;
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
	q->rear = (q->rear+1)%(q->cap);
	q->arr[q->rear] = num;
	q->size+=1;
	return;

}

int dequeue(myqueue* q)
{
	int temp=INT_MIN;
	if(!isQueueEmpty(q))
	{
		temp = q->arr[q->front];
		q->front = (q->front+1)%(q->cap);
		q->size-=1;

	}
	return temp;

}

void graph_doBFS(graph* gr,int origin)
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
	int *arr=(int*)calloc(gr->num,sizeof(int));
	memset(arr,0,(sizeof(int)*gr->num));
	enqueue(q,origin);
	arr[origin]=1;

	while(!isQueueEmpty(q))
	{
		temp = dequeue(q);
		printf("%d ",temp);
		node = gr->ArrList[temp].head;
		while(node!=NULL)
		{
			if(arr[node->dest] == 0) {
				enqueue(q,node->dest);
				arr[node->dest] = 1;
			}
			node = node-> next;

		}

	}
	printf("\n");

	return;
	
}

void graph_IsBipartite(graph* gr,int origin)
{
	myqueue* q = NULL;
	int temp;
	graphArrnode *node;

	q= createQueue(gr->num);
	int *arr=(int*)calloc(gr->num,sizeof(int));
	memset(arr,0,(sizeof(int)*gr->num));
	enqueue(q,origin);
	arr[origin]=1;

	while(!isQueueEmpty(q))
	{
		temp = dequeue(q);
//		printf("%d ",temp);
		node = gr->ArrList[temp].head;
		while(node!=NULL)
		{
			if(arr[node->dest] == 0) {
				enqueue(q,node->dest);
				arr[node->dest] = arr[temp]+1;
			}
			else if(arr[node->dest] == arr[temp])
			{
				printf("Non bipartite\n");
				return;

			}
			node = node-> next;

		}

	}
	printf("Bipartite\n");




}

void doDFS(graph* gr, int vert, int arr[])
{
	graphArrnode* node;
	arr[vert] = 1;
	printf("%d ",vert);
	node = gr->ArrList[vert].head;
	while(node !=NULL)
	{
		if(arr[node->dest] ==0)
		{
			doDFS(gr,node->dest,arr);
		}
		node = node->next;
	}
        
}


void graph_doDFS(graph* gr, int origin)
{
   
	int *arr = (int*)calloc(gr->num,sizeof(int));
	bzero(arr,gr->num*sizeof(int));
	doDFS(gr,origin,arr);
	printf("\n");

}


int isLoopPresentUtil(graph* gr, int vert, int arr[],int level)
{
	graphArrnode* node;
	arr[vert] = level;
	node = gr->ArrList[vert].head;
	while(node !=NULL)
	{
		if(arr[node->dest] ==0)
		{
			isLoopPresentUtil(gr,node->dest,arr,level+1);
		}
		else if(arr[node->dest] != level-1)
		{
		    return 0;
		}

		node = node->next;
	}
	return 1;

}
int isLoopPresent(graph* gr,int origin)
{
	int level = 0;
	int *arr = (int*)calloc(gr->num,sizeof(int));
	bzero(arr,gr->num*sizeof(int));
	return(isLoopPresentUtil(gr,origin,arr,level));


}

int isDoubleEdgedGraph(graph* gr, int origin)
{
   
}
