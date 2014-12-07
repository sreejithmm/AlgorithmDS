#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#define DEBUG 


typedef struct graphArrnode{
	int dest;
	float len;
	float pathLen;
	struct graphArrnode* next;
}graphArrnode;

typedef struct graphArrList 
{
	graphArrnode * head;
}graphArrList;



typedef struct _graph{
	
	int num;
	graphArrList* ArrList;
	
}graph;

typedef struct {
	int *arr;
	int front;
	int rear;
	int cap;
	int size;
}myqueue;

typedef struct edge{

	int source;
	int dest;
	float length;
}edge_st;

typedef struct heap{

     edge_st* edge[100];
     int size;

}heap;



void calculateMoves(int LadderArr[],int SnakeArr[],int board[],int nL, int nS);

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




int main()
{

	int nT,nL,nS;
	int i,j=0,k;
	int *LadderArr;
	int *SnakeArr;
	int board[101]={1};
	scanf("%d",&nT);
	
	while(nT)
	{
		scanf("%d,%d",&nL,&nS);
		LadderArr=(int*)calloc(2*nL+2,sizeof(int));
		SnakeArr=(int*)calloc(nS,sizeof(int));
		for(i=0;i<nL;i++)
		{
			scanf("%d,%d",&LadderArr[j++],&LadderArr[j++]);
			board[LadderArr[--j]] = LadderArr[--j];
			j+=2;
		}
		j=0;
		for(i=0;i<nS;i++)
		{
			scanf("%d,%d",&SnakeArr[j],&k);
			board[SnakeArr[j]]=0;
			j++;
		}

#ifdef DEBUG
		for(i=0;i<2*nL;i++)
		{
			printf("LadderArr:%d->%d\n",i,LadderArr[i]);
		}
		for(i=0;i<nS;i++)
		{
			printf("SnakeArr:%d->%d\n",i,SnakeArr[i]);
		}
		for(i=1;i<101;i++)
		{
			

		}
#endif	

		calculateMoves(LadderArr,SnakeArr,board,nL,nS);
		nT--;
	}

	return 0;


}


int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}

void calculateMoves(int LadderArr[],int SnakeArr[],int board[],int nL, int nS)
{

		/*create a graph*/
		/*each vertex is from the LadderArr[], including a 1 and 100 */
		/*mark the board array with ladder elements */
		/* sort the ladder arra */
		/* when adding a vertex, add path to all elements greater than the vertex */
		/* keep moving till ladder Arr is finished */
		int i;
		LadderArr[2*nL]=1;
		LadderArr[2*nL+1]=100;
		nL=2*nL+2;

		qsort(LadderArr,nL,sizeof(int),cmpfunc);

		for(i=0;i<nL;i++)
		{
			printf("%d ",LadderArr[i]);
		}		




}
