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
addVertices (graph * gr, int src, int dest,int isDirected,float weight)
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
  node->len = weight;
  node->pathLen=0;
  node->next = gr->ArrList[src].head;
  gr->ArrList[src].head = node;

  if(!isDirected) 
  {
  	node = (graphArrnode *) malloc (sizeof (graphArrnode));
	node->dest = src;
        node->len = weight;
	node->pathLen=0;
        node->next = gr->ArrList[dest].head;
        gr->ArrList[dest].head = node;
  }


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

int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}
int isDoubleEdgedGraphUtil(graph* gr, int vert, int arr[],int time[],int arrtime)
{
	graphArrnode* node=NULL;
	int parentConn;

	arr[vert]=1;
	node = gr->ArrList[vert].head;

	time[vert]=arrtime;
	

	while(node!=NULL)
	{
		if(arr[node->dest]==0)
		{
			parentConn=min(parentConn,isDoubleEdgedGraphUtil(gr,node->dest,arr,time,arrtime+1));
			if(parentConn >= vert || parentConn == INT_MIN)
			{
				
				return INT_MIN;
			}
			
		}
		else
		{
			parentConn=min(time[vert],time[node->dest]);
		}
		node = node->next;
	}
	return parentConn;
}
int isDoubleEdgedGraph(graph* gr, int origin)
{
	int *arr=(int*)calloc(gr->num,sizeof(int));
	bzero(arr,gr->num* sizeof(int));
	int *time=(int*)calloc(gr->num,sizeof(int));
	bzero(time,gr->num*sizeof(int));
	isDoubleEdgedGraphUtil(gr,origin,arr,time,0);
   
}


int getParent(int index)
{

    return((index-1)/2);

}
int getleftChild(int index)
{
    return((2*index)+1);
}
int getRightChild(int index)
{
    return((2*index)+2);
}

int insertToHeap(heap* h,edge_st* ed,int* size)
{
    int location = *size;
    int parentnode=getParent(location);

    while(location >0)
    {
        if(h->edge[parentnode]->length < ed->length)
        {
    
            h->edge[location] = ed;
            *size = *size + 1;
            return 0;
        }
        h->edge[location]=h->edge[parentnode];
        location = parentnode;
        parentnode = getParent(location);
    }
    h->edge[0]=ed;
    *size = *size + 1;
    return 0;
}


int getMinValueIdx(heap* h,int lidx, int ridx)
{
    if(h->edge[lidx]->length > h->edge[ridx]->length)
    {
        return ridx;
    }
    return lidx;
}
void swapEdge(heap* h,int idx1, int idx2)
{
    edge_st* t;
    t = h->edge[idx1];
    h->edge[idx1] = h->edge[idx2];
    h->edge[idx2] = t;
    return ;
}

void heapify(heap* h,int index,int size)
{

    int lidx = getleftChild(index);
    int ridx = getRightChild(index);
    int smallestidx;

    while(lidx <size && ridx < size)
    {
        smallestidx = getMinValueIdx(h,lidx,ridx);
        if(h->edge[smallestidx]->length > h->edge[index]->length)
        {
            return ;
        }
        swapEdge(h,smallestidx,index);
        index = smallestidx;
        lidx = getleftChild(index);
        ridx = getRightChild(index);

    }

}
/*original code */


heap* createHeap(graph* gr, int origin,int* size_val)
{
	int i;
	heap* h = (heap*)malloc(sizeof(heap));
	int size=0;/*heap array size*/
	edge_st* temp;
        bzero(h,sizeof(heap));
		
	for(i=0;i<gr->num;i++)
	{
		temp = (edge_st*)malloc(sizeof(edge_st));
		temp->source = i;
		temp->length = (i==origin)?0:INT_MAX;
		insertToHeap(h,temp,&size);
	}
	*size_val = size;
	return h;
}

edge_st* getMinHeap(heap* h)
{
	if(h==NULL)
		return NULL;
	return h->edge[0];
}

void deleteMinHeap(heap* h)
{
	if(h==NULL)
		return;
	swapEdge(h,0,(h->size)-1);

	h->size = h->size -1;

	heapify(h,0,h->size);

	return;
}

void modifyHeap(heap* h, int ref, float newval)
{
	int i;
	int parent;
	int newval_t;
	for(i=0; i<h->size; i++)
	{
		if(h->edge[i]->source == ref)
		{
			if(h->edge[i]->length > newval)
			{

				h->edge[i]->length = newval;
			}
			else
			{
				/*Do nothing*/
				return;
			}
			break;
		}
	}
	parent = getParent(i);
	while(parent && (h->edge[i]->length < h->edge[parent]->length))
	{
		swapEdge(h,i,parent);
		i=parent;
		parent = getParent(i);

	}

}

float getShortestPathUtil(graph* gr, heap* h, float vert[],int destination)
{

	edge_st* temp_ed;
	int temp_id;
	int temp_dest;
	float temp_len;
	graphArrnode* head;

	while(h->size)
	{
		temp_ed = getMinHeap(h);
		temp_id = temp_ed->source;
		head = gr->ArrList[temp_id].head;
		while(head)
		{
			temp_dest = head->dest;
			temp_len = head->len+temp_ed->length;
			modifyHeap(h,temp_dest,temp_len);
			head = head->next;
		}
		vert[temp_id] = temp_ed->length;

		deleteMinHeap(h);
		if(temp_id == destination)
		{
			return vert[temp_id];
		}

	}
	return vert[destination];


}

float getShortestPath(graph* gr, int origin,int destination)
{
	float shPath=INT_MAX;
	int size;
	float *Vert = (float*)calloc(gr->num,sizeof(float));
        heap* h= createHeap(gr,origin,&size);
	printf("\ngetShortestPath: heap created with size=%d\n",size);
	h->size = size;

	shPath = getShortestPathUtil(gr,h,Vert,destination);
	return shPath;
	
}

